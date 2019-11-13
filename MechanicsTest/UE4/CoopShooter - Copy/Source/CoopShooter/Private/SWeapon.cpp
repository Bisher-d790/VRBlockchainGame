// Fill out your copyright notice in the Description page of Project Settings.

#include "SWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "TimerManager.h"
#include "CoopShooter.h"
#include "Net/UnrealNetwork.h"


// Sets default values
ASWeapon::ASWeapon()
{
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh Component"));
	RootComponent = MeshComp;

	MuzzleSocketName = "MuzzleSocket";
	TrailFX_SocketName = "Target";

	SetReplicates(true);

	NetUpdateFrequency = 66.0f;
	MinNetUpdateFrequency = 33.0f;
}

// Called when the game starts or when spawned
void ASWeapon::BeginPlay()
{
	Super::BeginPlay();

	TimeBetweenShots = 60 / RateOfFire;
	RoundBullets = RoundCapacity;
}

void ASWeapon::Fire()
{

	if (Role < ROLE_Authority) {
		Server_Fire();
	}

	// Trace the world from the eyes of the player to crosshair location
	AActor* Owner = GetOwner();

	if (Owner && !RoundEmpty) {
		FVector EyeLocation;
		FRotator EyeRotation;

		Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FVector ShotDirection = EyeRotation.Vector();

		FVector TraceEnd = EyeLocation + (ShotDirection * ShotRange);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(Owner);
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = true;
		QueryParams.bReturnPhysicalMaterial = true;

		EPhysicalSurface SurfaceType = SurfaceType_Default;
		FVector TrailFX_End = TraceEnd;
		FHitResult Hit;

		if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, CollisionChannel_ShotTrace, QueryParams)) {

			// Hit something logic
			AActor* HitActor = Hit.GetActor();

			SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());

			float ShotDamage = BaseDamage;

			if (SurfaceType == SurfaceType_FleshVulnerable)	ShotDamage *= VulnerableShotMultiplier;

			UGameplayStatics::ApplyPointDamage(Hit.GetActor(), ShotDamage, ShotDirection, Hit, Owner->GetInstigatorController(), this, DamageType);

			TrailFX_End = Hit.ImpactPoint;

			PlayImpactFX(SurfaceType, Hit.ImpactPoint);
		}

		PlayFireFX(TrailFX_End);

		if (Role == ROLE_Authority) {
			HitScanTrace.TraceTo = TrailFX_End;
			HitScanTrace.SurfaceType = SurfaceType;
		}

		LastFiredTime = GetWorld()->GetTimeSeconds();
		if ((--RoundBullets) == 0)	RoundEmpty = true;
	}
}

void ASWeapon::PlayImpactFX(EPhysicalSurface SurfaceType, FVector ImpactPoint)
{
	UParticleSystem* SelectedHitFX = DefaultHitFX;

	switch (SurfaceType)
	{
	case SurfaceType_FleshDefault:
	case SurfaceType_FleshVulnerable:
		SelectedHitFX = FleshHitFX;
		break;
	default:
		SelectedHitFX = DefaultHitFX;
		break;
	}

	if (SelectedHitFX) {
		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);

		FVector ShotDirection = ImpactPoint - MuzzleLocation;

		ShotDirection.Normalize();

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SelectedHitFX, ImpactPoint, ShotDirection.Rotation());
	}
}

void ASWeapon::Server_Fire_Implementation()
{
	Fire();
}

bool ASWeapon::Server_Fire_Validate() {
	return true;
}

void ASWeapon::OnRep_HitScanTrace()
{
	// Play cosmetic effects
	PlayFireFX(HitScanTrace.TraceTo);

	PlayImpactFX(HitScanTrace.SurfaceType, HitScanTrace.TraceTo);
}

void ASWeapon::StartFire()
{
	float FirstDelay = FMath::Max(LastFiredTime - GetWorld()->GetTimeSeconds() + TimeBetweenShots, 0.0f);
	GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, this, &ASWeapon::Fire, TimeBetweenShots, true, FirstDelay);
}

void ASWeapon::StopFire()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
}

void ASWeapon::StartReload()
{
	if (RoundBullets != RoundCapacity) {
		GetWorldTimerManager().SetTimer(TimeHandle_ReloadTimer, this, &ASWeapon::Reload, ReloadTime, false, ReloadTime);
	}
}

void ASWeapon::Reload()
{
	RoundBullets = RoundCapacity;
	RoundEmpty = false;
}

void ASWeapon::StopReload()
{
	GetWorldTimerManager().ClearTimer(TimeHandle_ReloadTimer);
}

void ASWeapon::PlayFireFX(FVector TrailFX_End)
{
	if (MuzzleFlashFX)	UGameplayStatics::SpawnEmitterAttached(MuzzleFlashFX, MeshComp, MuzzleSocketName);

	if (TrailFX) {
		UParticleSystemComponent* TrailComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TrailFX, MeshComp->GetSocketLocation(MuzzleSocketName));
		TrailComp->SetVectorParameter(TrailFX_SocketName, TrailFX_End);
	}

	APawn* Owner = Cast<APawn>(GetOwner());
	if (Owner) {
		APlayerController* PC = Cast<APlayerController>(Owner->GetController());
		if (PC) {
			PC->ClientPlayCameraShake(CameraShake);
		}
	}
}

void ASWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ASWeapon, HitScanTrace, COND_SkipOwner);
}

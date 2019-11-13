// Fill out your copyright notice in the Description page of Project Settings.

#include "STrackerBot.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "SCharacter.h"
#include "HealthComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"
#include "Sound/SoundCue.h"


// Sets default values
ASTrackerBot::ASTrackerBot()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set Basic Variables 
	ExplosionDamage = 40;
	MovementForce = 2000.f;
	bUseVelocityChange = true;
	DistanceToReachTarget = 100.f;
	TimeToUpdateLocation = 0.5f;
	TimeToDetonate = 2.f;
	DetonatingFlashes = 3;
	NeighborBotRadius = 500.f;
	MaxPowerLevel = 3;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	MeshComp->SetCanEverAffectNavigation(false);
	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetLinearDamping(2.f);
	RootComponent = MeshComp;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComp"));
	HealthComp->OnHealthChanged.AddDynamic(this, &ASTrackerBot::HandleTakeDamage);

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetSphereRadius(DistanceToReachTarget * 2);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASTrackerBot::BeginPlay()
{
	Super::BeginPlay();

	if (Role == ROLE_Authority) {
		// Set the first path for AI movement
		NextPathPoint = GetNextPathPoint();

		// Start updating search for nearby bots
		FTimerHandle TimerHandle_CheckNearbyBots;
		GetWorldTimerManager().SetTimer(TimerHandle_CheckNearbyBots, this, &ASTrackerBot::CheckNearbyBots, TimeToUpdateLocation, true, 0.0f);
	}
}

// Called every frame
void ASTrackerBot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Role == ROLE_Authority) {
		AIMoveToTarget();
	}
}

void ASTrackerBot::AIMoveToTarget()
{
	float DistanceToTarget = FVector::Distance(GetActorLocation(), NextPathPoint);
	float TimeSinceLastTargetUpdate = UGameplayStatics::GetTimeSeconds(GetWorld()) - TargetLastUpdateTime;

	if (DistanceToTarget <= DistanceToReachTarget || TimeSinceLastTargetUpdate > TimeToUpdateLocation) {
		NextPathPoint = GetNextPathPoint();
	}
	else {
		FVector TargetDirection = NextPathPoint - GetActorLocation();
		TargetDirection.Normalize();

		TargetDirection *= MovementForce;

		MeshComp->AddForce(TargetDirection, NAME_None, bUseVelocityChange);
	}
}

FVector ASTrackerBot::GetNextPathPoint()
{
	// Temporary, gets the target player 
	ACharacter* TargetPlayerCharacter = nullptr;
	for (int i = 0; TargetPlayerCharacter == nullptr && i<100; i++) {
		TargetPlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, i);
	}

	UNavigationPath* NavPath = UNavigationSystemV1::FindPathToActorSynchronously(this, GetActorLocation(), TargetPlayerCharacter);

	TargetLastUpdateTime = UGameplayStatics::GetTimeSeconds(GetWorld());

	if (NavPath && NavPath->PathPoints.Num() > 1) {
		// Return next target point
		return NavPath->PathPoints[1];
	}

	// if failed to find path
	return GetActorLocation();
}

void ASTrackerBot::HandleTakeDamage(UHealthComponent* LocalHealthComponent, float Health, float HealthDelta, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	// @TODO: Pulse the material
	if (!MatInst)
	{
		MatInst = MeshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MeshComp->GetMaterial(0));
	}

	if (MatInst) {
		MatInst->SetScalarParameterValue("LastTimeDamaged", GetWorld()->TimeSeconds);
	}


	//Explode on hitpoints == 0
	if (Health <= 0.0f) {
		SelfDistruct();
	}
}

void ASTrackerBot::SelfDistruct()
{
	if (bExploded)	return;

	bExploded = true;

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionFX, GetActorLocation());

	MeshComp->SetVisibility(false, true);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	if (Role == ROLE_Authority) {
		TArray<AActor*> IgnoredActors;
		IgnoredActors.Add(this);

		float MultipliedExplosionDamage = ExplosionDamage + (ExplosionDamage * PowerLevel);

		// Apply Damage!
		UGameplayStatics::ApplyRadialDamage(this, MultipliedExplosionDamage, GetActorLocation(), DistanceToReachTarget * 2, nullptr, IgnoredActors, this, GetInstigatorController(), true);

		// Explosion Sound FX play
		UGameplayStatics::PlaySoundAtLocation(this, ExplosionSound, GetActorLocation());

		// Delete Actor then
		SetLifeSpan(2.0f);
	}
}

void ASTrackerBot::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (!bStartedDetonating) {
		ASCharacter* PlayerOverlapped = Cast<ASCharacter>(OtherActor);
		if (PlayerOverlapped) {

			if (Role == ROLE_Authority) {
				// Start Detonating
				float DetonateInterval = TimeToDetonate / (DetonatingFlashes + 1);

				GetWorldTimerManager().SetTimer(TimerHandle_SelfDamage, this, &ASTrackerBot::SelfDistruct_TargetReached, DetonateInterval, true, 0.0f);
			}

			bStartedDetonating = true;

			// Detonate Sound FX spawn
			UGameplayStatics::SpawnSoundAttached(DetonateSound, RootComponent);
		}
	}
}

// Applies 20 damage points to this actor till detonate ** Determines number of flashes before detonate
void ASTrackerBot::SelfDistruct_TargetReached()
{
	float SelfDamageAmount = 100 / (DetonatingFlashes + 1);
	UGameplayStatics::ApplyDamage(this, SelfDamageAmount, GetInstigatorController(), this, nullptr);
}

void ASTrackerBot::CheckNearbyBots() {
	// Collision Shape, 
	FCollisionShape CollisionShape;
	CollisionShape.SetSphere(NeighborBotRadius);

	// Collision Query params
	FCollisionObjectQueryParams QueryParams;
	QueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	// Get overlapping actors in the radius of NeighborBotRadius 
	TArray<FOverlapResult> Overlaps;
	GetWorld()->OverlapMultiByObjectType(Overlaps, GetActorLocation(), FQuat::Identity, QueryParams, CollisionShape);

	int NOfNeighbors = 0;
	for (FOverlapResult Result : Overlaps)
	{	// Check if is tracker bot and not this actor
		ASTrackerBot* Bot = Cast<ASTrackerBot>(Result.GetActor());

		if (Bot && Bot != this) {
			NOfNeighbors++;
		}
	}

	// Clamp PowerLevel between 0 and maxPowerLevel
	PowerLevel = FMath::Clamp(NOfNeighbors, 0, MaxPowerLevel);

	// Set Material constant according to number of neighbors
	if (!MatInst) {
		MatInst = MeshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MeshComp->GetMaterial(0));
	}

	if (MatInst) {
		// Use an alpha as a float between 0 and 1 to to set the material flashing, 
		// reflect powerLevel
		float Alpha = PowerLevel / (float)MaxPowerLevel;

		MatInst->SetScalarParameterValue("PowerLevelAlpha", Alpha);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "ExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "HealthComponent.h"
#include "Materials/MaterialInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Net/UnrealNetwork.h"


// Sets default values
AExplosiveBarrel::AExplosiveBarrel()
{
	ExplosionImpulse = 20000.f;
	ExplosionFXScale = 5.f;
	ExplosionDamage = 40.f;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetCollisionObjectType(ECC_PhysicsBody);
	RootComponent = MeshComp;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	HealthComp->OnHealthChanged.AddDynamic(this, &AExplosiveBarrel::OnHealthChanged);

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("Radial Force Component"));
	RadialForceComp->Radius = 700;
	RadialForceComp->ImpulseStrength = 1000.f;
	RadialForceComp->bImpulseVelChange = true;
	RadialForceComp->bIgnoreOwningActor = true;
	RadialForceComp->bAutoActivate = false;
	RadialForceComp->SetupAttachment(MeshComp);

	SetReplicates(true);
	SetReplicateMovement(true);
}

// Called when the game starts or when spawned
void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
}

void AExplosiveBarrel::OnHealthChanged(UHealthComponent* HealthComponent, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (HasExploded)	return;

	if (Health <= 0) {
		RadialForceComp->FireImpulse();

		OnRep_Explosion(); // Explode FX and replicated function

		MeshComp->AddImpulse(MeshComp->GetUpVector() * ExplosionImpulse, TEXT("NONE"), false);
		UGameplayStatics::ApplyRadialDamage(GetWorld(), ExplosionDamage, GetActorLocation(), RadialForceComp->Radius, ExplosionDamageType, TArray<AActor*>(), this);

		HasExploded = true;
	}
}

void AExplosiveBarrel::OnRep_Explosion()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionFX, GetActorLocation(), FRotator::ZeroRotator, FVector::OneVector * ExplosionFXScale);
	UGameplayStatics::SpawnEmitterAttached(BurningFX, RootComponent);
	if (ExplosionSound) {
		// Explosion Sound FX play
		UGameplayStatics::PlaySoundAtLocation(this, ExplosionSound, GetActorLocation());
	}
	MeshComp->SetMaterial(0, ExplodedMaterial);
}

void AExplosiveBarrel::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AExplosiveBarrel, HasExploded);
}



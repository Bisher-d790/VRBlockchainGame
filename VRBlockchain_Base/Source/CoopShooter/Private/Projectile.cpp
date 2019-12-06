// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
	InitVelocity = 2000.f;
	ExplosionDamage = 100.f;
	ExplosionDelay = 1.f;
	ExplosionRadius = 20.f;
	NumberOfBounces = 1;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComp->SetSphereRadius(200.f);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Block);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereComp->SetCollisionObjectType(ECC_PhysicsBody);
	SphereComp->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);	// set up a notification for when this component hits something blocking
	RootComponent = SphereComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	MeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement Component"));
	MovementComp->InitialSpeed = InitVelocity;
	MovementComp->bShouldBounce = true;

}


void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (NumberOfBounces == 0)	
		Explode();
	else NumberOfBounces--;
}


void AProjectile::ExplodeAfter()
{
	FTimerHandle ExplosionTimerHandle;
	GetWorldTimerManager().SetTimer(ExplosionTimerHandle, this, &AProjectile::Explode, ExplosionDelay);
}


void AProjectile::Explode()
{
	if (Owner) {
		UGameplayStatics::ApplyRadialDamage(GetWorld(), ExplosionDamage, GetActorLocation(), ExplosionRadius, DamageType, TArray<AActor*>(), this, Owner->GetInstigatorController());
		if (HitFX) UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitFX, GetActorLocation());
	}

	Destroy();
}

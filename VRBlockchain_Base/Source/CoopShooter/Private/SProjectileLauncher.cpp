// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileLauncher.h"
#include "Engine/World.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.h"


void ASProjectileLauncher::Fire() {
	AActor* Owner = GetOwner();

	if (Owner && Projectile && !RoundEmpty) {

		FVector EyeLocation;
		FRotator EyeRotation;
		Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FActorSpawnParameters ProjectileSpawnParams;
		ProjectileSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(Projectile,MeshComp->GetSocketLocation(MuzzleSocketName), EyeRotation, ProjectileSpawnParams);

		// Setup projectile defaults
		projectile->DamageType = DamageType;
		projectile->HitFX = DefaultHitFX;
		projectile->TrailFX = TrailFX;
		projectile->Owner = this;
		projectile->InitVelocity = ShotRange;
		projectile->ExplosionDamage = BaseDamage;
		projectile->ExplodeAfter();

		if (MuzzleFlashFX)	UGameplayStatics::SpawnEmitterAttached(MuzzleFlashFX, MeshComp, MuzzleSocketName);
		
		if ((--RoundBullets) == 0)	RoundEmpty = true;
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class COOPSHOOTER_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

	/* Assigned by firing weapon*/
	TSubclassOf<UDamageType> DamageType;
	UParticleSystem* HitFX;
	UParticleSystem* TrailFX;
	AActor* Owner;
	float InitVelocity = 2000.f; // assigned by ShotRange
	float ExplosionDamage = 100.f; // assigned by ShotDamage
	/**/

	void ExplodeAfter();

	UFUNCTION(BlueprintCallable, Category = "Explosion")
		void Explode();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere, Category = "Components")
		UProjectileMovementComponent* MovementComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Explosion")
		float ExplosionDelay = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Explosion")
		float ExplosionRadius = 20.f;

	UPROPERTY(EditAnywhere, Category = "Explosion")
		int NumberOfBounces = 1;

private:
	/** called when projectile hits something */
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExplosiveBarrel.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;
class UHealthComponent;
class UMaterialInterface;
class UParticleSystem;
class USoundCue;

UCLASS()
class COOPSHOOTER_API AExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplosiveBarrel();

	UPROPERTY(ReplicatedUsing = OnRep_Explosion)
	bool HasExploded;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "ExplosiveBarrel")
		UStaticMeshComponent*	MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "ExplosiveBarrel")
		URadialForceComponent* RadialForceComp;

	UPROPERTY(VisibleAnywhere, Category = "ExplosiveBarrel")
		UHealthComponent* HealthComp;

	UFUNCTION()
		void OnHealthChanged(UHealthComponent* HealthComponent, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UPROPERTY(EditDefaultsOnly, Category = "ExplosionFX")
		 UMaterialInterface* ExplodedMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "ExplosionFX")
		UParticleSystem* ExplosionFX;

	UPROPERTY(EditDefaultsOnly, Category = "ExplosionFX")
		float ExplosionFXScale;

	UPROPERTY(EditDefaultsOnly, Category = "ExplosionFX")
		UParticleSystem* BurningFX;

	UPROPERTY(EditDefaultsOnly, Category = "ExplosionFX")
		float ExplosionImpulse;

	UPROPERTY(EditDefaultsOnly, Category = "ExplosionFX")
		float ExplosionDamage;

	UPROPERTY(EditDefaultsOnly, Category = "ExplosionFX")
		USoundCue* ExplosionSound;
	
	TSubclassOf<UDamageType> ExplosionDamageType;

	UFUNCTION()
	void OnRep_Explosion();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "STrackerBot.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UHealthComponent;
class USoundCue;

UCLASS()
class COOPSHOOTER_API ASTrackerBot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASTrackerBot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		UStaticMeshComponent* MeshComp;

	// Hit Properties
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		UHealthComponent* HealthComp;

	UFUNCTION()
		void HandleTakeDamage(UHealthComponent* LocalHealthComponent, float Health, float HealthDelta, const class UDamageType* DamageType,
			class AController* InstigatedBy, AActor* DamageCauser);

	// Material instance when actor hit
	UMaterialInstanceDynamic* MatInst;

	// Detonate Properties
	void SelfDistruct();

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		USphereComponent* SphereComp;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	FTimerHandle TimerHandle_SelfDamage;

	void SelfDistruct_TargetReached();

	void CheckNearbyBots();

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float TimeToDetonate;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		int DetonatingFlashes;

	bool bStartedDetonating;

	// Explosion Parameters
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		UParticleSystem* ExplosionFX;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float ExplosionDamage;

	bool bExploded;

	// AI Movement
	void AIMoveToTarget();

	FVector GetNextPathPoint();

	FVector NextPathPoint;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float MovementForce;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		bool bUseVelocityChange;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float DistanceToReachTarget;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float TimeToUpdateLocation;

	float TargetLastUpdateTime;

	// Neighboring Bots
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		float NeighborBotRadius;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		int MaxPowerLevel;

	int PowerLevel;

	// Sounds
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		USoundCue* DetonateSound;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
		USoundCue* ExplosionSound;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

class USkeletalMeshComponent;
class UDamageType;
class UParticleSystem;

// Contains info about the shot linetrace
USTRUCT() struct FHitScanTrace 
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		TEnumAsByte<EPhysicalSurface> SurfaceType;

	UPROPERTY()
		FVector_NetQuantize TraceTo;
};

UCLASS()
class COOPSHOOTER_API ASWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USkeletalMeshComponent* MeshComp;

	void PlayFireFX(FVector TrailFX_End);
	
	void PlayImpactFX(EPhysicalSurface SurfaceType, FVector Hit);

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float ShotRange = 10000.f;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float BaseDamage = 20.f;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float VulnerableShotMultiplier = 4.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
		TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		UParticleSystem* MuzzleFlashFX;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		UParticleSystem* DefaultHitFX;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		UParticleSystem* FleshHitFX;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		UParticleSystem* TrailFX;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<UCameraShake> CameraShake;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		FName MuzzleSocketName;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		FName TrailFX_SocketName;

	UFUNCTION(Category = "Weapon")
		virtual void Fire();

	UFUNCTION(Server, Reliable, WithValidation)
		void Server_Fire();

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		int RoundCapacity = 60;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		float ReloadTime = 3.f;

	bool RoundEmpty = false;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
		int RoundBullets;

	FTimerHandle TimeHandle_ReloadTimer;

	FTimerHandle TimerHandle_TimeBetweenShots;

	// RPM - Bullets per minutes
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		float RateOfFire = 600.f;

	float LastFiredTime;

	// Derived from RateOfFire
	float TimeBetweenShots;

	UPROPERTY(ReplicatedUsing = OnRep_HitScanTrace)
		FHitScanTrace HitScanTrace;

	UFUNCTION()
	void OnRep_HitScanTrace();

public:
	void StartFire();

	void StopFire();

	void StartReload();

	void Reload();

	void StopReload();

};

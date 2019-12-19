// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

class USkeletalMeshComponent;
class UDamageType;
class UParticleSystem;
class UCameraShake;
class UImage;
class USoundCue;

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

	void Server_Fire_Implementation(FVector ShotTarget);

	bool Server_Fire_Validate(FVector ShotTarget);

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float ShotRange;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float VulnerableShotMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
		TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float BaseDamage;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		int Level;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		FString Name;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		int ID;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		UParticleSystem* MuzzleFlashFX;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		UParticleSystem* DefaultHitFX;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		UParticleSystem* FleshHitFX;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		UParticleSystem* TrailFX;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		USoundCue* FireSound;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<UCameraShake> CameraShake;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		FName MuzzleSocketName;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		FName TrailFX_SocketName;

	UFUNCTION(Category = "Weapon")
		virtual void Fire();

	UFUNCTION(Server, Reliable, WithValidation)
		void Server_Fire(FVector ShotTarget);

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		int RoundCapacity;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		float ReloadTime;

	bool RoundEmpty;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
		int RoundBullets;

	FTimerHandle TimeHandle_ReloadTimer;

	FTimerHandle TimerHandle_TimeBetweenShots;

	// RPM - Bullets per minutes
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		float RateOfFire;

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

	FVector2D CrosshairPosition;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetCrosshairPosition(FVector2D NewPosition) { CrosshairPosition = NewPosition; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		inline float GetRoundBullets() { return RoundBullets; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		inline float GetBaseDamage() { return BaseDamage; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		inline int GetLevel() { return Level; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		inline  FString GetName() { return Name; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		inline int GetID() { return ID; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetBaseDamage(float Damage) { BaseDamage = Damage; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetLevel(int NewLevel) { Level = NewLevel; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetName(FString NewName) { Name = NewName; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetID(int NewID) { ID = NewID; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void UpgradeWeapon();
};

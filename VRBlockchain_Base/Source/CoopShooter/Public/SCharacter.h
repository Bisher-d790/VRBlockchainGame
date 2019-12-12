// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ASWeapon;
class UHealthComponent;
class APlayerController;

UCLASS()
class COOPSHOOTER_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void BeginCrouch();

	void EndCrouch();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		inline ASWeapon* GetCurrentWeapon() { return CurrentWeapon; };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void  SetWeapon(ASWeapon* WeaponInstance);

	UPROPERTY(Replicated)
		ASWeapon* CurrentWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<ASWeapon> StarterWeapon;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		FName WeaponSocketName;

	UPROPERTY(VisibleDefaultsOnly, Category = "Player")
		FName CameraSocketName;

	void StartFire();

	void StopFire();

	void StartReload();

	void StopReload();

	bool bWantsToZoom = false;

	// assigned from the camera component
	float DefaultFOV;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		float ZoomFOV;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon", meta = (ClampMin = 0.1, ClampMax = 100))
		float ZoomSpeed;

	void BeginZoom();

	void EndZoom();

	virtual FVector GetPawnViewLocation() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
		UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
		USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
		UHealthComponent* HealthComp;

	UFUNCTION()
		void OnHealthChanged(UHealthComponent* LocalHealthComponent, float Health, float HealthDelta, const class UDamageType* DamageType,
			class AController* InstigatedBy, AActor* DamageCauser);

	UPROPERTY(EditDefaultsOnly, Category = "Player")
		float TimeToDestroyAfterDeath;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SmoothZoomFOV(float DeltaTime);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
		bool bIsDead;

	UFUNCTION(BlueprintCallable, Category = "Player")
		inline bool GetIsDead() { return bIsDead; };

	UFUNCTION(BlueprintImplementableEvent, Category = "Player")
		void OnRestarted(APlayerController* PlayerController);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player")
		void OnKilled();
};
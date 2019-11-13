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

	UPROPERTY(Replicated)
	ASWeapon* CurrentWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
		TSubclassOf<ASWeapon> StarterWeapon;

	UPROPERTY(VisibleDefaultsOnly, Category = "Player")
		FName WeaponSocketName;

	void StartFire();

	void StopFire();

	void StartReload();

	void StopReload();

	bool bWantsToZoom = false;

	// assigned from the camera component
	float DefaultFOV;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
		float ZoomFOV;

	UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.1, ClampMax = 100))
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
		float TimeToDestroyAfterDeath = 10.f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SmoothZoomFOV(float DeltaTime);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
		bool bIsDead;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Player")
		void OnRestarted(APlayerController* PlayerController);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player")
		void OnKilled();
};
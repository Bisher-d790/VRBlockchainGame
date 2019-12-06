// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPowerUp.generated.h"

UCLASS()
class COOPSHOOTER_API ASPowerUp : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASPowerUp();

protected:
	// Number of ticks the PowerUp should process 
	UPROPERTY(EditDefaultsOnly, Category = "Powerup")
		int32 NOfTicks;

	// Number of already processed ticks
	int32 ProcessedTicks;

	FTimerHandle TimerHandle_PowerUpTick;

	// Time between each two ticks
	UPROPERTY(EditDefaultsOnly, Category = "Powerup")
		float TimerInterval;

	// Function that calls PowerUp functionality each tick
	UFUNCTION()
		void OnTickPowerup();

	UPROPERTY(ReplicatedUsing = OnRep_PowerUpActive)
		bool bPowerUpIsActivated;

	UFUNCTION()
		void OnRep_PowerUpActive();

	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUp")
		void OnPowerUpStateChange(bool bNewActiveState);

public:
	// Function to Activate the PowerUp (When Picked Up)
	UFUNCTION()
		void ActivatePowerUp(AActor* ForActor);

	// Event called when PowerUp is Activated (Or Picked Up)
	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUp")
		void OnActivated(AActor* ForActor);

	// Event called when PowerUp is Expired
	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUp")
		void OnExpired();

	// Event called on each tick
	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUp")
		void OnPowerUpTicked();

};

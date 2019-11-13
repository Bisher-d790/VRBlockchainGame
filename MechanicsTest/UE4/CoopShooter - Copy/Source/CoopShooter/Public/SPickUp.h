// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPickUp.generated.h"

class USphereComponent;
class UDecalComponent;
class ASPowerUp;

UCLASS()
class COOPSHOOTER_API ASPickUp : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASPickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Pickup Collision Components 
	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* SphereComp;

	// Pickup Visual floor marker Component
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UDecalComponent* DecalComp;

	// PowerUp base class
	UPROPERTY(EditInstanceOnly, Category = "PickUp")
		TSubclassOf<ASPowerUp> PowerUpClass;

	ASPowerUp* PowerUpInstance;

	// Timer Duration to reset the PowerUp after being picked up
	UPROPERTY(EditInstanceOnly, Category = "PickUp")
		float CoolDownDuration;

	FTimerHandle TimerHandle_RespawnTimer;

	// Restore the powerup
	void Respawn();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};

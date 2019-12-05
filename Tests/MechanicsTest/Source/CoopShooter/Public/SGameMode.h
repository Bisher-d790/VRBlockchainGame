// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"


enum class ERoundState : uint8;

// Delegate when an actor is killed
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, VictimActor, AActor*, KillerActor, AController*, KillerController); // Killed Actor, Killer Actor, InstigatorController

/**
 *
 */
UCLASS()
class COOPSHOOTER_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	// Function to check the status of other players
	void CheckAnyPlayerAlive();

	// Function when the game is finished
	void Gameover();

	// Sets the games state
	void SetGameState(ERoundState NewRoundState);

	// Restarts dead players
	void RestartDeadPlayers();

public:
	// Constructor
	ASGameMode();

	// When the game starts
	virtual void StartPlay() override;

	// Ticks every second
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(BlueprintAssignable, Category = "Gamemode")
		FOnActorKilled OnActorKilled;
};

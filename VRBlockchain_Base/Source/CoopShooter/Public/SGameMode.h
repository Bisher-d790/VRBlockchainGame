// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"


enum class EGameState : uint8;

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
	// Timer between spawns within a wave
	FTimerHandle TimerHandle_SpawningBots;

	// Time between spawns within a wave
	UPROPERTY(EditDefaultsOnly, Category = "Gamemode")
		float TimeBetweenSpawns;

	// Timer Between waves
	FTimerHandle TimerHandle_BetweenWaves;

	// Time Between Waves
	UPROPERTY(EditDefaultsOnly, Category = "Gamemode")
		float TimeBetweenWaves;

	// Number of bots to spawn in a wave
	UPROPERTY(EditDefaultsOnly, Category = "Gamemode")
		int32 NOfBotsInWave;

	// Waves counter
	int32 WaveCount;

protected:
	// a blueprint event to spawn a bot
	UFUNCTION(BlueprintImplementableEvent, Category = "Gamemode")
		void SpawnBot();

	// Function that calls SpawnBot(), for StartWave() to call at each timer iteration
	void SpawnBot_Handler();

	// function to call when a wave starts
	void StartWave();

	// Function to call when the wave is ending
	void EndWave();

	// Function between waves to call next wave
	void PrepareNextWave();

	// Function to check the status of the wave, called every tick
	void CheckWaveStatus();

	// Function to check the status of other players
	void CheckAnyPlayerAlive();

	// Function when the game is finished
	void Gameover();

	// Sets the games state
	void SetGameState(EGameState NewWaveState);

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

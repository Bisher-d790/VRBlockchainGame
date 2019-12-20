// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SGameState.generated.h"


UENUM(BlueprintType)
enum class EGameState : uint8
{
	WaitingToStart,

	WaveInProgress,

	// All bots spawned, but they are not dead yet
	WaitingToComplete,

	WaveCompleted,

	GameOver,
};

/**
 * 
 */
UCLASS()
class COOPSHOOTER_API ASGameState : public AGameStateBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_WaveState(EGameState OldState);

	UFUNCTION(BlueprintImplementableEvent, Category = "GameState")
		void OnWaveStateChanged(EGameState OldState, EGameState NewState);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_WaveState, Category = "GameState")
	EGameState WaveState;

public:
	void SetWaveState(EGameState NewState);
};

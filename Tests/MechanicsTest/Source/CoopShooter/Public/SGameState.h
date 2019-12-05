// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SGameState.generated.h"


UENUM(BlueprintType)
enum class ERoundState : uint8
{
	WaitingToStart,

	RoundInProgress,

	WaitingToComplete,

	RoundCompleted,

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
	void OnRep_RoundState(ERoundState OldState);

	UFUNCTION(BlueprintImplementableEvent, Category = "GameState")
		void OnRoundStateChanged(ERoundState OldState, ERoundState NewState);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_RoundState, Category = "GameState")
	ERoundState RoundState;

public:
	void SetRoundState(ERoundState NewState);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameMode.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "HealthComponent.h"
#include "SGameState.h"
#include "SPlayerState.h"
#include "SCharacter.h"


ASGameMode::ASGameMode()
{
	// Tick Basics
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.0f;

	GameStateClass = ASGameState::StaticClass();
	PlayerStateClass = ASPlayerState::StaticClass();
}

void ASGameMode::StartPlay()
{
	Super::StartPlay();
}


void ASGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CheckAnyPlayerAlive();
}

void ASGameMode::CheckAnyPlayerAlive()
{
	// Check is any player is alive
	for (FConstPlayerControllerIterator PCIt = GetWorld()->GetPlayerControllerIterator(); PCIt; ++PCIt) {
		APlayerController* PC = PCIt->Get();

		if (PC && PC->GetPawn()) {
			APawn* PawnToCheck = PC->GetPawn();

			UHealthComponent* HealthToCheck = Cast<UHealthComponent>(PawnToCheck->GetComponentByClass(UHealthComponent::StaticClass()));
			if (ensure(HealthToCheck) && HealthToCheck->GetHealth() > 0.0f) {
				// There's a player alive
				return;
			}
		}
	}

	// No player is alive
	Gameover();
}


void ASGameMode::Gameover()
{
	// TODO: Finish Gameover logic


	UE_LOG(LogTemp, Log, TEXT("Game Over!"));

	SetGameState(ERoundState::GameOver);
}

void ASGameMode::SetGameState(ERoundState NewRoundState)
{
	ASGameState* GS = GetGameState<ASGameState>();
	if (ensureAlways(GS)) {
		GS->SetRoundState(NewRoundState);
	}
}

void ASGameMode::RestartDeadPlayers()
{
	// Check is any player is alive
	for (FConstPlayerControllerIterator PCIt = GetWorld()->GetPlayerControllerIterator(); PCIt; ++PCIt) {
		APlayerController* PC = PCIt->Get();

		if (PC && PC->GetPawn() == nullptr) {
			FTimerHandle TimerHandle_RestartPlayer;
			RestartPlayer(PC);
			Cast<ASCharacter>(PC->GetPawn())->OnRestarted(PC);
		}
	}
}

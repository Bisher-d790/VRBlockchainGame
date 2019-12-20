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
	// Set Basic values
	TimeBetweenSpawns = 1.0f;
	TimeBetweenWaves = 5.0f;
	NOfBotsInWave = 2;
	WaveCount = 0;

	// Tick Basics
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.0f;

	GameStateClass = ASGameState::StaticClass();
	PlayerStateClass = ASPlayerState::StaticClass();
}

void ASGameMode::StartPlay()
{
	Super::StartPlay();

	PrepareNextWave();
}


void ASGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CheckWaveStatus();
	CheckAnyPlayerAlive();
}

void ASGameMode::PrepareNextWave()
{
	GetWorldTimerManager().SetTimer(TimerHandle_BetweenWaves, this, &ASGameMode::StartWave, TimeBetweenWaves, false, 0.0f);

	RestartDeadPlayers();

	SetGameState(EGameState::WaitingToStart);
}

void ASGameMode::CheckWaveStatus()
{
	// If wave not finished or already preparing next wave
	bool bIsPreparingNextWave = GetWorldTimerManager().IsTimerActive(TimerHandle_BetweenWaves);

	if (NOfBotsInWave > 0 || bIsPreparingNextWave) {
		return;
	}

	bool bIsAnyBotsAlive = false;

	for (FConstPawnIterator PawnIt = GetWorld()->GetPawnIterator(); PawnIt; ++PawnIt) {
		APawn* PawnToCheck = PawnIt->Get();
		if (!PawnToCheck || PawnToCheck->IsPlayerControlled()) {
			continue;
		}

		UHealthComponent* HealthToCheck = Cast<UHealthComponent>(PawnToCheck->GetComponentByClass(UHealthComponent::StaticClass()));
		if (HealthToCheck && HealthToCheck->GetHealth() > 0.0f) {
			bIsAnyBotsAlive = true;

			break;
		}
	}

	if (!bIsAnyBotsAlive) {
		SetGameState(EGameState::WaveCompleted);

		PrepareNextWave();
	}

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

void ASGameMode::StartWave()
{
	WaveCount++;

	NOfBotsInWave = 2 * WaveCount;

	GetWorldTimerManager().SetTimer(TimerHandle_SpawningBots, this, &ASGameMode::SpawnBot_Handler, TimeBetweenSpawns, true, 0.0f);

	SetGameState(EGameState::WaveInProgress);
}

void ASGameMode::SpawnBot_Handler()
{
	SpawnBot();

	// Check if all bots are spawned, End Wave
	NOfBotsInWave--;
	if (NOfBotsInWave <= 0) {
		EndWave();
	}
}

void ASGameMode::EndWave()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_SpawningBots);

	SetGameState(EGameState::WaitingToComplete);
}

void ASGameMode::Gameover()
{
	EndWave();

	// TODO: Finish Gameover logic


	UE_LOG(LogTemp, Log, TEXT("Game Over!"));

	SetGameState(EGameState::GameOver);
}

void ASGameMode::SetGameState(EGameState NewWaveState)
{
	ASGameState* GS = GetGameState<ASGameState>();
	if (ensureAlways(GS)) {
		GS->SetWaveState(NewWaveState);
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

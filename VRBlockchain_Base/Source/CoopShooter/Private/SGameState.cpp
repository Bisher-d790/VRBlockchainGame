// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameState.h"
#include "Net/UnrealNetwork.h"


void ASGameState::OnRep_WaveState(EWaveState OldState) {
	OnWaveStateChanged(OldState, WaveState);
}

void ASGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASGameState, WaveState);
}

void ASGameState::SetWaveState(EWaveState NewState)
{
	if (Role == ROLE_Authority) {
		EWaveState OldState = WaveState;

		WaveState = NewState;

		// Call event when on server
		OnRep_WaveState(OldState);
	}
}

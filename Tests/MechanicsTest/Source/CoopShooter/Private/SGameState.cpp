// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameState.h"
#include "Net/UnrealNetwork.h"


void ASGameState::OnRep_RoundState(ERoundState OldState) {
	OnRoundStateChanged(OldState, RoundState);
}

void ASGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASGameState, RoundState);
}

void ASGameState::SetRoundState(ERoundState NewState)
{
	if (Role == ROLE_Authority) {
		ERoundState OldState = RoundState;

		RoundState = NewState;

		// Call event when on server
		OnRep_RoundState(OldState);
	}
}

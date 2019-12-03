// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FYP_VRBlockchainGameMode.h"
#include "FYP_VRBlockchainHUD.h"
#include "FYP_VRBlockchainCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFYP_VRBlockchainGameMode::AFYP_VRBlockchainGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFYP_VRBlockchainHUD::StaticClass();
}

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VRTestGameMode.h"
#include "VRTestHUD.h"
#include "VRTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AVRTestGameMode::AVRTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AVRTestHUD::StaticClass();
}

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HandTrackingTestGameMode.h"
#include "HandTrackingTestHUD.h"
#include "HandTrackingTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHandTrackingTestGameMode::AHandTrackingTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHandTrackingTestHUD::StaticClass();
}

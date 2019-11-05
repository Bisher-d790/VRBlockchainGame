// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HandTrackingGameMode.h"
#include "HandTrackingHUD.h"
#include "HandTrackingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHandTrackingGameMode::AHandTrackingGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHandTrackingHUD::StaticClass();
}

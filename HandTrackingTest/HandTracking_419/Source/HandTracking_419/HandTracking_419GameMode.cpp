// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HandTracking_419GameMode.h"
#include "HandTracking_419HUD.h"
#include "HandTracking_419Character.h"
#include "UObject/ConstructorHelpers.h"

AHandTracking_419GameMode::AHandTracking_419GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHandTracking_419HUD::StaticClass();
}

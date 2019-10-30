// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MobileVRTestGameMode.h"
#include "MobileVRTestHUD.h"
#include "MobileVRTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMobileVRTestGameMode::AMobileVRTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMobileVRTestHUD::StaticClass();
}

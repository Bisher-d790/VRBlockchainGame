// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "OpenCVTestGameMode.h"
#include "OpenCVTestHUD.h"
#include "OpenCVTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOpenCVTestGameMode::AOpenCVTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AOpenCVTestHUD::StaticClass();
}

// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "VRTest_419GameMode.h"
#include "VRTest_419HUD.h"
#include "VRTest_419Character.h"
#include "UObject/ConstructorHelpers.h"

AVRTest_419GameMode::AVRTest_419GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AVRTest_419HUD::StaticClass();
}

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VRTestiOSGameMode.h"
#include "VRTestiOSHUD.h"
#include "VRTestiOSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AVRTestiOSGameMode::AVRTestiOSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AVRTestiOSHUD::StaticClass();
}

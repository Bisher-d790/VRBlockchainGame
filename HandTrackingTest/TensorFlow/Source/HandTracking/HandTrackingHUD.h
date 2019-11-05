// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HandTrackingHUD.generated.h"

UCLASS()
class AHandTrackingHUD : public AHUD
{
	GENERATED_BODY()

public:
	AHandTrackingHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};


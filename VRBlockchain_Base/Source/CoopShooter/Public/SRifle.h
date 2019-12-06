// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SWeapon.h"
#include "SRifle.generated.h"

/**
 * 
 */

UCLASS()
class COOPSHOOTER_API ASRifle : public ASWeapon
{
	GENERATED_BODY()
	
protected:
		void Fire() override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SWeapon.h"
#include "SProjectileLauncher.generated.h"

/**
 * 
 */

class AProjectile;

UCLASS()
class COOPSHOOTER_API ASProjectileLauncher : public ASWeapon
{
	GENERATED_BODY()
	
protected:
		void Fire() override;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
		TSubclassOf<AActor> Projectile;
};

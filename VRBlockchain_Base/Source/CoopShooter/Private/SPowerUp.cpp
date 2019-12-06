// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerUp.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ASPowerUp::ASPowerUp()
{
	ProcessedTicks = 0;
	NOfTicks = 1;
	TimerInterval = 0.0f;

	SetReplicates(true);
}

void ASPowerUp::ActivatePowerUp(AActor* ForActor) {

	OnActivated(ForActor);

	bPowerUpIsActivated = true;
	OnRep_PowerUpActive();

	if (TimerInterval > 0.0f) {
		GetWorldTimerManager().SetTimer(TimerHandle_PowerUpTick, this, &ASPowerUp::OnTickPowerup, TimerInterval, true);
	}
	else {
		OnTickPowerup();
	}
}

void ASPowerUp::OnTickPowerup() {
	// index for number of ticks
	ProcessedTicks++;

	OnPowerUpTicked();

	if (ProcessedTicks >= NOfTicks) {
		OnExpired();

		bPowerUpIsActivated = false;
		OnRep_PowerUpActive();

		// Clear timer to stop ticking
		GetWorldTimerManager().ClearTimer(TimerHandle_PowerUpTick);
	}
}

void ASPowerUp::OnRep_PowerUpActive()
{
	OnPowerUpStateChange(bPowerUpIsActivated);
}

void ASPowerUp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASPowerUp, bPowerUpIsActivated);
}

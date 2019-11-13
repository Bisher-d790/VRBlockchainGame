// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "SGameMode.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	DefaultHealth = 100.f;
	SetIsReplicated(true);
	bIsDead = false;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwnerRole() == ROLE_Authority) {
		AActor* Owner = GetOwner();
		if (Owner) {
			Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
		}
	}

	Health = DefaultHealth;

}

void UHealthComponent::OnRep_Health(float LastHealth)
{
	float Damage = Health - LastHealth;
	OnHealthChanged.Broadcast(this, Health, Damage,nullptr, nullptr, nullptr);
}

void UHealthComponent::HandleTakeAnyDamage(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	if (Damage <= 0.f || bIsDead) {
		return;
	}

	// Update Health Clamped
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
	
	bIsDead = Health <= 0.0f;

	OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);

	if (bIsDead) {
		ASGameMode* GM = Cast<ASGameMode>(GetWorld()->GetAuthGameMode());
		if (GM) {
			GM->OnActorKilled.Broadcast(GetOwner(), DamageCauser, InstigatedBy);
		}
	}
}

void UHealthComponent::Heal(float HealingAmount)
{
	if (Health <= 0.0f || HealingAmount <= 0.0f) {
		return;
	}

	Health = FMath::Clamp(Health + HealingAmount, 0.0f, DefaultHealth);

	UE_LOG(LogTemp, Log, TEXT("Health Changes: %s (+%s)"), *FString::SanitizeFloat(Health), *FString::SanitizeFloat(HealingAmount));

	OnHealthChanged.Broadcast(this, Health, -HealingAmount, nullptr, nullptr, nullptr);
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UHealthComponent, Health);
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "SPickUp.h"
#include "Components/SphereComponent.h"
#include "Components/DecalComponent.h"
#include "SPowerUp.h"
#include "TimerManager.h"

// Sets default values
ASPickUp::ASPickUp()
{
	// setup the components
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetSphereRadius(75.f);
	RootComponent = SphereComp;

	// Decal to put a mark on the floor
	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->SetRelativeRotation(FRotator(90.f, 0.0f, 0.0f));
	DecalComp->DecalSize = FVector(35.f, 75.f, 75.f);
	DecalComp->SetupAttachment(RootComponent);

	// Timer Duration to reset Pick Up after being taken
	CoolDownDuration = 10.0f;

	SetReplicates(true);
}

void ASPickUp::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (Role == ROLE_Authority && PowerUpInstance) {
		PowerUpInstance->ActivatePowerUp(OtherActor);
		PowerUpInstance = nullptr;

		GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &ASPickUp::Respawn, CoolDownDuration);
	}
}

// Called when the game starts or when spawned
void ASPickUp::BeginPlay()
{
	Super::BeginPlay();

	if (Role == ROLE_Authority) {
		Respawn();
	}
}

void ASPickUp::Respawn()
{

	if (!PowerUpClass) {
		UE_LOG(LogTemp, Warning, TEXT("The PickUp Object %s doesn't have an instance of PowerUp."), *GetName());
		return;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	PowerUpInstance = GetWorld()->SpawnActor<ASPowerUp>(PowerUpClass, GetTransform(), SpawnParams);
}




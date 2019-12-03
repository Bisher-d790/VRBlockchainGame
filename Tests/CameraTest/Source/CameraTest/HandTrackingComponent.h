// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HandTrackingComponent.generated.h"

class UTextureRenderTarget2D;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CAMERATEST_API UHandTrackingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHandTrackingComponent();

	UPROPERTY(EditDefaultsOnly, Category = "HandTracker Component")
		UTextureRenderTarget2D* TextureRenderTarget;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool WritePixelsToArray(UTextureRenderTarget2D& RenderTarget, TArray<FColor>& BitMap);

private:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
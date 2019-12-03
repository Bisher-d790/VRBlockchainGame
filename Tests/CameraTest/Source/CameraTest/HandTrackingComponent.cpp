// Fill out your copyright notice in the Description page of Project Settings.


#include "HandTrackingComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/TextureRenderTarget2D.h"
#include "HighResScreenshot.h"


// Sets default values for this component's properties
UHandTrackingComponent::UHandTrackingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UHandTrackingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

// Called every frame
void UHandTrackingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UHandTrackingComponent::WritePixelsToArray(UTextureRenderTarget2D& TextureRenderTarget, TArray<FColor>& BitMap)
{
	check(IsInGameThread());

	FTextureRenderTargetResource* RTResource = TextureRenderTarget.GameThread_GetRenderTargetResource();
	if (RTResource == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("UHandTrackingComponent: UTextureRenderTarget2D missing render target"));
		return false;
	}

	FReadSurfaceDataFlags ReadPixelFlags(RCM_UNorm);
	ReadPixelFlags.SetLinearToGamma(true);

	return RTResource->ReadPixels(BitMap, ReadPixelFlags);
}

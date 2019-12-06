// Fill out your copyright notice in the Description page of Project Settings.
#include "HandTrackingComponent.h"
#include "Engine/TextureRenderTarget2D.h"


// Sets default values for this component's properties
UHandTrackingComponent::UHandTrackingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Initialize variables
	ThresholdTrackerSizePercentage = 5.f;
	Trackers = TArray<FTracker>();
	Bitmap2D = TArray<TArray<FColor>>();

}


// Called when the game starts
void UHandTrackingComponent::BeginPlay()
{
	Super::BeginPlay();

	// Initialize variables
	if (TextureRenderTarget) {
		float MaxTextureSize = TextureRenderTarget->SizeX * TextureRenderTarget->SizeY;
		ThresholdTrackerSizePixel = ThresholdTrackerSizePercentage * MaxTextureSize / 100;

		UE_LOG(LogTemp, Log, TEXT("Threshold Pixel Distance: %d"), ThresholdTrackerSizePixel);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("UHandTrackingComponent::BeginPlay: UTextureRenderTarget2D reference not set."));
	}
}


// Called every frame
void UHandTrackingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!TextureRenderTarget) {
		UE_LOG(LogTemp, Error, TEXT("UHandTrackingComponent::TickComponent: UTextureRenderTarget2D reference not set."));
		return;
	}

	//// update local Texture maps
	UpdateTexture();

	//// update local trackers according to new Texture
	UpdateTrackers();
}


void UHandTrackingComponent::UpdateTexture()
{
	// update bitmap array
	if (!WritePixelsToArray(*TextureRenderTarget, Bitmap2D)) {
		UE_LOG(LogTemp, Error, TEXT("UHandTrackingComponent::UpdateTexture: Couldn't write TRT2D to 2Darray."))
	}
}


void UHandTrackingComponent::UpdateTrackers()
{
	int trackerIndex = 0;

	// Loop pixels
	for (int32 y = 0; y < Bitmap2D.Num(); y++) {
		for (int32 x = 0; x < Bitmap2D[y].Num(); x++)
		{
			// check if is black(skin detected) or visited
			bool bIsBlack = ((Bitmap2D[y][x].R + Bitmap2D[y][x].G + Bitmap2D[y][x].B) / 3) < 125;

			if (bIsBlack) {
				FTracker tracker;
				tracker.YBorder.X = y;
				tracker.XBorder.X = x;

				CheckTracker(x, y, &tracker);
				tracker.UpdateTrackerParams(TextureRenderTarget->SizeX, TextureRenderTarget->SizeY);

				if (tracker.Size > ThresholdTrackerSizePixel) {
					if (!Trackers.IsValidIndex(trackerIndex))
						Trackers.Add(tracker);
					else {
						Trackers[trackerIndex].XBorder = tracker.XBorder;
						Trackers[trackerIndex].YBorder = tracker.YBorder;
						Trackers[trackerIndex].Size = tracker.Size;
						Trackers[trackerIndex].Position = tracker.Position;
					}
					trackerIndex++;
				}
			}
		}
	}

	Trackers.Sort([](const FTracker& A, const FTracker& B) {
		return A.Size > B.Size;
	});
}


void UHandTrackingComponent::CheckTracker(int32 x, int32 y, FTracker* tracker) {
	// check if is black(skin detected) or visited
	bool bIsBlack = ((Bitmap2D[y][x].R + Bitmap2D[y][x].G + Bitmap2D[y][x].B) / 3) < 125;

	if (bIsBlack) {
		// visited
		Bitmap2D[y][x] = FColor(125, 125, 125);

		if (Bitmap2D[y].IsValidIndex(x + 1))
			CheckTracker(x + 1, y, tracker);
		if (tracker->XBorder.Y < x)	tracker->XBorder.Y = x;

		if (Bitmap2D.IsValidIndex(y + 1))
			CheckTracker(x, y + 1, tracker);
		if (tracker->YBorder.Y < y)	tracker->YBorder.Y = y;

		if (Bitmap2D[y].IsValidIndex(x - 1))
			CheckTracker(x - 1, y, tracker);
		if (tracker->XBorder.X > x)	tracker->XBorder.X = x;
	}
}


FVector2D UHandTrackingComponent::GetPreferredTrackerPosition()
{
	if (Trackers.IsValidIndex(0))
		return Trackers[0].Position;
	return FVector2D();
}


bool UHandTrackingComponent::WritePixelsToArray(UTextureRenderTarget2D& RenderTarget, TArray<TArray<FColor>>& Bitmap2DRef)
{
	if (!RenderTarget.IsValidLowLevel()) {
		UE_LOG(LogTemp, Error, TEXT("UHandTrackingComponent::WritePixelsToArray: UTextureRenderTarget2D missing render target"));
		return false;
	}

	check(IsInGameThread());

	FTextureRenderTargetResource* RTResource = RenderTarget.GameThread_GetRenderTargetResource();
	if (RTResource == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("UHandTrackingComponent::WritePixelsToArray: UTextureRenderTarget2D missing render target"));
		return false;
	}

	FReadSurfaceDataFlags ReadPixelFlags(RCM_UNorm);
	ReadPixelFlags.SetLinearToGamma(true);

	// Array to store Bitmap linear pixels, we store in order not to create one each tick
	TArray<FColor> Bitmap = TArray<FColor>();
	RTResource->ReadPixels(Bitmap, ReadPixelFlags);

	if (Bitmap.Num() <= 0) {
		UE_LOG(LogTemp, Error, TEXT("UHandTrackingComponent::WriteBitmapTo2DArray: Bitmap is empty"));
		return false;
	}

	if (Bitmap2DRef.Num() <= 0) {
		if ((RenderTarget.SizeX | RenderTarget.SizeY) <= 0 || Bitmap.Num() <= 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("UHandTrackingComponent::WriteBitmapTo2DArray: couldn't initialize Bitmap2D, TextureRenderTarget or Bitmap is empty"));
			return false;
		}

		int index = 0;

		for (int32 y = 0; y < RenderTarget.SizeY; y++) {
			TArray<FColor> raw = TArray<FColor>();

			for (int32 x = 0; x < RenderTarget.SizeX; x++) {
				raw.Add(Bitmap[index++]);
			}

			Bitmap2DRef.Add(raw);
		}

		if (index != Bitmap.Num()) UE_LOG(LogTemp, Warning, TEXT("UHandTrackingComponent::WriteBitmapTo2DArray: Bitmap2D initialization error, iterator not equal to bitmap size."));

		return true;
	}

	int index = 0;
	for (int32 y = 0; y < Bitmap2DRef.Num(); y++) {
		for (int32 x = 0; x < Bitmap2DRef[y].Num(); x++) {
			Bitmap2DRef[y][x] = Bitmap[index++];
		}
	}

	if (index != Bitmap.Num()) UE_LOG(LogTemp, Warning, TEXT("UHandTrackingComponent::WriteBitmapTo2DArray: Bitmap2D update error, iterator not equal to bitmap size."));

	return true;
}
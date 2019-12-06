// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HandTrackingComponent.generated.h"

USTRUCT(BlueprintType)
struct FTracker {
	GENERATED_BODY()

public:
	FVector2D XBorder = FVector2D();
	FVector2D YBorder = FVector2D();
	double Size = 0;
	FVector2D Position = FVector2D();

	// recalculates tracker's params
	void UpdateTrackerParams(int32 ScreenSizeX, int32 ScreenSizeY) {

		// Calculate Length
		Size = FMath::Abs(XBorder.Y - XBorder.X); FMath::Abs(YBorder.Y - YBorder.X);

		// Calculate Position
		Position = FVector2D((XBorder.X + XBorder.Y) / 2, (7 * YBorder.X + YBorder.Y) / 8);
	}

	FString ToString() {
		return  ("Xs: " + XBorder.ToString() + "\nYs: " + YBorder.ToString() + "\nSize: " + FString::FromInt(Size)
			+ "\nPosition: " + Position.ToString());
	};

};

class UTextureRenderTarget2D;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COOPSHOOTER_API UHandTrackingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHandTrackingComponent();

	UPROPERTY(EditDefaultsOnly, Category = "HandTracker Component")
		UTextureRenderTarget2D* TextureRenderTarget;

	UFUNCTION(BlueprintCallable, Category = "HandTracker Component")
		void SetTextureRenderTarget(UTextureRenderTarget2D* TextureRender) { this->TextureRenderTarget = TextureRender; }

	// Threshold percentage size for pixels to be considered a tracker, a percentage that is converted to pixels at runtime
	UPROPERTY(EditDefaultsOnly, Category = "HandTracker Component", meta = (ClampMin = "0", ClampMax = "100"))
		float ThresholdTrackerSizePercentage;

	UFUNCTION(BlueprintCallable, Category = "HandTracker Component")
		virtual FVector2D GetPreferredTrackerPosition();

	UFUNCTION(BlueprintCallable, Category = "HandTracker Component")
		inline TArray<FTracker> GetTrackers() { return Trackers; };

	UFUNCTION(BlueprintCallable, Category = "Tracker Utilities")
		FString TrackerToString(FTracker& Tracker) { return  Tracker.ToString(); };

	UFUNCTION(BlueprintCallable, Category = "Tracker Utilities")
		FVector2D GetTrackerPosition(FTracker& Tracker) { return  Tracker.Position; };

	UFUNCTION(BlueprintCallable, Category = "Tracker Utilities")
		float GetTrackerSize(FTracker& Tracker) { return  Tracker.Size; };

	UFUNCTION(BlueprintCallable, Category = "Tracker Utilities")
		FVector2D GetTrackerXBorders(FTracker& Tracker) { return  Tracker.XBorder; };

	UFUNCTION(BlueprintCallable, Category = "Tracker Utilities")
		FVector2D GetTrackerYBorders(FTracker& Tracker) { return  Tracker.YBorder; };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Writes the rendertargettexture to an FColor array
	bool WritePixelsToArray(UTextureRenderTarget2D& RenderTarget, TArray<TArray<FColor>>& Bitmap2D);

	// Function called every tick to update local texture representation maps, template method
	virtual void UpdateTexture();

	// Function called every tick to update local tracker list, template method
	virtual void UpdateTrackers();

private:
	// Array to store trackers
	TArray<FTracker> Trackers = TArray<FTracker>();

	// Array to store Bitmap 2d map pixels, we store in order not to create one each tick
	TArray<TArray<FColor>> Bitmap2D = TArray<TArray<FColor>>();

	// Threshold size for pixels to be considered a tracker, set from the ThresholdPercentageSize value after conversion
	int32 ThresholdTrackerSizePixel;

	// recursive method to get tracker from texture
	void CheckTracker(int32 x, int32 y, FTracker* tracker);
};
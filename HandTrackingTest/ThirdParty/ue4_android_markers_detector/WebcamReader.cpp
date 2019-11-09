// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject5.h"
#include "Engine.h"

#include "WebcamReader.h"


// Sets default values
AWebcamReader::AWebcamReader()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraID = 0;
	isStreamOpen = false;
	VideoSize = FVector2D(640, 480);
	Threshold = 120;
	buffer.reserve(1920 * 1080 * 3);

#ifdef __clang__
#pragma clang diagnostic ignored "-Wmissing-braces"
#endif

	map <int, std::array<float, 3>> markersLocations = {
		{ 11111111, { { 120, 150, 0 } } },
		{ 1100110011, { { 170.5, 150, 0 } } },
	};

	std::array<double, 9> cameraMatrixBuf = { 8.7666720553412040e+002, 0., 3.1147149867982830e+002,
		0., 8.7084221678578592e+002, 2.2823097838101620e+002, 0., 0., 1. };
	std::array<double, 8> cameraDistortionBuf = { 0, 0, 0, 0, 0 };

	int markerHalfSize = 10; //cm

	markersDetector = new MarkersDetector(&markersLocations, cameraMatrixBuf, cameraDistortionBuf, markerHalfSize);
}

// Called when the game starts or when spawned
void AWebcamReader::BeginPlay()
{
	Super::BeginPlay();

	isStreamOpen = markersDetector->captureCamera(CameraID, VideoSize.X, VideoSize.Y);

	if (isStreamOpen)
	{
		UpdateFrame();
		VideoSize = FVector2D(VideoSize.X, VideoSize.Y);
		VideoTexture = UTexture2D::CreateTransient(VideoSize.X, VideoSize.Y);
		VideoTexture->UpdateResource();
		VideoUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, VideoSize.X, VideoSize.Y);

		markersDetector->threshold = Threshold;

		//Initialize data array
		Data.Init(FColor(0, 0, 0, 255), VideoSize.X * VideoSize.Y);
	}

}

void AWebcamReader::UpdateTexture()
{
	if (isStreamOpen && buffer.size())
	{
		//Copy Mat data to Data array
		for (int y = 0; y < VideoSize.Y; y++)
		{
			for (int x = 0; x < VideoSize.X; x++)
			{
				int i = x + (y * VideoSize.X);
				Data[i].B = buffer[i * 3 + 0];
				Data[i].G = buffer[i * 3 + 1];
				Data[i].R = buffer[i * 3 + 2];
			}
		}

		//Update texture 2D
		UpdateTextureRegions(VideoTexture, (int32)0, (uint32)3, VideoUpdateTextureRegion, (uint32)(4 * VideoSize.X), (uint32)4, (uint8*)Data.GetData(), false);
	}
}

void AWebcamReader::UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData)
{
	if (Texture->Resource)
	{
		struct FUpdateTextureRegionsData
		{
			FTexture2DResource* Texture2DResource;
			int32 MipIndex;
			uint32 NumRegions;
			FUpdateTextureRegion2D* Regions;
			uint32 SrcPitch;
			uint32 SrcBpp;
			uint8* SrcData;
		};

		FUpdateTextureRegionsData* RegionData = new FUpdateTextureRegionsData;

		RegionData->Texture2DResource = (FTexture2DResource*)Texture->Resource;
		RegionData->MipIndex = MipIndex;
		RegionData->NumRegions = NumRegions;
		RegionData->Regions = Regions;
		RegionData->SrcPitch = SrcPitch;
		RegionData->SrcBpp = SrcBpp;
		RegionData->SrcData = SrcData;

		ENQUEUE_UNIQUE_RENDER_COMMAND_TWOPARAMETER(
			UpdateTextureRegionsData,
			FUpdateTextureRegionsData*, RegionData, RegionData,
			bool, bFreeData, bFreeData,
			{
				for (uint32 RegionIndex = 0; RegionIndex < RegionData->NumRegions; ++RegionIndex)
				{
					int32 CurrentFirstMip = RegionData->Texture2DResource->GetCurrentFirstMip();
					if (RegionData->MipIndex >= CurrentFirstMip)
					{
						RHIUpdateTexture2D(
							RegionData->Texture2DResource->GetTexture2DRHI(),
							RegionData->MipIndex - CurrentFirstMip,
							RegionData->Regions[RegionIndex],
							RegionData->SrcPitch,
							RegionData->SrcData
							+ RegionData->Regions[RegionIndex].SrcY * RegionData->SrcPitch
							+ RegionData->Regions[RegionIndex].SrcX * RegionData->SrcBpp
							);
					}
				}
				if (bFreeData)
				{
					FMemory::Free(RegionData->Regions);
					FMemory::Free(RegionData->SrcData);
				}
				delete RegionData;
			});
	}
}

// Called every frame
void AWebcamReader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isStreamOpen)
	{
		UpdateFrame();
		UpdateTexture();
		OnNextVideoFrame();
	}

}

void AWebcamReader::UpdateFrame()
{
	if (isStreamOpen)
	{
		std::array<float, 3> camLocation;
		std::array<float, 3> camRotation;

		markersDetector->update(buffer, camLocation, camRotation, usedMarkers);

		cameraLocation.X = nearestEvenInt(camLocation[0]);
		cameraLocation.Y = nearestEvenInt(camLocation[1]);
		cameraLocation.Z = nearestEvenInt(camLocation[2]);

		cameraRotation.Roll = nearestEvenInt(camRotation[0] * 360 / PI);
		cameraRotation.Pitch = nearestEvenInt(camRotation[1] * 360 / PI);
		cameraRotation.Yaw = nearestEvenInt(camRotation[2] * 360 / PI);

		//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::FromInt(usedMarkers));

	}
}

void AWebcamReader::OnNextVideoFrame_Implementation()
{
	// No default implementation
}


void AWebcamReader::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	markersDetector->releaseCamera();
	isStreamOpen = false;
}


int AWebcamReader::nearestEvenInt(float to)
{
	int r = round(to);
	return (r % 2 == 0) ? r : (r + 1);
}
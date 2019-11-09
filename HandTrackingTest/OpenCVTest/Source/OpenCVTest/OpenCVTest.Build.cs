// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class OpenCVTest : ModuleRules
{

    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/")); }
    }

    public OpenCVTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "RHI", "RenderCore" });

        LoadOpenCV(Target);
    }

    private void LoadOpenCV(ReadOnlyTargetRules Target)
    {
        bool isWindowsSupported = (Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32);

        // Create OpenCV Path
        string OpenCVPath = Path.Combine(ThirdPartyPath, "OpenCV");
        // Create Android Libraries Path
        string AndroidLibPath = Path.Combine(ThirdPartyPath, "Android");

        //if (isWindowsSupported)
        //{
            //Add Include path
            PublicIncludePaths.Add(Path.Combine(OpenCVPath, "Includes"));

            // Add Library Path
            PublicLibraryPaths.Add(Path.Combine(OpenCVPath, "Libraries", "Win64"));

        if (isWindowsSupported)
        {
        //Add Static Libraries
        PublicAdditionalLibraries.Add("opencv_world320.lib");

            //Add Dynamic Libraries
            PublicDelayLoadDLLs.Add("opencv_world320.dll");
            if (Target.Platform == UnrealTargetPlatform.Win64)
                PublicDelayLoadDLLs.Add("opencv_ffmpeg320_64.dll");
            else
                PublicDelayLoadDLLs.Add("opencv_ffmpeg320_64.dll");
        }
        else
        {
            PublicAdditionalLibraries.Add(Path.Combine(AndroidLibPath, "libmarkersdetector.so"));
        }

        PublicDefinitions.Add(string.Format("WITH_OPENCV_BINDING={0}", isWindowsSupported ? 1 : 0));
    }
}
// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

public class MyProject5 : ModuleRules
{

    public MyProject5(TargetInfo Target)
    {
        string ModulePath = Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name));
        string ThirdPartyPath = Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/"));

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", "ShaderCore" });

        PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "MarkersDetector", "Includes"));

        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "MarkersDetector", "Win64", "MarkersDetector.lib"));
        }
        else
        {
            PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "MarkersDetector", "Android", "libmarkersdetector.so"));
        }

    }
}

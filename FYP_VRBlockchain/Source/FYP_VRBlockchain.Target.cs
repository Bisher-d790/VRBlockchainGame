// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class FYP_VRBlockchainTarget : TargetRules
{
	public FYP_VRBlockchainTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("FYP_VRBlockchain");
	}
}

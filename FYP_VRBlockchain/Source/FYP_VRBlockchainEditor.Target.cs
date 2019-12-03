// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class FYP_VRBlockchainEditorTarget : TargetRules
{
	public FYP_VRBlockchainEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("FYP_VRBlockchain");
	}
}

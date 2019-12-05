using UnrealBuildTool;
using System.Collections.Generic;

public class EtherlinkerTestTarget : TargetRules
{
	public EtherlinkerTestTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("EtherlinkerTest");
	}
}

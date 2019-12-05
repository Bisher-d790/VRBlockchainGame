using UnrealBuildTool;
using System.Collections.Generic;

public class EtherlinkerTestEditorTarget : TargetRules
{
	public EtherlinkerTestEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("EtherlinkerTest");
	}
}

using UnrealBuildTool;

public class EtherlinkerTest : ModuleRules
{
	public EtherlinkerTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "Etherlinker" });
	}
}

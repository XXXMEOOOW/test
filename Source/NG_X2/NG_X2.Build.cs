// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NG_X2 : ModuleRules
{
	public NG_X2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NG_X2",
			"NG_X2/Variant_Platforming",
			"NG_X2/Variant_Combat",
			"NG_X2/Variant_Combat/AI",
			"NG_X2/Variant_SideScrolling",
			"NG_X2/Variant_SideScrolling/Gameplay",
			"NG_X2/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5_MVVM_Example : ModuleRules
{
	public UE5_MVVM_Example(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine",
			"EnhancedInput",
			"InputCore",
			"ModelViewViewModel",
			"UMG",
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
		});
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

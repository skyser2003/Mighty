// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class Mighty : ModuleRules {
    private string ModulePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }

    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
    }

    public Mighty(TargetInfo Target)
    {
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        LoadLibMighty(Target);
        
        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");
        // if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
        // {
        //		if (UEBuildConfiguration.bCompileSteamOSS == true)
        //		{
        //			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
        //		}
        // }
    }

    public bool LoadLibMighty(TargetInfo Target)
    {
        bool isLibrarySupported = false;

        if ((Target.Platform == UnrealTargetPlatform.Win64)) {
            isLibrarySupported = true;
            PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "libMighty", "lib", "Release", "libMighty.lib"));
        }

        if (isLibrarySupported == true) {
            // Include path
            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "libMighty", "include"));
        }

        Definitions.Add(string.Format("WITH_LIBMIGHTY_BINDING={0}", isLibrarySupported ? 1 : 0));

        return isLibrarySupported;
    }
}

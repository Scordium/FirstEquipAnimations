#pragma once
#include "CoreMinimal.h"
#include "Configuration/ConfigManager.h"
#include "Engine/Engine.h"
#include "FirstEquipConfigStruct.generated.h"

/* Struct generated from Mod Configuration Asset '/FirstEquipAnimations/FirstEquipConfig' */
USTRUCT(BlueprintType)
struct FFirstEquipConfigStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    float Boombox_Chance;

    UPROPERTY(BlueprintReadWrite)
    float Chainsaw_Chance;

    UPROPERTY(BlueprintReadWrite)
    float NobeliskDetonator_Chance;

    UPROPERTY(BlueprintReadWrite)
    float PortableMiner_Chance;

    UPROPERTY(BlueprintReadWrite)
    float RebarGun_Chance;

    UPROPERTY(BlueprintReadWrite)
    float Rifle_Chance;

    UPROPERTY(BlueprintReadWrite)
    float XenoZapper_Chance;

    UPROPERTY(BlueprintReadWrite)
    float XenoBasher_Chance;

    UPROPERTY(BlueprintReadWrite)
    float Unclassified_Chance;

    /* Retrieves active configuration value and returns object of this struct containing it */
    static FFirstEquipConfigStruct GetActiveConfig() {
        FFirstEquipConfigStruct ConfigStruct{};
        FConfigId ConfigId{"FirstEquipAnimations", ""};
        UConfigManager* ConfigManager = GEngine->GetEngineSubsystem<UConfigManager>();
        ConfigManager->FillConfigurationStruct(ConfigId, FDynamicStructInfo{FFirstEquipConfigStruct::StaticStruct(), &ConfigStruct});
        return ConfigStruct;
    }
};


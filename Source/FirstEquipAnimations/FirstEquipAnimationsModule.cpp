#include "FirstEquipAnimationsModule.h"

#include "FGPortableMiner.h"
#include "FirstEquipConfigStruct.h"
#include "Equipment/FGChainsaw.h"
#include "Equipment/FGChargedWeapon.h"
#include "Equipment/FGEquipment.h"
#include "Equipment/FGPortableMinerDispenser.h"
#include "Equipment/BoomBox/FGEquipmentBoomBox.h"
#include "Kismet/KismetMathLibrary.h"
#include "Patching/NativeHookManager.h"

void FFirstEquipAnimationsModule::StartupModule() {

#if !WITH_EDITOR
	SUBSCRIBE_METHOD(AFGEquipment::ShouldShowStinger, [](auto& Scope, const AFGEquipment* self)
	{
		auto config = FFirstEquipConfigStruct::GetActiveConfig(self->GetWorld());
		float chance;

		//Cursed, but eh.
		if(self->GetClass()->IsChildOf(AFGEquipmentBoomBox::StaticClass())) chance = config.Boombox_Chance;
		else if(self->GetClass()->IsChildOf(AFGChainsaw::StaticClass())) chance = config.Chainsaw_Chance;
		else if(self->GetClass()->IsChildOf(AFGChargedWeapon::StaticClass())) chance = config.NobeliskDetonator_Chance;
		else if(self->GetClass()->IsChildOf(AFGPortableMinerDispenser::StaticClass())) chance = config.PortableMiner_Chance;
		else if(self->GetClass()->GetName().Contains("Equip_RebarGun_Projectile")) chance = config.RebarGun_Chance;
		else if(self->GetClass()->GetName().Contains("Equip_Rifle")) chance = config.Rifle_Chance;
		else if(self->GetClass()->GetName().Contains("Equip_ShockShank")) chance = config.XenoZapper_Chance;
		else if(self->GetClass()->GetName().Contains("Equip_StunSpear")) chance = config.XenoBasher_Chance;
		else chance = config.Unclassified_Chance;

		bool showStinger = UKismetMathLibrary::RandomBoolWithWeight(chance/100); 
		Scope.Override(showStinger);
	});
#endif
}

IMPLEMENT_GAME_MODULE(FFirstEquipAnimationsModule, FirstEquipAnimations);
#include "FirstEquipAnimationsModule.h"
#include "Equipment/FGEquipment.h"
#include "Patching/NativeHookManager.h"

void FFirstEquipAnimationsModule::StartupModule() {
	SUBSCRIBE_METHOD(AFGEquipment::ShouldShowStinger, [](auto& Scope, const AFGEquipment* self)
	{
		Scope.Override(true);
	});
}

IMPLEMENT_GAME_MODULE(FFirstEquipAnimationsModule, FirstEquipAnimations);
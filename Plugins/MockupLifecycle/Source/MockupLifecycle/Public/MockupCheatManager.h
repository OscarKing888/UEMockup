#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "MockupCheatManager.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UMockupCheatManager : public UCheatManager
{
    GENERATED_BODY()

public:

	UFUNCTION(Exec)
	void DumpAllActors();
};

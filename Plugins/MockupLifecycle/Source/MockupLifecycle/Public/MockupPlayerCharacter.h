#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MockupPlayerCharacter.generated.h"

UCLASS(Blueprintable, BlueprintType)
class MOCKUPLIFECYCLE_API AMockupPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
    AMockupPlayerCharacter();

    virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void PossessedBy(AController* NewController);
	virtual void UnPossessed();

};

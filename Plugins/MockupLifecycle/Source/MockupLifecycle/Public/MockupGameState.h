#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MockupGameState.generated.h"

UCLASS(Blueprintable, BlueprintType)
class AMockupGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
    AMockupGameState(const FObjectInitializer& ObjectInitializer);	

    virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(ReplicatedUsing = OnRep_GameScore, EditAnywhere, BlueprintReadWrite, Category = "MockupLifecycle")
	int32 GameScore = -1;

	UFUNCTION()
	void OnRep_GameScore();
};

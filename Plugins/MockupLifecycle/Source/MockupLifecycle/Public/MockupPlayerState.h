#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MockupPlayerState.generated.h"

UCLASS(Blueprintable, BlueprintType)
class AMockupPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
    AMockupPlayerState(const FObjectInitializer& ObjectInitializer);	

    virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(ReplicatedUsing= OnRep_PlayerScore, EditAnywhere, BlueprintReadWrite, Category = "MockupLifecycle")
	int32 PlayerScore = -1;

	UFUNCTION()
	void OnRep_PlayerScore();

};

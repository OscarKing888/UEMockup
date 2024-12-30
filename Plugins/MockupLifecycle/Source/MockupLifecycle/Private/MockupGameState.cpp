#include "MockupGameState.h"
#include "MockupLifecycleLogs.h"
#include "Net/UnrealNetwork.h"

AMockupGameState::AMockupGameState(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{	
	LOG_FUN();
}


void AMockupGameState::BeginPlay()
{
    Super::BeginPlay();
	LOG_FUN();
}

void AMockupGameState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
    LOG_FUN_INFO_ALIGN(*MockupGetEnumString(EndPlayReason));
}

void AMockupGameState::OnRep_GameScore()
{
	LOG_FUN_INFO_ALIGN(*FString::Printf(TEXT("GameScore: %d"), GameScore));
}

void AMockupGameState::GetLifetimeReplicatedProps( TArray< FLifetimeProperty > & OutLifetimeProps ) const
{
	Super::GetLifetimeReplicatedProps( OutLifetimeProps );
	LOG_FUN();
	
	DOREPLIFETIME(AMockupGameState, GameScore);
}
#include "MockupPlayerState.h"
#include "MockupLifecycleLogs.h"
#include "Net/UnrealNetwork.h"

AMockupPlayerState::AMockupPlayerState(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{	
	LOG_FUN();
}


void AMockupPlayerState::BeginPlay()
{
    Super::BeginPlay();
	LOG_FUN();
}

void AMockupPlayerState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
    LOG_FUN_INFO_ALIGN(*MockupGetEnumString(EndPlayReason));
}

void AMockupPlayerState::OnRep_PlayerScore()
{
	LOG_FUN_INFO_ALIGN(*FString::Printf(TEXT("PlayerScore: %d"), PlayerScore));
}

void AMockupPlayerState::GetLifetimeReplicatedProps( TArray< FLifetimeProperty > & OutLifetimeProps ) const
{
	Super::GetLifetimeReplicatedProps( OutLifetimeProps );
	LOG_FUN();
	
	DOREPLIFETIME(AMockupPlayerState, PlayerScore);
}
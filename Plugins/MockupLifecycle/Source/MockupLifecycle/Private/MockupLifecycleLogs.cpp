#include "MockupLifecycleLogs.h"
#include "GameFramework/PlayerState.h"


int32 GetPlayerID(const UObject* WorldContextObject)
{
	APlayerController* PlayerController = WorldContextObject->GetWorld()->GetFirstPlayerController();	
	if (PlayerController && PlayerController->PlayerState)
	{
    	int32 PlayerId = PlayerController->PlayerState->GetPlayerId();
		return PlayerId;    	
	}

	return -1;
}

FString GetNetModeString(const UObject* WorldContextObject)
{
	if(!IsValid(WorldContextObject->GetWorld()))
	{
		return TEXT("N/A");
	}

	ENetMode NetMode = WorldContextObject->GetWorld()->GetNetMode();
	switch (NetMode)
	{
	case NM_Standalone:
		return TEXT("Standalone");
	case NM_DedicatedServer:
		return TEXT("DS");
	case NM_ListenServer:
		return TEXT("ListenServer");
	case NM_Client:
		return FString::Printf(TEXT("Client:%d"), GetPlayerID(WorldContextObject));
	case NM_MAX:
		return TEXT("MAX");
	default:
		return TEXT("Unknown");
	}
}

// APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
// if (PlayerController && PlayerController->PlayerState)
// {
//     FUniqueNetIdRepl UniqueNetId = PlayerController->PlayerState->GetUniqueId();
// }


FString MockupGetLogPrefix(const UObject* WorldContextObject)
{
	FString NetModeStr = GetNetModeString(WorldContextObject);

	return FString::Printf(TEXT("\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]"),
		IsRunningGame() ? TEXT("Game") : TEXT("X"),
		IsRunningClientOnly() ? TEXT("ClientOnly") : TEXT("X"),
		IsRunningDedicatedServer() ? TEXT("DS") : TEXT("X"),
		*NetModeStr,
		GIsEditor ? TEXT("Editor") : TEXT("X"),
		GIsServer ? TEXT("Server") : TEXT("X"),
		GIsClient ? TEXT("Client") : TEXT("X"),
		WorldContextObject->HasAnyFlags(RF_ClassDefaultObject) ? TEXT("CDO") : TEXT("X")
		);
}

FString MockupGetLogPrefix()
{
	return  FString::Printf(TEXT("\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]\t[%s]"),
		IsRunningGame() ? TEXT("Game") : TEXT("X"),
		IsRunningClientOnly() ? TEXT("ClientOnly") : TEXT("X"),
		IsRunningDedicatedServer() ? TEXT("DS") : TEXT("X"),
		TEXT(" "),
		GIsEditor ? TEXT("Editor") : TEXT("X"),
		GIsServer ? TEXT("Server") : TEXT("X"),
		GIsClient ? TEXT("Client") : TEXT("X"),
		TEXT(" ")
		);
}


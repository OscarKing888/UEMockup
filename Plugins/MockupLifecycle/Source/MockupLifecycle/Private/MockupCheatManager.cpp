#include "MockupCheatManager.h"
#include "MockupLifecycleActor.h"
#include "EngineUtils.h"
#include "MockupLifecycleLogs.h"


void UMockupCheatManager::DumpAllActors()
{
	if (!GetWorld())
    {
        UE_LOG(LogTemp, Warning, TEXT("GetWorld() returned nullptr. Cannot dump actors."));
        return;
    }

	UE_LOG(LogTemp, Warning, TEXT("==== Dumping all actors in the world..."));
	// dump all AMockupLifecycleActors's Role, RemoteRole, HasAuthority
	for(TActorIterator<AMockupLifecycleActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AMockupLifecycleActor* Actor = *ActorItr;
		FString LogStr = FString::Printf(TEXT("%s\t Role: %s\tRemoteRole: %s\tHasAuthority: %s"),
			*Actor->GetName(),
			*MockupGetEnumString(Actor->GetLocalRole()),
			*MockupGetEnumString(Actor->GetRemoteRole()),
			Actor->HasAuthority() ? TEXT("Y") : TEXT("N"));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *LogStr);
	}
}

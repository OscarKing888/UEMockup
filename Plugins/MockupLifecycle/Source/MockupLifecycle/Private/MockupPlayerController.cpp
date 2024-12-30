#include "MockupPlayerController.h"
#include "MockupCheatManager.h"
#include "MockupLifecycleActor.h"
#include "EngineUtils.h"
#include "MockupLifecycleLogs.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"
#include "MockupPlayerState.h"
#include "MockupGameState.h"


AMockupPlayerController::AMockupPlayerController(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{	
    CheatClass = UMockupCheatManager::StaticClass();
	LOG_FUN();
}


void AMockupPlayerController::ExportActorsToCSV(const FString& FlieName)
{
    // 定义 CSV 文件路径
    FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir() / FlieName);

	UE_LOG(LogTemp, Log, TEXT("Exporting actor data to %s"), *FilePath);

    // CSV 文件的标题行
    FString CSVContent = TEXT("ActorName,Role,RemoteRole,HasAuthority\n");

    // 遍历世界中的所有 Actor
    for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        AActor* Actor = *ActorItr;
        FString ActorName = Actor->GetName();
        FString RoleStr = MockupGetEnumString(Actor->GetLocalRole());
        FString RemoteRoleStr = MockupGetEnumString(Actor->GetRemoteRole());
        FString HasAuthorityStr = Actor->HasAuthority() ? TEXT("Y") : TEXT("N");

        // 将 Actor 信息添加到 CSV 内容中
        CSVContent += FString::Printf(TEXT("%s,%s,%s,%s\n"),
            *ActorName, *RoleStr, *RemoteRoleStr, *HasAuthorityStr);
    }

    // 将 CSV 内容保存到文件
    if (FFileHelper::SaveStringToFile(CSVContent, *FilePath))
    {
        UE_LOG(LogTemp, Log, TEXT("成功将 Actor 信息导出到 %s"), *FilePath);
		
    	OpenCSVFileDirectory(FilePath);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("无法将 Actor 信息保存到 %s"), *FilePath);
    }
}


void AMockupPlayerController::OpenCSVFileDirectory(const FString& DirectoryPath)
{
#if PLATFORM_WINDOWS
	FString AdjustedPath = DirectoryPath;
    AdjustedPath = AdjustedPath.Replace(TEXT("/"), TEXT("\\"), ESearchCase::IgnoreCase);
    FString Command = FString::Printf(TEXT("explorer \"%s\""), *AdjustedPath);
    FPlatformProcess::CreateProc(*Command, nullptr, true, false, false, nullptr, 0, nullptr, nullptr);	
#elif PLATFORM_MAC
    FString Command = FString::Printf(TEXT("open \"%s\""), *DirectoryPath);
    FPlatformProcess::CreateProc(*Command, nullptr, true, false, false, nullptr, 0, nullptr, nullptr);
#elif PLATFORM_LINUX
    FString Command = FString::Printf(TEXT("xdg-open \"%s\""), *DirectoryPath);
    FPlatformProcess::CreateProc(*Command, nullptr, true, false, false, nullptr, 0, nullptr, nullptr);
#endif
}


void AMockupPlayerController::DumpAllActors(const FString& FlieName)
{
	if (!GetWorld())
    {
        UE_LOG(LogTemp, Warning, TEXT("GetWorld() returned nullptr. Cannot dump actors."));
        return;
    }

	UE_LOG(LogTemp, Warning, TEXT("==== Dumping all actors in the world..."));
	// dump all AMockupLifecycleActors's Role, RemoteRole, HasAuthority
	for(TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AActor* Actor = *ActorItr;
		FString LogStr = FString::Printf(TEXT("%s\t Role: %s\tRemoteRole: %s\tHasAuthority: %s"),
			*Actor->GetName(),
			*MockupGetEnumString(Actor->GetLocalRole()),
			*MockupGetEnumString(Actor->GetRemoteRole()),
			Actor->HasAuthority() ? TEXT("Y") : TEXT("N"));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *LogStr);
	}

	ExportActorsToCSV(FlieName);
}


void AMockupPlayerController::DumpAllActorsClient()
{
	DumpAllActors(TEXT("Client_Actors.csv"));
}


void AMockupPlayerController::DumpAllActorsServer()
{
	Server_DumpAllActors();
}


void AMockupPlayerController::Server_DumpAllActors_Implementation()
{
	DumpAllActors(TEXT("DS_Actors.csv"));
	Client_Log(TEXT("Server_DumpAllActors completed!"));
}


void AMockupPlayerController::Client_Log_Implementation(const FString& Message)
{
	UE_LOG(LogTemp, Warning, TEXT("Client_Log: %s"), *Message);
}


void AMockupPlayerController::BeginPlay()
{
    Super::BeginPlay();
	LOG_FUN();

}

void AMockupPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    LOG_FUN_INFO_ALIGN(*MockupGetEnumString(EndPlayReason));
    Super::EndPlay(EndPlayReason);
}

void AMockupPlayerController::OnPossess(APawn* aPawn)
{	
	Super::OnPossess(aPawn);

	if(IsValid(aPawn))
	{
		LOG_FUN_INFO_ALIGN(*FString::Printf(TEXT("Pawn: %s"), *aPawn->GetName()));
	}
	else
	{
		LOG_FUN_INFO_ALIGN(TEXT("Pawn: nullptr"));
	}
	
}

void AMockupPlayerController::OnUnPossess()
{
	Super::OnUnPossess();

	if(IsValid(GetPawn()))
	{
		LOG_FUN_INFO_ALIGN(*FString::Printf(TEXT("Pawn: %s"), *GetPawn()->GetName()));
	}
	else
	{
		LOG_FUN_INFO_ALIGN(TEXT("Pawn: nullptr"));
	}
}

void AMockupPlayerController::AddPlayerScore()
{
	Server_AddPlayerScore();
}


void AMockupPlayerController::Server_AddPlayerScore_Implementation()
{
	AMockupPlayerState* MockupPlayerState = Cast<AMockupPlayerState>(PlayerState);
	if(MockupPlayerState)
	{
		++MockupPlayerState->PlayerScore;
		LOG_FUN_INFO_ALIGN(*FString::Printf(TEXT("PlayerScore:%d"), MockupPlayerState->PlayerScore));
	}
}


void AMockupPlayerController::AddGameScore()
{
	Server_AddPlayerScore();
}


void AMockupPlayerController::Server_AddGameScore_Implementation()
{
	AMockupGameState* MockupGameState = Cast<AMockupGameState>(GetWorld()->GetGameState());
	if(MockupGameState)
	{
		++MockupGameState->GameScore;
		LOG_FUN_INFO_ALIGN(*FString::Printf(TEXT("GameScore:%d"), MockupGameState->GameScore));
	}
}

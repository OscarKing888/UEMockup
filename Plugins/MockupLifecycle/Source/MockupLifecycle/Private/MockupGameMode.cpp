#include "MockupGameMode.h"
#include "MockupLifecycleLogs.h"

AMockupGameMode::AMockupGameMode(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{	
	LOG_FUN();
}


void AMockupGameMode::BeginPlay()
{
    Super::BeginPlay();
	LOG_FUN();

}

void AMockupGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
    LOG_FUN_INFO_ALIGN(*MockupGetEnumString(EndPlayReason));
}


void AMockupGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);
    LOG_FUN();
}

void AMockupGameMode::InitGameState()
{
    Super::InitGameState();
    LOG_FUN();
}

TSubclassOf<AGameSession> AMockupGameMode::GetGameSessionClass() const
{
    auto RetVal = Super::GetGameSessionClass();
    LOG_FUN();
    return RetVal;
}

int32 AMockupGameMode::GetNumPlayers()
{
    auto RetVal = Super::GetNumPlayers();
    LOG_FUN();
    return RetVal;
}

int32 AMockupGameMode::GetNumSpectators()
{
    auto RetVal = Super::GetNumSpectators();
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::StartPlay()
{
    Super::StartPlay();
    LOG_FUN();
}

bool AMockupGameMode::HasMatchStarted() const
{
    auto RetVal = Super::HasMatchStarted();
    LOG_FUN();
    return RetVal;
}

bool AMockupGameMode::HasMatchEnded() const
{
    auto RetVal = Super::HasMatchEnded();
    LOG_FUN();
    return RetVal;
}

bool AMockupGameMode::ClearPause()
{
    auto RetVal = Super::ClearPause();
    LOG_FUN();
    return RetVal;
}

bool AMockupGameMode::AllowPausing(APlayerController* PC)
{
    auto RetVal = Super::AllowPausing(PC);
    LOG_FUN();
    return RetVal;
}

bool AMockupGameMode::IsPaused() const
{
    auto RetVal = Super::IsPaused();
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::ResetLevel()
{
    Super::ResetLevel();
    LOG_FUN();
}

void AMockupGameMode::ReturnToMainMenuHost()
{
    Super::ReturnToMainMenuHost();
    LOG_FUN();
}

bool AMockupGameMode::CanServerTravel(const FString& URL, bool bAbsolute)
{
    auto RetVal = Super::CanServerTravel(URL, bAbsolute);
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::ProcessServerTravel(const FString& URL, bool bAbsolute)
{
    Super::ProcessServerTravel(URL, bAbsolute);
    LOG_FUN();
}

void AMockupGameMode::GetSeamlessTravelActorList(bool bToTransition, TArray<AActor*>& ActorList)
{
    Super::GetSeamlessTravelActorList(bToTransition, ActorList);
    LOG_FUN();
}

void AMockupGameMode::SwapPlayerControllers(APlayerController* OldPC, APlayerController* NewPC)
{
    Super::SwapPlayerControllers(OldPC, NewPC);
    LOG_FUN();
}

TSubclassOf<APlayerController> AMockupGameMode::GetPlayerControllerClassToSpawnForSeamlessTravel(APlayerController* PreviousPlayerController)
{
    auto RetVal = Super::GetPlayerControllerClassToSpawnForSeamlessTravel(PreviousPlayerController);
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::HandleSeamlessTravelPlayer(AController*& C)
{
    Super::HandleSeamlessTravelPlayer(C);
    LOG_FUN();
}

void AMockupGameMode::PostSeamlessTravel()
{
    Super::PostSeamlessTravel();
    LOG_FUN();
}

void AMockupGameMode::StartToLeaveMap()
{
    Super::StartToLeaveMap();
    LOG_FUN();
}

void AMockupGameMode::GameWelcomePlayer(UNetConnection* Connection, FString& RedirectURL)
{
    Super::GameWelcomePlayer(Connection, RedirectURL);
    LOG_FUN();
}

void AMockupGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
    LOG_FUN();
}

void AMockupGameMode::PreLoginAsync(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, const FOnPreLoginCompleteDelegate& OnComplete)
{
    Super::PreLoginAsync(Options, Address, UniqueId, OnComplete);
    LOG_FUN();
}

APlayerController* AMockupGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    auto RetVal = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);
    LOG_FUN();
}

void AMockupGameMode::Logout(AController* Exiting)
{
    Super::Logout(Exiting);
    LOG_FUN();
}

APlayerController* AMockupGameMode::SpawnPlayerController(ENetRole InRemoteRole, const FString& Options)
{
    auto RetVal = Super::SpawnPlayerController(InRemoteRole, Options);
    LOG_FUN();
    return RetVal;
}

APlayerController* AMockupGameMode::SpawnPlayerController(ENetRole InRemoteRole, FVector const& SpawnLocation, FRotator const& SpawnRotation)
{
    auto RetVal = Super::SpawnPlayerController(InRemoteRole, SpawnLocation, SpawnRotation);
    LOG_FUN();
    return RetVal;
}

APlayerController* AMockupGameMode::SpawnReplayPlayerController(ENetRole InRemoteRole, FVector const& SpawnLocation, FRotator const& SpawnRotation)
{
    auto RetVal = Super::SpawnReplayPlayerController(InRemoteRole, SpawnLocation, SpawnRotation);
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::ChangeName(AController* Controller, const FString& NewName, bool bNameChange)
{
    Super::ChangeName(Controller, NewName, bNameChange);
    LOG_FUN();
}

void AMockupGameMode::RestartPlayer(AController* NewPlayer)
{
    Super::RestartPlayer(NewPlayer);
    LOG_FUN();
}

void AMockupGameMode::RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot)
{
    Super::RestartPlayerAtPlayerStart(NewPlayer, StartSpot);
    LOG_FUN();
}

void AMockupGameMode::RestartPlayerAtTransform(AController* NewPlayer, const FTransform& SpawnTransform)
{
    Super::RestartPlayerAtTransform(NewPlayer, SpawnTransform);
    LOG_FUN();
}

void AMockupGameMode::SetPlayerDefaults(APawn* PlayerPawn)
{
    Super::SetPlayerDefaults(PlayerPawn);
    LOG_FUN();
}

bool AMockupGameMode::AllowCheats(APlayerController* P)
{
    auto RetVal = Super::AllowCheats(P);
    LOG_FUN();
    return RetVal;
}

bool AMockupGameMode::IsHandlingReplays()
{
    auto RetVal = Super::IsHandlingReplays();
    LOG_FUN();
    return RetVal;
}

bool AMockupGameMode::SpawnPlayerFromSimulate(const FVector& NewLocation, const FRotator& NewRotation)
{
    auto RetVal = Super::SpawnPlayerFromSimulate(NewLocation, NewRotation);
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::PreInitializeComponents()
{
    Super::PreInitializeComponents();
    LOG_FUN();
}

void AMockupGameMode::Reset()
{
    Super::Reset();
    LOG_FUN();
}

bool AMockupGameMode::UpdatePlayerStartSpot(AController* Player, const FString& Portal, FString& OutErrorMessage)
{
    auto RetVal = Super::UpdatePlayerStartSpot(Player, Portal, OutErrorMessage);
    LOG_FUN();
    return RetVal;
}

bool AMockupGameMode::ShouldStartInCinematicMode(APlayerController* Player, bool& OutHidePlayer, bool& OutHideHud, bool& OutDisableMovement, bool& OutDisableTurning)
{
    auto RetVal = Super::ShouldStartInCinematicMode(Player, OutHidePlayer, OutHideHud, OutDisableMovement, OutDisableTurning);
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::UpdateGameplayMuteList(APlayerController* aPlayer)
{
    Super::UpdateGameplayMuteList(aPlayer);
    LOG_FUN();
}

void AMockupGameMode::GenericPlayerInitialization(AController* C)
{
    Super::GenericPlayerInitialization(C);
    LOG_FUN();
}

void AMockupGameMode::ReplicateStreamingStatus(APlayerController* PC)
{
    Super::ReplicateStreamingStatus(PC);
    LOG_FUN();
}

bool AMockupGameMode::ShouldSpawnAtStartSpot(AController* Player)
{
    auto RetVal = Super::ShouldSpawnAtStartSpot(Player);
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::FinishRestartPlayer(AController* NewPlayer, const FRotator& StartRotation)
{
    Super::FinishRestartPlayer(NewPlayer, StartRotation);
    LOG_FUN();
}

void AMockupGameMode::FailedToRestartPlayer(AController* NewPlayer)
{
    Super::FailedToRestartPlayer(NewPlayer);
    LOG_FUN();
}

APlayerController* AMockupGameMode::ProcessClientTravel(FString& URL, bool bSeamless, bool bAbsolute)
{
    auto RetVal = Super::ProcessClientTravel(URL, bSeamless, bAbsolute);
    LOG_FUN();
    return RetVal;
}

void AMockupGameMode::InitSeamlessTravelPlayer(AController* NewController)
{
    Super::InitSeamlessTravelPlayer(NewController);
    LOG_FUN();
}

APlayerController* AMockupGameMode::SpawnPlayerControllerCommon(ENetRole InRemoteRole, FVector const& SpawnLocation, FRotator const& SpawnRotation, TSubclassOf<APlayerController> InPlayerControllerClass)
{
    auto RetVal = Super::SpawnPlayerControllerCommon(InRemoteRole, SpawnLocation, SpawnRotation, InPlayerControllerClass);
    LOG_FUN();
    return RetVal;
}
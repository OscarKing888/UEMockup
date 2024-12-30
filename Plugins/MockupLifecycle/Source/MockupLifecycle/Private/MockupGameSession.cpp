#include "MockupGameSession.h"
#include "MockupLifecycleLogs.h"

AMockupGameSession::AMockupGameSession(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{	
	LOG_FUN();
}


void AMockupGameSession::BeginPlay()
{
    Super::BeginPlay();
	LOG_FUN();

}

void AMockupGameSession::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
    LOG_FUN_INFO_ALIGN(*MockupGetEnumString(EndPlayReason));
}


void AMockupGameSession::InitOptions(const FString& Options)
{
    Super::InitOptions(Options);
    LOG_FUN();
}

bool AMockupGameSession::ProcessAutoLogin()
{
    auto RetVal = Super::ProcessAutoLogin();
    LOG_FUN();
    return RetVal;
}

void AMockupGameSession::OnAutoLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FString& Error)
{
    Super::OnAutoLoginComplete(LocalUserNum, bWasSuccessful, Error);
    LOG_FUN();
}

FString AMockupGameSession::ApproveLogin(const FString& Options)
{
    auto RetVal = Super::ApproveLogin(Options);
    LOG_FUN();
    return RetVal;
}

void AMockupGameSession::RegisterPlayer(APlayerController* NewPlayer, const FUniqueNetIdRepl& UniqueId, bool bWasFromInvite)
{
    Super::RegisterPlayer(NewPlayer, UniqueId, bWasFromInvite);
    LOG_FUN();
}

void AMockupGameSession::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);
    LOG_FUN();
}

bool AMockupGameSession::AtCapacity(bool bSpectator)
{
    auto RetVal = Super::AtCapacity(bSpectator);
    LOG_FUN();
    return RetVal;
}

void AMockupGameSession::NotifyLogout(const APlayerController* PC)
{
    Super::NotifyLogout(PC);
    LOG_FUN();
}

void AMockupGameSession::NotifyLogout(FName InSessionName, const FUniqueNetIdRepl& UniqueId)
{
    Super::NotifyLogout(InSessionName, UniqueId);
    LOG_FUN();
}

void AMockupGameSession::UnregisterPlayer(FName InSessionName, const FUniqueNetIdRepl& UniqueId)
{
    Super::UnregisterPlayer(InSessionName, UniqueId);
    LOG_FUN();
}

void AMockupGameSession::UnregisterPlayers(FName InSessionName, const TArray< FUniqueNetIdRepl >& Players)
{
    Super::UnregisterPlayers(InSessionName, Players);
    LOG_FUN();
}

void AMockupGameSession::UnregisterPlayer(const APlayerController* ExitingPlayer)
{
    Super::UnregisterPlayer(ExitingPlayer);
    LOG_FUN();
}

void AMockupGameSession::AddAdmin(APlayerController* AdminPlayer)
{
    Super::AddAdmin(AdminPlayer);
    LOG_FUN();
}

void AMockupGameSession::RemoveAdmin(APlayerController* AdminPlayer)
{
    Super::RemoveAdmin(AdminPlayer);
    LOG_FUN();
}

bool AMockupGameSession::KickPlayer(APlayerController* KickedPlayer, const FText& KickReason)
{
    auto RetVal = Super::KickPlayer(KickedPlayer, KickReason);
    LOG_FUN();
    return RetVal;
}

bool AMockupGameSession::BanPlayer(APlayerController* BannedPlayer, const FText& BanReason)
{
    auto RetVal = Super::BanPlayer(BannedPlayer, BanReason);
    LOG_FUN();
    return RetVal;
}

void AMockupGameSession::ReturnToMainMenuHost()
{
    Super::ReturnToMainMenuHost();
    LOG_FUN();
}

void AMockupGameSession::PostSeamlessTravel()
{
    Super::PostSeamlessTravel();
    LOG_FUN();
}

void AMockupGameSession::RegisterServer()
{
    Super::RegisterServer();
    LOG_FUN();
}

void AMockupGameSession::RegisterServerFailed()
{
    Super::RegisterServerFailed();
    LOG_FUN();
}

bool AMockupGameSession::GetSessionJoinability(FName InSessionName, FJoinabilitySettings& OutSettings)
{
    auto RetVal = Super::GetSessionJoinability(InSessionName, OutSettings);
    LOG_FUN();
    return RetVal;
}

void AMockupGameSession::UpdateSessionJoinability(FName InSessionName, bool bPublicSearchable, bool bAllowInvites, bool bJoinViaPresence, bool bJoinViaPresenceFriendsOnly)
{
    Super::UpdateSessionJoinability(InSessionName, bPublicSearchable, bAllowInvites, bJoinViaPresence, bJoinViaPresenceFriendsOnly);
    LOG_FUN();
}

void AMockupGameSession::DumpSessionState()
{
    Super::DumpSessionState();
    LOG_FUN();
}

bool AMockupGameSession::HandleStartMatchRequest()
{
    auto RetVal = Super::HandleStartMatchRequest();
    LOG_FUN();
    return RetVal;
}

void AMockupGameSession::HandleMatchIsWaitingToStart()
{
    Super::HandleMatchIsWaitingToStart();
    LOG_FUN();
}

void AMockupGameSession::HandleMatchHasStarted()
{
    Super::HandleMatchHasStarted();
    LOG_FUN();
}

void AMockupGameSession::HandleMatchHasEnded()
{
    Super::HandleMatchHasEnded();
    LOG_FUN();
}

bool AMockupGameSession::CanRestartGame()
{
    auto RetVal = Super::CanRestartGame();
    LOG_FUN();
    return RetVal;
}

void AMockupGameSession::OnStartSessionComplete(FName InSessionName, bool bWasSuccessful)
{
    Super::OnStartSessionComplete(InSessionName, bWasSuccessful);
    LOG_FUN();
}

void AMockupGameSession::OnEndSessionComplete(FName InSessionName, bool bWasSuccessful)
{
    Super::OnEndSessionComplete(InSessionName, bWasSuccessful);
    LOG_FUN();
}

void AMockupGameSession::PostReloadConfig(FProperty* PropertyThatWasLoaded)
{
    Super::PostReloadConfig(PropertyThatWasLoaded);
    LOG_FUN();
}


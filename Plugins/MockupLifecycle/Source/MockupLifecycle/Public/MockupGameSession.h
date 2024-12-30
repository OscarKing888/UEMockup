#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "MockupGameSession.generated.h"

UCLASS(Blueprintable, BlueprintType)
class AMockupGameSession : public AGameSession
{
	GENERATED_BODY()

public:
    AMockupGameSession(const FObjectInitializer& ObjectInitializer);	

    virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void InitOptions(const FString& Options) override;
    virtual bool ProcessAutoLogin() override;
    virtual void OnAutoLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FString& Error) override;
    virtual FString ApproveLogin(const FString& Options) override;
    virtual void RegisterPlayer(APlayerController* NewPlayer, const FUniqueNetIdRepl& UniqueId, bool bWasFromInvite) override;
    virtual void PostLogin(APlayerController* NewPlayer) override;
    virtual bool AtCapacity(bool bSpectator) override;
    virtual void NotifyLogout(const APlayerController* PC) override;
    virtual void NotifyLogout(FName InSessionName, const FUniqueNetIdRepl& UniqueId) override;
    virtual void UnregisterPlayer(FName InSessionName, const FUniqueNetIdRepl& UniqueId) override;
    virtual void UnregisterPlayers(FName InSessionName, const TArray< FUniqueNetIdRepl >& Players) override;
    virtual void UnregisterPlayer(const APlayerController* ExitingPlayer) override;
    virtual void AddAdmin(APlayerController* AdminPlayer) override;
    virtual void RemoveAdmin(APlayerController* AdminPlayer) override;
    virtual bool KickPlayer(APlayerController* KickedPlayer, const FText& KickReason) override;
    virtual bool BanPlayer(APlayerController* BannedPlayer, const FText& BanReason) override;
    virtual void ReturnToMainMenuHost() override;
    virtual void PostSeamlessTravel() override;
    virtual void RegisterServer() override;
    virtual void RegisterServerFailed() override;
    virtual bool GetSessionJoinability(FName InSessionName, FJoinabilitySettings& OutSettings) override;
    virtual void UpdateSessionJoinability(FName InSessionName, bool bPublicSearchable, bool bAllowInvites, bool bJoinViaPresence, bool bJoinViaPresenceFriendsOnly) override;
    virtual void DumpSessionState() override;
    virtual bool HandleStartMatchRequest() override;
    virtual void HandleMatchIsWaitingToStart() override;
    virtual void HandleMatchHasStarted() override;
    virtual void HandleMatchHasEnded() override;
    virtual bool CanRestartGame() override;
    virtual void OnStartSessionComplete(FName InSessionName, bool bWasSuccessful) override;
    virtual void OnEndSessionComplete(FName InSessionName, bool bWasSuccessful) override;
    virtual void PostReloadConfig(FProperty* PropertyThatWasLoaded) override;
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MockupGameMode.generated.h"

UCLASS(Blueprintable, BlueprintType)
class AMockupGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    AMockupGameMode(const FObjectInitializer& ObjectInitializer);	

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
    virtual void InitGameState() override;
    virtual TSubclassOf<AGameSession> GetGameSessionClass() const override;
    virtual int32 GetNumPlayers() override;
    virtual int32 GetNumSpectators() override;
    virtual void StartPlay() override;
    virtual bool HasMatchStarted() const override;
    virtual bool HasMatchEnded() const override;
    //virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
    virtual bool ClearPause() override;
    virtual bool AllowPausing(APlayerController* PC = nullptr) override;
    virtual bool IsPaused() const override;
    virtual void ResetLevel() override;
    virtual void ReturnToMainMenuHost() override;
    virtual bool CanServerTravel(const FString& URL, bool bAbsolute) override;
    virtual void ProcessServerTravel(const FString& URL, bool bAbsolute = false) override;
    virtual void GetSeamlessTravelActorList(bool bToTransition, TArray<AActor*>& ActorList) override;
    virtual void SwapPlayerControllers(APlayerController* OldPC, APlayerController* NewPC) override;
    virtual TSubclassOf<APlayerController> GetPlayerControllerClassToSpawnForSeamlessTravel(APlayerController* PreviousPlayerController) override;
    virtual void HandleSeamlessTravelPlayer(AController*& C) override;
    virtual void PostSeamlessTravel() override;
    virtual void StartToLeaveMap() override;
    virtual void GameWelcomePlayer(UNetConnection* Connection, FString& RedirectURL) override;
    virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
    virtual void PreLoginAsync(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, const FOnPreLoginCompleteDelegate& OnComplete) override;
    virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
    virtual void PostLogin(APlayerController* NewPlayer) override;
    virtual void Logout(AController* Exiting) override;
    virtual APlayerController* SpawnPlayerController(ENetRole InRemoteRole, const FString& Options) override;
    virtual APlayerController* SpawnPlayerController(ENetRole InRemoteRole, FVector const& SpawnLocation, FRotator const& SpawnRotation) override;
    virtual APlayerController* SpawnReplayPlayerController(ENetRole InRemoteRole, FVector const& SpawnLocation, FRotator const& SpawnRotation) override;
    virtual void ChangeName(AController* Controller, const FString& NewName, bool bNameChange) override;
    virtual void RestartPlayer(AController* NewPlayer) override;
    virtual void RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot) override;
    virtual void RestartPlayerAtTransform(AController* NewPlayer, const FTransform& SpawnTransform) override;
    virtual void SetPlayerDefaults(APawn* PlayerPawn) override;
    virtual bool AllowCheats(APlayerController* P) override;
    virtual bool IsHandlingReplays() override;
    virtual bool SpawnPlayerFromSimulate(const FVector& NewLocation, const FRotator& NewRotation) override;
    virtual void PreInitializeComponents() override;
    virtual void Reset() override;
    virtual bool UpdatePlayerStartSpot(AController* Player, const FString& Portal, FString& OutErrorMessage) override;
    virtual bool ShouldStartInCinematicMode(APlayerController* Player, bool& OutHidePlayer, bool& OutHideHud, bool& OutDisableMovement, bool& OutDisableTurning) override;
    virtual void UpdateGameplayMuteList(APlayerController* aPlayer) override;
    
	//virtual FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal = TEXT("")) override;

    virtual void GenericPlayerInitialization(AController* C) override;
    virtual void ReplicateStreamingStatus(APlayerController* PC) override;
    virtual bool ShouldSpawnAtStartSpot(AController* Player) override;
    virtual void FinishRestartPlayer(AController* NewPlayer, const FRotator& StartRotation) override;
    virtual void FailedToRestartPlayer(AController* NewPlayer) override;
    virtual APlayerController* ProcessClientTravel(FString& URL, bool bSeamless, bool bAbsolute) override;
    virtual void InitSeamlessTravelPlayer(AController* NewController) override;
    virtual APlayerController* SpawnPlayerControllerCommon(ENetRole InRemoteRole, FVector const& SpawnLocation, FRotator const& SpawnRotation, TSubclassOf<APlayerController> InPlayerControllerClass) override;
};

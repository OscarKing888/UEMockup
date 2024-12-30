#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MockupGameInstance.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UMockupGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
    UMockupGameInstance(const FObjectInitializer& ObjectInitializer);
	
	virtual bool HandleOpenCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld) override;
    virtual bool HandleDisconnectCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld) override;
    virtual bool HandleReconnectCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld) override;
    virtual bool HandleTravelCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld) override;

#if UE_ALLOW_EXEC_COMMANDS
    virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Out = *GLog) override;
#endif

    virtual void FinishDestroy() override;
    virtual void Init() override;
    virtual void Shutdown() override;
    virtual void HandleInputDeviceConnectionChange(EInputDeviceConnectionState NewConnectionState, FPlatformUserId PlatformUserId, FInputDeviceId InputDeviceId) override;
    virtual void HandleInputDevicePairingChange(FInputDeviceId InputDeviceId, FPlatformUserId NewUserPlatformId, FPlatformUserId OldUserPlatformId) override;
	
#if WITH_EDITOR	
    virtual FGameInstancePIEResult InitializeForPlayInEditor(int32 PIEInstanceIndex, const struct FGameInstancePIEParameters& Params) override;
    virtual FGameInstancePIEResult StartPlayInEditorGameInstance(ULocalPlayer* LocalPlayer, const struct FGameInstancePIEParameters& Params) override;
    virtual FGameInstancePIEResult PostCreateGameModeForPIE(const FGameInstancePIEParameters& Params, AGameModeBase* GameMode) override;
    virtual void ReportPIEStartupTime() override;
#endif

    virtual void OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld) override;
    virtual void StartGameInstance() override;
    virtual void			DebugCreatePlayer(int32 ControllerId) override;
    virtual void			DebugRemovePlayer(int32 ControllerId) override;
    virtual ULocalPlayer*	CreateInitialPlayer(FString& OutError) override;
    //virtual int32			AddLocalPlayer(ULocalPlayer* NewPlayer, int32 ControllerId) override;
    virtual int32 AddLocalPlayer(ULocalPlayer* NewPlayer, FPlatformUserId UserId) override;
    virtual bool			RemoveLocalPlayer(ULocalPlayer * ExistingPlayer) override;
    
	//virtual void StartRecordingReplay(const FString& InName, const FString& FriendlyName, const TArray<FString>& AdditionalOptions = TArray<FString>(), TSharedPtr<IAnalyticsProvider> AnalyticsProvider = nullptr) override;
    virtual void StopRecordingReplay() override;
    //virtual bool PlayReplay(const FString& InName, UWorld* WorldOverride = nullptr, const TArray<FString>& AdditionalOptions = TArray<FString>()) override;
    
	virtual void AddUserToReplay(const FString& UserString) override;
    virtual bool EnableListenServer(bool bEnable, int32 PortOverride = 0) override;
    virtual void ReceivedNetworkEncryptionToken(const FString& EncryptionToken, const FOnEncryptionKeyResponse& Delegate) override;
    virtual void ReceivedNetworkEncryptionAck(const FOnEncryptionKeyResponse& Delegate) override;
    virtual EEncryptionFailureAction ReceivedNetworkEncryptionFailure(UNetConnection* Connection) override;
    virtual void PreloadContentForURL(FURL InURL) override;
    virtual class AGameModeBase* CreateGameModeForURL(FURL InURL, UWorld* InWorld) override;
    virtual void SetPersistentTravelURL(FURL InURL) override;
    virtual TSubclassOf<AGameModeBase> OverrideGameModeClass(TSubclassOf<AGameModeBase> GameModeClass, const FString& MapName, const FString& Options, const FString& Portal) const override;
    virtual TSubclassOf<UOnlineSession> GetOnlineSessionClass() override;
    virtual FName GetOnlinePlatformName() const override;
    virtual bool ClientTravelToSession(int32 ControllerId, FName InSessionName) override;
    virtual void ReturnToMainMenu() override;
    virtual void RegisterReferencedObject(UObject* ObjectToReference) override;
    virtual void UnregisterReferencedObject(UObject* ObjectToReference) override;
    virtual EReplicationSystem GetDesiredReplicationSystem(FName InNetDriverDefinition) const override;
    virtual void OnStart() override;
};

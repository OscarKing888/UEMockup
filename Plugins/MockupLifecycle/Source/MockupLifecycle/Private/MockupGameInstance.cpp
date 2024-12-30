#include "MockupGameInstance.h"
#include "MockupLifecycleLogs.h"

UMockupGameInstance::UMockupGameInstance(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{	
	LOG_FUN();
}


bool UMockupGameInstance::HandleOpenCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld)
{
    auto RetVal = Super::HandleOpenCommand(Cmd, Ar, InWorld);
    LOG_FUN();
    return RetVal;
}

bool UMockupGameInstance::HandleDisconnectCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld)
{
    auto RetVal = Super::HandleDisconnectCommand(Cmd, Ar, InWorld);
    LOG_FUN();
    return RetVal;
}

bool UMockupGameInstance::HandleReconnectCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld)
{
    auto RetVal = Super::HandleReconnectCommand(Cmd, Ar, InWorld);
    LOG_FUN();
    return RetVal;
}

bool UMockupGameInstance::HandleTravelCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld)
{
    auto RetVal = Super::HandleTravelCommand(Cmd, Ar, InWorld);
    LOG_FUN();
    return RetVal;
}

#if UE_ALLOW_EXEC_COMMANDS
bool UMockupGameInstance::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Out)
{
    auto RetVal = Super::Exec(InWorld, Cmd, Out);
    LOG_FUN();
    return RetVal;
}
#endif

void UMockupGameInstance::FinishDestroy()
{
    Super::FinishDestroy();
    LOG_FUN();
}

void UMockupGameInstance::Init()
{
    Super::Init();
    LOG_FUN();
}

void UMockupGameInstance::Shutdown()
{
    Super::Shutdown();
    LOG_FUN();
}

void UMockupGameInstance::HandleInputDeviceConnectionChange(EInputDeviceConnectionState NewConnectionState, FPlatformUserId PlatformUserId, FInputDeviceId InputDeviceId)
{
    Super::HandleInputDeviceConnectionChange(NewConnectionState, PlatformUserId, InputDeviceId);
    LOG_FUN();
}

void UMockupGameInstance::HandleInputDevicePairingChange(FInputDeviceId InputDeviceId, FPlatformUserId NewUserPlatformId, FPlatformUserId OldUserPlatformId)
{
    Super::HandleInputDevicePairingChange(InputDeviceId, NewUserPlatformId, OldUserPlatformId);
    LOG_FUN();
}

#if WITH_EDITOR

FGameInstancePIEResult UMockupGameInstance::InitializeForPlayInEditor(int32 PIEInstanceIndex, const FGameInstancePIEParameters& Params)
{
    auto RetVal = Super::InitializeForPlayInEditor(PIEInstanceIndex, Params);
    LOG_FUN();
    return RetVal;
}

FGameInstancePIEResult UMockupGameInstance::StartPlayInEditorGameInstance(ULocalPlayer* LocalPlayer, const FGameInstancePIEParameters& Params)
{
    auto RetVal = Super::StartPlayInEditorGameInstance(LocalPlayer, Params);
    LOG_FUN();
    return RetVal;
}

FGameInstancePIEResult UMockupGameInstance::PostCreateGameModeForPIE(const FGameInstancePIEParameters& Params, AGameModeBase* GameMode)
{
    auto RetVal = Super::PostCreateGameModeForPIE(Params, GameMode);
    LOG_FUN();
    return RetVal;
}

void UMockupGameInstance::ReportPIEStartupTime()
{
    Super::ReportPIEStartupTime();
    LOG_FUN();
}

#endif

void UMockupGameInstance::OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld)
{
    Super::OnWorldChanged(OldWorld, NewWorld);
    LOG_FUN();
}

void UMockupGameInstance::StartGameInstance()
{
    Super::StartGameInstance();
    LOG_FUN();
}

void UMockupGameInstance::DebugCreatePlayer(int32 ControllerId)
{
    Super::DebugCreatePlayer(ControllerId);
    LOG_FUN();
}

void UMockupGameInstance::DebugRemovePlayer(int32 ControllerId)
{
    Super::DebugRemovePlayer(ControllerId);
    LOG_FUN();
}

ULocalPlayer* UMockupGameInstance::CreateInitialPlayer(FString& OutError)
{
    auto RetVal = Super::CreateInitialPlayer(OutError);
    LOG_FUN();
    return RetVal;
}

// int32 UMockupGameInstance::AddLocalPlayer(ULocalPlayer* NewPlayer, int32 ControllerId)
// {
//     auto RetVal = Super::AddLocalPlayer(NewPlayer, ControllerId);
//     LOG_FUN();
//     return RetVal;
// }

int32 UMockupGameInstance::AddLocalPlayer(ULocalPlayer* NewPlayer, FPlatformUserId UserId)
{
    auto RetVal = Super::AddLocalPlayer(NewPlayer, UserId);
    LOG_FUN();
    return RetVal;
}

bool UMockupGameInstance::RemoveLocalPlayer(ULocalPlayer * ExistingPlayer)
{
    auto RetVal = Super::RemoveLocalPlayer(ExistingPlayer);
    LOG_FUN();
    return RetVal;
}

void UMockupGameInstance::StopRecordingReplay()
{
    Super::StopRecordingReplay();
    LOG_FUN();
}

void UMockupGameInstance::AddUserToReplay(const FString& UserString)
{
    Super::AddUserToReplay(UserString);
    LOG_FUN();
}

bool UMockupGameInstance::EnableListenServer(bool bEnable, int32 PortOverride)
{
    auto RetVal = Super::EnableListenServer(bEnable, PortOverride);
    LOG_FUN();
    return RetVal;
}

void UMockupGameInstance::ReceivedNetworkEncryptionToken(const FString& EncryptionToken, const FOnEncryptionKeyResponse& Delegate)
{
    Super::ReceivedNetworkEncryptionToken(EncryptionToken, Delegate);
    LOG_FUN();
}

void UMockupGameInstance::ReceivedNetworkEncryptionAck(const FOnEncryptionKeyResponse& Delegate)
{
    Super::ReceivedNetworkEncryptionAck(Delegate);
    LOG_FUN();
}

EEncryptionFailureAction UMockupGameInstance::ReceivedNetworkEncryptionFailure(UNetConnection* Connection)
{
    auto RetVal = Super::ReceivedNetworkEncryptionFailure(Connection);
    LOG_FUN();
    return RetVal;
}

void UMockupGameInstance::PreloadContentForURL(FURL InURL)
{
    Super::PreloadContentForURL(InURL);
    LOG_FUN();
}

class AGameModeBase* UMockupGameInstance::CreateGameModeForURL(FURL InURL, UWorld* InWorld)
{
    auto RetVal = Super::CreateGameModeForURL(InURL, InWorld);
    LOG_FUN();
    return RetVal;
}

void UMockupGameInstance::SetPersistentTravelURL(FURL InURL)
{
    Super::SetPersistentTravelURL(InURL);
    LOG_FUN();
}

TSubclassOf<AGameModeBase> UMockupGameInstance::OverrideGameModeClass(TSubclassOf<AGameModeBase> GameModeClass, const FString& MapName, const FString& Options, const FString& Portal) const
{
    auto RetVal = Super::OverrideGameModeClass(GameModeClass, MapName, Options, Portal);
    LOG_FUN();
    return RetVal;
}

TSubclassOf<UOnlineSession> UMockupGameInstance::GetOnlineSessionClass()
{
    auto RetVal = Super::GetOnlineSessionClass();
    LOG_FUN();
    return RetVal;
}

FName UMockupGameInstance::GetOnlinePlatformName() const
{
    auto RetVal = Super::GetOnlinePlatformName();
    LOG_FUN();
    return RetVal;
}

bool UMockupGameInstance::ClientTravelToSession(int32 ControllerId, FName InSessionName)
{
    auto RetVal = Super::ClientTravelToSession(ControllerId, InSessionName);
    LOG_FUN();
    return RetVal;
}

void UMockupGameInstance::ReturnToMainMenu()
{
    Super::ReturnToMainMenu();
    LOG_FUN();
}

void UMockupGameInstance::RegisterReferencedObject(UObject* ObjectToReference)
{
    Super::RegisterReferencedObject(ObjectToReference);
    LOG_FUN();
}

void UMockupGameInstance::UnregisterReferencedObject(UObject* ObjectToReference)
{
    Super::UnregisterReferencedObject(ObjectToReference);
    LOG_FUN();
}

EReplicationSystem UMockupGameInstance::GetDesiredReplicationSystem(FName InNetDriverDefinition) const
{
    auto RetVal = Super::GetDesiredReplicationSystem(InNetDriverDefinition);
    LOG_FUN();
    return RetVal;
}

void UMockupGameInstance::OnStart()
{
    Super::OnStart();
    LOG_FUN();
}


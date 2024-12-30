#include "MockupLifecycleActorComponent.h"
#include "UObject/ObjectSaveContext.h"
#include "MockupLifecycleLogs.h"
#include "GameFramework/Character.h"


UMockupLifecycleActorComponent::UMockupLifecycleActorComponent()
{
    LOG_FUN_INFO_ALIGN(TEXT("UMockupLifecycleActorComponent::UMockupLifecycleActorComponent()"));
}

UMockupLifecycleActorComponent::UMockupLifecycleActorComponent(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    LOG_FUN();
}



void UMockupLifecycleActorComponent::PostCDOContruct()
{
    Super::PostCDOContruct();
    LOG_PROPERTY();
}

#if WITH_EDITOR
void UMockupLifecycleActorComponent::PostCDOCompiled(const FPostCDOCompiledContext& Context)
{
    Super::PostCDOCompiled(Context);
    LOG_PROPERTY();
}
#endif

void UMockupLifecycleActorComponent::PostLoad()
{
    Super::PostLoad();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::PostInitProperties()
{
    Super::PostInitProperties();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::PostReinitProperties()
{

    Super::PostReinitProperties();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::PostLoadSubobjects( FObjectInstancingGraph* OuterInstanceGraph )
{    
    Super::PostLoadSubobjects(OuterInstanceGraph);
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::PreSave(FObjectPreSaveContext ObjectSaveContext)
{
    Super::PreSave(ObjectSaveContext);
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::PreSaveRoot(FObjectPreSaveRootContext ObjectSaveContext)
{
    Super::PreSaveRoot(ObjectSaveContext);
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::PostSaveRoot(FObjectPostSaveRootContext ObjectSaveContext)
{
    Super::PostSaveRoot(ObjectSaveContext);
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::PreNetReceive()
{
    Super::PreNetReceive();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::PostNetReceive()
{
    Super::PostNetReceive();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::PostRepNotifies()
{
    Super::PostRepNotifies();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::BeginDestroy()
{
    LOG_PROPERTY();
    Super::BeginDestroy();
}

void UMockupLifecycleActorComponent::FinishDestroy()
{
    LOG_PROPERTY();
    Super::FinishDestroy();
}

void UMockupLifecycleActorComponent::OnComponentCreated()
{
    Super::OnComponentCreated();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::InitializeComponent()
{
    Super::InitializeComponent();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::OnRegister()
{
    Super::OnRegister();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::OnUnregister()
{
    LOG_PROPERTY();
    Super::OnUnregister();
}

void UMockupLifecycleActorComponent::BeginPlay()
{
    Super::BeginPlay();
    LOG_PROPERTY();
}

void UMockupLifecycleActorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    LOG_FUN_INFO_ALIGN(*MockupGetEnumString(EndPlayReason));
    Super::EndPlay(EndPlayReason);
}

void UMockupLifecycleActorComponent::PostApplyToComponent()
{
    LOG_PROPERTY();
    Super::PostApplyToComponent();
}

void UMockupLifecycleActorComponent::OnCreatePhysicsState()
{
    LOG_PROPERTY();
    Super::OnCreatePhysicsState();
}

void UMockupLifecycleActorComponent::OnDestroyPhysicsState()
{
    LOG_PROPERTY();
    Super::OnDestroyPhysicsState();
}

void UMockupLifecycleActorComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
    LOG_PROPERTY();
    Super::OnComponentDestroyed(bDestroyingHierarchy);
}

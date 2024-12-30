// MyActor.cpp
#include "MockupLifecycleActor.h"
#include "UObject/ObjectSaveContext.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "MockupLifecycleLogs.h"
#include "MockupLifecycleActorComponent.h"

AMockupLifecycleActor::AMockupLifecycleActor()
{
    LOG_FUN_INFO_ALIGN(TEXT("AMockupLifecycleActor::AMockupLifecycleActor()"));
}

AMockupLifecycleActor::AMockupLifecycleActor(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	MockupLifecycleActorComponent = CreateDefaultSubobject<UMockupLifecycleActorComponent>(TEXT("MockupLifecycleActorComponent"));

    LOG_FUN();
}

void AMockupLifecycleActor::PostCDOContruct()
{
    LOG_PROPERTY_ACTOR();
    Super::PostCDOContruct();
}

#if WITH_EDITOR
void AMockupLifecycleActor::PostCDOCompiled(const FPostCDOCompiledContext& Context)
{
    LOG_PROPERTY_ACTOR();
    Super::PostCDOCompiled(Context);
}
#endif


void AMockupLifecycleActor::PostLoad()
{
    Super::PostLoad();
    LOG_PROPERTY_ACTOR();
}

void AMockupLifecycleActor::PostInitProperties()
{
    Super::PostInitProperties();
    LOG_PROPERTY_ACTOR();
}

void AMockupLifecycleActor::PostReinitProperties()
{

    Super::PostReinitProperties();
    LOG_PROPERTY_ACTOR();
}

void AMockupLifecycleActor::PostLoadSubobjects( FObjectInstancingGraph* OuterInstanceGraph )
{
    LOG_PROPERTY_ACTOR();
    Super::PostLoadSubobjects(OuterInstanceGraph);
}

void AMockupLifecycleActor::PreSave(FObjectPreSaveContext ObjectSaveContext)
{
    LOG_PROPERTY_ACTOR();
    Super::PreSave(ObjectSaveContext);
}

void AMockupLifecycleActor::PreSaveRoot(FObjectPreSaveRootContext ObjectSaveContext)
{
    LOG_PROPERTY_ACTOR();
    Super::PreSaveRoot(ObjectSaveContext);
}

void AMockupLifecycleActor::PostSaveRoot(FObjectPostSaveRootContext ObjectSaveContext)
{
    LOG_PROPERTY_ACTOR();
    Super::PostSaveRoot(ObjectSaveContext);
}

void AMockupLifecycleActor::PreReplication(IRepChangedPropertyTracker & ChangedPropertyTracker)
{
    LOG_PROPERTY_ACTOR();
    Super::PreReplication(ChangedPropertyTracker);
}

void AMockupLifecycleActor::PreReplicationForReplay(IRepChangedPropertyTracker & ChangedPropertyTracker)
{
    LOG_PROPERTY_ACTOR();
    Super::PreReplicationForReplay(ChangedPropertyTracker);
}

void AMockupLifecycleActor::PreNetReceive()
{
    LOG_PROPERTY_ACTOR();
    Super::PreNetReceive();
}

void AMockupLifecycleActor::PostNetReceive()
{
    LOG_PROPERTY_ACTOR();
    Super::PostNetReceive();
}

void AMockupLifecycleActor::PostNetReceiveRole()
{
    LOG_PROPERTY_ACTOR();
    Super::PostNetReceiveRole();
}

void AMockupLifecycleActor::PostNetInit()
{
    LOG_PROPERTY_ACTOR();
    Super::PostNetInit();
}

void AMockupLifecycleActor::PostNetReceiveLocationAndRotation()
{
    LOG_PROPERTY_ACTOR();
    Super::PostNetReceiveLocationAndRotation();
}

void AMockupLifecycleActor::PostNetReceiveVelocity(const FVector& NewVelocity)
{
    LOG_PROPERTY_ACTOR();
    Super::PostNetReceiveVelocity(NewVelocity);
}

void AMockupLifecycleActor::PostNetReceivePhysicState()
{
    LOG_PROPERTY_ACTOR();
    Super::PostNetReceivePhysicState();
}

void AMockupLifecycleActor::PostRepNotifies()
{
    LOG_PROPERTY_ACTOR();
    Super::PostRepNotifies();
}

void AMockupLifecycleActor::BeginDestroy()
{
    LOG_PROPERTY_ACTOR();
    Super::BeginDestroy();
}

void AMockupLifecycleActor::FinishDestroy()
{
    LOG_PROPERTY_ACTOR();
    Super::FinishDestroy();
}


void AMockupLifecycleActor::PreRegisterAllComponents()
{
    Super::PreRegisterAllComponents();
    LOG_PROPERTY_ACTOR();
}

void AMockupLifecycleActor::PostRegisterAllComponents()
{
    Super::PostRegisterAllComponents();
    LOG_PROPERTY_ACTOR();
}

void AMockupLifecycleActor::PostActorCreated()
{
    Super::PostActorCreated();
    LOG_PROPERTY_ACTOR();
}

void AMockupLifecycleActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    LOG_PROPERTY_ACTOR();
}

void AMockupLifecycleActor::PreInitializeComponents()
{
    Super::PreInitializeComponents();
    LOG_PROPERTY_ACTOR();
}

void AMockupLifecycleActor::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    LOG_PROPERTY_ACTOR();
}

void AMockupLifecycleActor::BeginPlay()
{
    Super::BeginPlay();
    LOG_PROPERTY_ACTOR();

	if(HasAuthority())
	{
		if(IsValid(SpawnByActorPos) && IsValid(MockupCharacterClass))
		{
			SpawnDemoActor(MockupCharacterClass, SpawnByActorPos->GetActorLocation());
		}

		if(IsValid(SpawnByCompPos) && IsValid(MockupLifecycleActorComponent->MockupCharacterClass))
		{
			SpawnDemoActor(MockupLifecycleActorComponent->MockupCharacterClass, SpawnByCompPos->GetActorLocation());
		}
	}
}

void AMockupLifecycleActor::SpawnDemoActor(UClass* ClassToSpawn, const FVector& SpawnLocation)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	//SpawnParams.Instigator = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* NewActor = GetWorld()->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	if(IsValid(NewActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("==== Spawned character %s"), *NewActor->GetName());
	}
}

void AMockupLifecycleActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    LOG_FUN_INFO_ALIGN(*MockupGetEnumString(EndPlayReason));
    Super::EndPlay(EndPlayReason);
}


#if WITH_EDITOR
void AMockupLifecycleActor::PreEditChange(FProperty* PropertyThatWillChange)
{
    LOG_FUN();
    Super::PreEditChange(PropertyThatWillChange);
}

void AMockupLifecycleActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    LOG_FUN();
    Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AMockupLifecycleActor::PreEditUndo()
{
    LOG_FUN();
    Super::PreEditUndo();
}

void AMockupLifecycleActor::PostEditUndo()
{
    LOG_FUN();
    Super::PostEditUndo();
}

void AMockupLifecycleActor::PostEditUndo(TSharedPtr<ITransactionObjectAnnotation> TransactionAnnotation)
{
    LOG_FUN();
    Super::PostEditUndo(TransactionAnnotation);
}

void AMockupLifecycleActor::PostEditImport()
{
    LOG_FUN();
    Super::PostEditImport();
}

void AMockupLifecycleActor::PostTransacted(const FTransactionObjectEvent& TransactionEvent)
{
    LOG_FUN();
    Super::PostTransacted(TransactionEvent);
}
#endif


void AMockupLifecycleActor::PrestreamTextures( float Seconds, bool bEnableStreaming, int32 CinematicTextureGroups )
{
    LOG_FUN();
    Super::PrestreamTextures(Seconds, bEnableStreaming, CinematicTextureGroups);
}


void AMockupLifecycleActor::PostRename( UObject* OldOuter, const FName OldName )
{
    LOG_FUN();
    Super::PostRename(OldOuter, OldName);
}

#if WITH_EDITOR
void AMockupLifecycleActor::PostEditMove(bool bFinished)
{
    LOG_FUN();
    Super::PostEditMove(bFinished);
}
#endif
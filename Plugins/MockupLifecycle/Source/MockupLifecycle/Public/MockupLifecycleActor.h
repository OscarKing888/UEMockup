#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MockupLifecycleActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class AMockupLifecycleActor : public AActor
{
    GENERATED_BODY()

public:
	AMockupLifecycleActor();
    AMockupLifecycleActor(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MockupLifecycle")
	TObjectPtr<class UMockupLifecycleActorComponent> MockupLifecycleActorComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MockupLifecycle")
	TSubclassOf<ACharacter> MockupCharacterClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MockupLifecycle")
	TObjectPtr<AActor> SpawnByActorPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MockupLifecycle")
	TObjectPtr<AActor> SpawnByCompPos;

	void SpawnDemoActor(UClass* ClassToSpawn, const FVector& SpawnLocation);


	//~ Begin UObject Interface
	virtual void PostCDOContruct() override;

#if WITH_EDITOR	
	virtual void PostCDOCompiled(const FPostCDOCompiledContext& Context) override;
#endif

    virtual void PostLoad() override;	
	virtual void PostLoadSubobjects( FObjectInstancingGraph* OuterInstanceGraph ) override;
	
	virtual void PreSave(FObjectPreSaveContext ObjectSaveContext) override;
	virtual void PreSaveRoot(FObjectPreSaveRootContext ObjectSaveContext) override;
	virtual void PostSaveRoot(FObjectPostSaveRootContext ObjectSaveContext) override;
	
	virtual void PostInitProperties() override;
	virtual void PostReinitProperties() override;

	virtual void PreNetReceive() override;
	virtual void PostNetReceive() override;
	virtual void PostRepNotifies() override;

	virtual void BeginDestroy() override;
    virtual void FinishDestroy() override;
    //~ End UObject Interface

    //~ Begin AActor Interface
	virtual void PreReplication(IRepChangedPropertyTracker & ChangedPropertyTracker) override;
	virtual void PreReplicationForReplay(IRepChangedPropertyTracker & ChangedPropertyTracker) override;
	virtual void PostNetReceiveRole() override;
	virtual void PostNetInit() override;
	virtual void PostNetReceiveLocationAndRotation() override;
	virtual void PostNetReceiveVelocity(const FVector& NewVelocity) override;
	virtual void PostNetReceivePhysicState() override;

    virtual void PreRegisterAllComponents() override;
    virtual void PostRegisterAllComponents() override;
    virtual void PostActorCreated() override;
    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void PreInitializeComponents() override;
    virtual void PostInitializeComponents() override;

    virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    //~ End AActor Interface

	//~ Begin AActor Editor Interface
#if WITH_EDITOR
	virtual void PreEditChange(FProperty* PropertyThatWillChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual void PreEditUndo() override;
	virtual void PostEditUndo() override;
	virtual void PostEditUndo(TSharedPtr<ITransactionObjectAnnotation> TransactionAnnotation) override;

	virtual void PostEditImport() override;
	virtual void PostTransacted(const FTransactionObjectEvent& TransactionEvent) override;

	virtual void PostEditMove(bool bFinished) override;
#endif

	virtual void PostRename( UObject* OldOuter, const FName OldName ) override;
	//~ End AActor Editor Interface

	virtual void PrestreamTextures( float Seconds, bool bEnableStreaming, int32 CinematicTextureGroups = 0 );
	
};

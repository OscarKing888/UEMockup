#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MockupLifecycleActorComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UMockupLifecycleActorComponent : public UActorComponent
{
    GENERATED_BODY()

public:

	UMockupLifecycleActorComponent();
	UMockupLifecycleActorComponent(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MockupLifecycle")
	TSubclassOf<ACharacter> MockupCharacterClass;
	
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

    //~ Begin UActorComponent Interface
    virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

    virtual void InitializeComponent() override;
    virtual void OnRegister() override;
    virtual void OnUnregister() override;
	
	virtual void OnCreatePhysicsState() override;
	virtual void OnDestroyPhysicsState() override;

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    //~ End UActorComponent Interface

	virtual void PostApplyToComponent() override;
};

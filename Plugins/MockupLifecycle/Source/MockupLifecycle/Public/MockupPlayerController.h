#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MockupPlayerController.generated.h"

UCLASS(Blueprintable, BlueprintType)
class AMockupPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    AMockupPlayerController(const FObjectInitializer& ObjectInitializer);	

	void DumpAllActors(const FString& FlieName);

	UFUNCTION(Exec)
	void DumpAllActorsClient();

	UFUNCTION(Exec)
	void DumpAllActorsServer();

	UFUNCTION(Server, Reliable)
	void Server_DumpAllActors();

	UFUNCTION(Client, Reliable)
	void Client_Log(const FString& Message);

	void ExportActorsToCSV(const FString& FlieName);
	void OpenCSVFileDirectory(const FString& DirectoryPath);


    virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	
	UFUNCTION(Exec)
	void AddPlayerScore();
	
	UFUNCTION(Server, Reliable)
	void Server_AddPlayerScore();

	UFUNCTION(Exec)
	void AddGameScore();
	
	UFUNCTION(Server, Reliable)
	void Server_AddGameScore();
};

#include "MockupPlayerCharacter.h"
#include "MockupLifecycleLogs.h"

AMockupPlayerCharacter::AMockupPlayerCharacter()
{	
	LOG_FUN();
}


void AMockupPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
	LOG_FUN();

}

void AMockupPlayerCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
    LOG_FUN_INFO_ALIGN(*MockupGetEnumString(EndPlayReason));
}

void AMockupPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	LOG_FUN_INFO_ALIGN(IsValid(NewController) ? *NewController->GetPathName() : TEXT("NULL"));
}


void AMockupPlayerCharacter::UnPossessed()
{
	Super::UnPossessed();
	LOG_FUN();
}
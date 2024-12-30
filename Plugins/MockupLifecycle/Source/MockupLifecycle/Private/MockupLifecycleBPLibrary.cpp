// Copyright Epic Games, Inc. All Rights Reserved.

#include "MockupLifecycleBPLibrary.h"
#include "MockupLifecycle.h"

UMockupLifecycleBPLibrary::UMockupLifecycleBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UMockupLifecycleBPLibrary::MockupLifecycleSampleFunction(float Param)
{
	return -1;
}


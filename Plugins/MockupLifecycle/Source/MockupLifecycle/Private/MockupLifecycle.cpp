// Copyright Epic Games, Inc. All Rights Reserved.

#include "MockupLifecycle.h"
#include "MockupLifecycleLogs.h"

#define LOCTEXT_NAMESPACE "FMockupLifecycleModule"

void FMockupLifecycleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	LOG_FILE_LINE();
}

void FMockupLifecycleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	LOG_FILE_LINE();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMockupLifecycleModule, MockupLifecycle)
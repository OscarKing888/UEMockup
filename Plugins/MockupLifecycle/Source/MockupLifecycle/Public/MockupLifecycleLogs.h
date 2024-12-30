// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

template<typename TEnum>
static FString MockupGetEnumString(TEnum Val)
{
	UEnum* EnumPtr = StaticEnum<TEnum>();
	if (!EnumPtr) return FString();

	return EnumPtr->GetDisplayNameTextByValue((uint8)Val).ToString();
}

extern FString MockupGetLogPrefix(const UObject* WorldContextObject);
extern FString MockupGetLogPrefix();

static FString FormatLogString(const FString& Prefix, const FString& FunctionName, const FString& Info, const FString& ObjectPath, const FString& File, int32 Line)
{
    return FString::Printf(TEXT("====%s\t%s\t%s\t%s\t%s:%d"), *Prefix, *FunctionName, *Info, *ObjectPath, *File, Line);
}



#define LOG_FILE_LINE() \
    UE_LOG(LogTemp, Warning, TEXT("%s"), *FormatLogString(MockupGetLogPrefix(), __FUNCTION__, TEXT("\t \t \t "), TEXT(""), __FILE__, __LINE__))

#define LOG_FUN() \
    UE_LOG(LogTemp, Warning, TEXT("%s"), *FormatLogString(MockupGetLogPrefix(this), __FUNCTION__, TEXT("\t \t \t "), this->GetPathName(), __FILE__, __LINE__))

#define LOG_FUN_INFO(InfoCharPtr) \
    UE_LOG(LogTemp, Warning, TEXT("%s"), *FormatLogString(MockupGetLogPrefix(this), __FUNCTION__, InfoCharPtr, this->GetPathName(), __FILE__, __LINE__))


#define LOG_FUN_INFO_ALIGN(InfoCharPtr) \
    UE_LOG(LogTemp, Warning, TEXT("%s"), *FormatLogString(MockupGetLogPrefix(this), __FUNCTION__, *FString::Printf(TEXT("%s%s"), InfoCharPtr, TEXT("\t \t \t ")), this->GetPathName(), __FILE__, __LINE__))

#define LOG_PROPERTY() \
    { \
        FString LogStr = FString::Printf(TEXT("MockupCharacterClass: %s\t \t \t "), \
            MockupCharacterClass.Get() != nullptr ? *MockupCharacterClass->GetName() : TEXT("Null")); \
        LOG_FUN_INFO(*LogStr); \
    }

#define LOG_PROPERTY_ACTOR() \
    { \
        FString LogStr = FString::Printf(TEXT("MockupCharacterClass: %s\t%s\t%s\t%s"), \
            MockupCharacterClass.Get() != nullptr ? *MockupCharacterClass->GetName() : TEXT("Null"), \
            this->IsA<AActor>() ? *MockupGetEnumString(GetLocalRole()) : TEXT(" "), \
            this->IsA<AActor>() ? *MockupGetEnumString(GetRemoteRole()) : TEXT(" "), \
            this->IsA<AActor>() ? (HasAuthority() ? TEXT("Y") : TEXT("N")) : TEXT(" ")); \
        LOG_FUN_INFO(*LogStr); \
    }

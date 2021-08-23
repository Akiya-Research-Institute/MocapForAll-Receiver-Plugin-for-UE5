// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Engine/GameInstance.h"
#include "VMT4UEOscManager.generated.h"

class UVMT4UEStreamingData;
class UUEOSCReceiver;

/**
 * 
 */
UCLASS(BlueprintType)
class VMT4UE_API UVMT4UEOSCManager : public UObject
{
	GENERATED_BODY()
	
public:
    FRWLock RWLock;

	UPROPERTY()
    TMap<int32, UVMT4UEStreamingData*> StreamingDataMap;

	UPROPERTY()
	TArray<UUEOSCReceiver*> OscReceivers;
	
	static UVMT4UEOSCManager* GetInstance();

private:
	static UVMT4UEOSCManager* Instance;
};

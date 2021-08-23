// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UEOSC/Include/UEOSCElement.h"
#include "VMT4UEBlueprintFunctionLibrary.generated.h"

class UVMT4UEStreamingData;

/**
 * 
 */
UCLASS()
class VMT4UE_API UVMT4UEBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    static void OnReceivedVMC(UVMT4UEStreamingData* streamingData, const FName &Address, const TArray<FUEOSCElement> &Data, const FString &SenderIp);
    static TWeakObjectPtr<UVMT4UEStreamingData> GetStreamingData(const int32 Port);

    UFUNCTION(BlueprintCallable, Category = "MocapForAll") static void GetStreamingTrackerTransforms(TMap<int, FTransform>& trackerTransforms, const int port);
};

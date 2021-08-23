// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEOSC/Include/UEOscElement.h"
#include "VMT4UEStreamingData.generated.h"

/**
 *
 */
UCLASS()
class VMT4UE_API UVMT4UEStreamingData : public UObject
{
	GENERATED_BODY()

public:
	FRWLock RWLock;
	TMap<int, FTransform> trackerTransforms;

	UFUNCTION()
	void OnReceived(const FName &Address, const TArray<FUEOSCElement> &Data, const FString &SenderIp);
};

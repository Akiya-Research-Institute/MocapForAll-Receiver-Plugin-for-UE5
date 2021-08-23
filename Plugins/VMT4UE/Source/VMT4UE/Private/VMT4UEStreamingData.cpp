// Fill out your copyright notice in the Description page of Project Settings.

#include "VMT4UEStreamingData.h"
#include "VMT4UEBlueprintFunctionLibrary.h"
#include "UEOSC/Include/UEOSCElement.h"

void UVMT4UEStreamingData::OnReceived(const FName &Address, const TArray<FUEOSCElement> &Data, const FString &SenderIp)
{
	UVMT4UEBlueprintFunctionLibrary::OnReceivedVMC(this, Address, Data, SenderIp);
}

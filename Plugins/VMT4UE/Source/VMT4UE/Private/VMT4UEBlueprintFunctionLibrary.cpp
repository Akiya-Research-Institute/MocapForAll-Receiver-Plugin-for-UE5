// Fill out your copyright notice in the Description page of Project Settings.

#include "VMT4UEBlueprintFunctionLibrary.h"
#include "VMT4UEStreamingData.h"
#include "VMT4UEOSCManager.h"
#include "UEOSC/Include/UEOSCElement.h"
#include "UEOSC/Include/UEOSCReceiver.h"

void UVMT4UEBlueprintFunctionLibrary::OnReceivedVMC(UVMT4UEStreamingData* streamingData, const FName& Address, const TArray<FUEOSCElement>& Data, const FString &SenderIp)
{
	if (streamingData == nullptr)
	{
		return;
	}

    const FString AddressString = Address.ToString();

	if (AddressString == TEXT("/VMT/Room/Unity"))
	{
		if (Data.Num() < 10)
		{
			return;
		}
		int32 Index = 0;

		FRWScopeLock RWScopeLock(streamingData->RWLock, FRWScopeLockType::SLT_Write);

		const auto index = Data[Index++].IntValue;
		const auto enable = Data[Index++].IntValue;
		const auto timeoffset = Data[Index++].FloatValue;
		const auto UnityLocationX = Data[Index++].FloatValue;
		const auto UnityLocationY = Data[Index++].FloatValue;
		const auto UnityLocationZ = Data[Index++].FloatValue;
		const auto UnityRotationX = Data[Index++].FloatValue;
		const auto UnityRotationY = Data[Index++].FloatValue;
		const auto UnityRotationZ = Data[Index++].FloatValue;
		const auto UnityRotationW = Data[Index++].FloatValue;

		FTransform& VMCBone = streamingData->trackerTransforms.FindOrAdd(index);

		VMCBone.SetTranslation(FVector(
			UnityLocationZ * 100.0f,
			UnityLocationX * 100.0f,
			UnityLocationY * 100.0f));

		VMCBone.SetRotation(FQuat(
			UnityRotationZ,
			UnityRotationX,
			UnityRotationY,
			UnityRotationW));
	}
}

TWeakObjectPtr<UVMT4UEStreamingData> UVMT4UEBlueprintFunctionLibrary::GetStreamingData(const int32 Port)
{
	UVMT4UEOSCManager* OSCManager = UVMT4UEOSCManager::GetInstance();
	if (OSCManager == nullptr)
	{
		return nullptr;
	}
	
	{
		// Get
		FRWScopeLock RWScopeLock(OSCManager->RWLock, FRWScopeLockType::SLT_ReadOnly);
		auto StreamingData = OSCManager->StreamingDataMap.Find(Port);
		if (StreamingData != nullptr)
		{
			return *StreamingData;
		}
	}
	{
		// Create
		FRWScopeLock RWScopeLock(OSCManager->RWLock, FRWScopeLockType::SLT_Write);
		auto StreamingData = OSCManager->StreamingDataMap.Find(Port);
		if (StreamingData != nullptr)
		{
			return *StreamingData;
		}
		UVMT4UEStreamingData* NewStreamingData = NewObject<UVMT4UEStreamingData>();

		//FRWScopeLock RWScopeLock2(NewStreamingSkeletalMeshTransform->RWLock, FRWScopeLockType::SLT_Write);
		OSCManager->StreamingDataMap.Emplace(Port, NewStreamingData);

		// Bind Port
		UUEOSCReceiver* OscReceiver = NewObject<UUEOSCReceiver>();
		OscReceiver->OSCReceiveEventDelegate.AddDynamic(NewStreamingData, &UVMT4UEStreamingData::OnReceived);
		OscReceiver->Connect(Port);

		OSCManager->OscReceivers.Add(OscReceiver);

		return NewStreamingData;
	}
	return nullptr;
}

void UVMT4UEBlueprintFunctionLibrary::GetStreamingTrackerTransforms(TMap<int, FTransform>& trackerTransforms, const int port)
{
	auto meshTransforms = GetStreamingData(port);
	trackerTransforms = meshTransforms->trackerTransforms;
}
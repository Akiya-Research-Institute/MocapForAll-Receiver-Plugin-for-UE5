// Fill out your copyright notice in the Description page of Project Settings.

#include "VMT4UEOscManager.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

UVMT4UEOSCManager* UVMT4UEOSCManager::Instance = nullptr;

UVMT4UEOSCManager* UVMT4UEOSCManager::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = NewObject< UVMT4UEOSCManager >();
		check(Instance)
		Instance->AddToRoot();
	}
	return Instance;
}

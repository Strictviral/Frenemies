// Fill out your copyright notice in the Description page of Project Settings.


#include "FrenemiesAssetManager.h"
#include "FrenemiesGameplayTags.h"

UFrenemiesAssetManager& UFrenemiesAssetManager::Get()
{
	check(GEngine);
	UFrenemiesAssetManager* FrenemiesAssetManager = Cast<UFrenemiesAssetManager>(GEngine->AssetManager);
	return *FrenemiesAssetManager;
}

void UFrenemiesAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FFrenemiesGameplayTags::InitializeNativeGameplayTags();
	
}

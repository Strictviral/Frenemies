// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "FrenemiesAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class FRENEMIES_API UFrenemiesAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:

	static UFrenemiesAssetManager& Get();


protected:

	virtual void StartInitialLoading() override;
};

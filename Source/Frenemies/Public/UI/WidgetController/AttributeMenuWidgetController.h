// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/FrenemiesWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class FRENEMIES_API UAttributeMenuWidgetController : public UFrenemiesWidgetController
{
	GENERATED_BODY()

public:
	
	virtual void BindCallbacksToDependencies() override;

	virtual void BroadcastInitialValues() override;
	
	
};

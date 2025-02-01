// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/FrenemiesWidgetController.h"

void UFrenemiesWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UFrenemiesWidgetController::BroadcastInitialValues()
{
}

void UFrenemiesWidgetController::BindCallbacksToDependencies()
{
}

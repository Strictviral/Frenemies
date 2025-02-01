// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/FrenemiesHUD.h"

#include "UI/Widget/FrenemiesUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AFrenemiesHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();

		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AFrenemiesHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC,
	UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass uninitalized, please fill out BP_FrenemiesHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetClass uninitalized, please fill out BP_FrenemiesHUD"));

	//construct overlay widget
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	FrenemiesOverlayUserWidget = Cast<UFrenemiesUserWidget>(Widget);

	///construct overlay widget controller
	const FWidgetControllerParams WidgetControllerParams(PC,PS,ASC,AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	FrenemiesOverlayUserWidget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();
	
	
	Widget->AddToViewport();
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/FrenemiesAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UFrenemiesAttributeSet* FrenemiesAttributeSet = CastChecked<UFrenemiesAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(FrenemiesAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(FrenemiesAttributeSet->GetMaxHealth());
	OnStaminaChanged.Broadcast(FrenemiesAttributeSet->GetStamina());
	OnMaxStaminaChanged.Broadcast(FrenemiesAttributeSet->GetMaxStamina());
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UFrenemiesAttributeSet* FrenemiesAttributeSet = CastChecked<UFrenemiesAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::StaminaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetMaxStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStaminaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::StaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnStaminaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxStaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxStaminaChanged.Broadcast(Data.NewValue);
}

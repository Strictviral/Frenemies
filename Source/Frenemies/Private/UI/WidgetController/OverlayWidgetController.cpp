// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/FrenemiesAbilitySystemComponent.h"
#include "AbilitySystem/FrenemiesAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UFrenemiesAttributeSet* FrenemiesAttributeSet = CastChecked<UFrenemiesAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(FrenemiesAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(FrenemiesAttributeSet->GetMaxHealth());
	OnStaminaChanged.Broadcast(FrenemiesAttributeSet->GetStamina());
	OnMaxStaminaChanged.Broadcast(FrenemiesAttributeSet->GetMaxStamina());
	OnThirstChanged.Broadcast(FrenemiesAttributeSet->GetThirst());
	OnMaxThirstChanged.Broadcast(FrenemiesAttributeSet->GetMaxThirst());
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UFrenemiesAttributeSet* FrenemiesAttributeSet = CastChecked<UFrenemiesAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		}
	);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetStaminaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnStaminaChanged.Broadcast(Data.NewValue);
		}
	);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetMaxStaminaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxStaminaChanged.Broadcast(Data.NewValue);
		}
	);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetThirstAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnThirstChanged.Broadcast(Data.NewValue);
		}
	);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(FrenemiesAttributeSet->GetMaxThirstAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxThirstChanged.Broadcast(Data.NewValue);
		}
	);
	
	Cast<UFrenemiesAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// For example, say that Tag = Message.HealthPotion
				//"Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}




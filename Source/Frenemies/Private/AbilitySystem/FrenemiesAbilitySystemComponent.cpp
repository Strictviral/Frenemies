// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/FrenemiesAbilitySystemComponent.h"

#include "FrenemiesGameplayTags.h"


void UFrenemiesAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UFrenemiesAbilitySystemComponent::EffectApplied);

	const FFrenemiesGameplayTags& GameplayTags = FFrenemiesGameplayTags::Get();

	GEngine->AddOnScreenDebugMessage(-1,
		10.0f,
		FColor::Blue,
		FString::Printf(TEXT("Tag: %s"), *GameplayTags.Attributes_Secondary_AppliedArmor.ToString()));
	
}

void UFrenemiesAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                     const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
	
	
}

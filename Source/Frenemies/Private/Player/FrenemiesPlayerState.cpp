// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FrenemiesPlayerState.h"

#include "AbilitySystem/FrenemiesAbilitySystemComponent.h"
#include "AbilitySystem/FrenemiesAttributeSet.h"

AFrenemiesPlayerState::AFrenemiesPlayerState()
{
	SetNetUpdateFrequency(100.0f);

	AbilitySystemComponent = CreateDefaultSubobject<UFrenemiesAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);


	AttributeSet = CreateDefaultSubobject<UFrenemiesAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.0f);
}

UAbilitySystemComponent* AFrenemiesPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

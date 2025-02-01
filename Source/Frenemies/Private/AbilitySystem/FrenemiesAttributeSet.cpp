// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/FrenemiesAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UFrenemiesAttributeSet::UFrenemiesAttributeSet()
{
	InitHealth(50.0f);
	InitMaxHealth(100.0f);
	InitHunger(100.00f);
	InitMaxHunger(100.0f);
	InitThirst(100.0f);
	InitMaxThirst(100.0f);
	InitStamina(50.0f);
	InitMaxStamina(100.0f);
}

void UFrenemiesAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UFrenemiesAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFrenemiesAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFrenemiesAttributeSet, Hunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFrenemiesAttributeSet, MaxHunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFrenemiesAttributeSet, Thirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFrenemiesAttributeSet, MaxThirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFrenemiesAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFrenemiesAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
}

void UFrenemiesAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFrenemiesAttributeSet, Health, OldMaxHealth);
}


void UFrenemiesAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFrenemiesAttributeSet, Health, OldHealth);
}

void UFrenemiesAttributeSet::OnRep_Hunger(const FGameplayAttributeData& OldHunger) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFrenemiesAttributeSet, Hunger, OldHunger);
}

void UFrenemiesAttributeSet::OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFrenemiesAttributeSet, MaxHunger, OldMaxHunger);
}

void UFrenemiesAttributeSet::OnRep_Thirst(const FGameplayAttributeData& OldThirst) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFrenemiesAttributeSet, Thirst, OldThirst);
}

void UFrenemiesAttributeSet::OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFrenemiesAttributeSet, MaxThirst, OldMaxThirst);
}

void UFrenemiesAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFrenemiesAttributeSet, MaxThirst, OldStamina);
}

void UFrenemiesAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFrenemiesAttributeSet, MaxStamina, OldMaxStamina);
}



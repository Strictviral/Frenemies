// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * FrenemiesGameplayTags
 *
 * Singleton containing native gameplay tags
 */

struct FFrenemiesGameplayTags
{
public:
 static const FFrenemiesGameplayTags& Get() {return GameplayTags;}
 static void InitializeNativeGameplayTags();

 FGameplayTag Attributes_Primary_Strength;
 FGameplayTag Attributes_Primary_Intelligence;
 FGameplayTag Attributes_Primary_Armor;
 FGameplayTag Attributes_Primary_Resilience;
 
 FGameplayTag Attributes_Secondary_AppliedArmor;
 FGameplayTag Attributes_Secondary_MaxHealth;
 FGameplayTag Attributes_Secondary_MaxStamina;
 FGameplayTag Attributes_Secondary_MaxThirst;
 FGameplayTag Attributes_Secondary_MaxHunger;
 FGameplayTag Attributes_Secondary_Insight;
 
 
protected:

 
private:

 static FFrenemiesGameplayTags GameplayTags;
 
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "FrenemiesGameplayTags.h"
#include "GameplayTagsManager.h"

FFrenemiesGameplayTags FFrenemiesGameplayTags::GameplayTags;

void FFrenemiesGameplayTags::InitializeNativeGameplayTags()
{
	/*
	 * Primary attribute tags
	 */
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("Increase the amount of Damage a player does, MaxHealth gained, Ability to Move Objects"));

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"),
		FString("Increases the amount of Insight a Player has"));

	GameplayTags.Attributes_Primary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Armor"),
		FString("Increases the amount of AppliedArmor a Person has"));

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Resilience"),
		FString("Increases the amount of Max Health and Stamina"));


	/*
	 * Secondary attribute tags
	 */
	
	GameplayTags.Attributes_Secondary_AppliedArmor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.AppliedArmor"),
		FString("Reduces damage taken"));

	GameplayTags.Attributes_Secondary_Insight = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Insight"),
		FString("Makes Magical Objects visible and easy to see puzzle pieces, Magic Chests"));

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxHealth"),
		FString("Maximum amount of Health a player can have"));

	GameplayTags.Attributes_Secondary_MaxStamina = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxStamina"),
		FString("Maximum amount of Stamina a player can have"));

	GameplayTags.Attributes_Secondary_MaxThirst = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxThirst"),
		FString("Maximum amount of Thirst a player can have"));

	GameplayTags.Attributes_Secondary_MaxHunger = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxHunger"),
		FString("Maximum amount of Hunger a player can have"));
}

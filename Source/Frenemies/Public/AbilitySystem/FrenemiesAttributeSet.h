// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "FrenemiesAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


/**
 * 
 */
UCLASS()
class FRENEMIES_API UFrenemiesAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UFrenemiesAttributeSet();

	//Replicate Varibales Using this funnction
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(ReplicatedUsing = OnRep_Health, BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UFrenemiesAttributeSet, Health);

	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth, BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UFrenemiesAttributeSet, MaxHealth);

	UPROPERTY(ReplicatedUsing = OnRep_Hunger, BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData Hunger;
	ATTRIBUTE_ACCESSORS(UFrenemiesAttributeSet, Hunger);

	UPROPERTY(ReplicatedUsing = OnRep_MaxHunger, BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData MaxHunger;
	ATTRIBUTE_ACCESSORS(UFrenemiesAttributeSet, MaxHunger);
	
	UPROPERTY(ReplicatedUsing = OnRep_Thirst, BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData Thirst;
	ATTRIBUTE_ACCESSORS(UFrenemiesAttributeSet, Thirst);

	UPROPERTY(ReplicatedUsing = OnRep_MaxThirst, BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData MaxThirst;
	ATTRIBUTE_ACCESSORS(UFrenemiesAttributeSet, MaxThirst);

	UPROPERTY(ReplicatedUsing = OnRep_Stamina, BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UFrenemiesAttributeSet, Stamina);

	UPROPERTY(ReplicatedUsing = OnRep_MaxStamina, BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UFrenemiesAttributeSet, MaxStamina);


	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Hunger(const FGameplayAttributeData& OldHunger) const;

	UFUNCTION()
	void OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger) const;

	UFUNCTION()
	void OnRep_Thirst(const FGameplayAttributeData& OldThirst) const;

	UFUNCTION()
	void OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst) const;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
	
	
	
	
};

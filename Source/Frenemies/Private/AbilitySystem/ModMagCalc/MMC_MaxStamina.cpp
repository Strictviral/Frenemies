// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxStamina.h"

#include "AbilitySystem/FrenemiesAttributeSet.h"
#include "Interface/CombatInterface.h"

UMMC_MaxStamina::UMMC_MaxStamina()
{
	ResilienceDef.AttributeToCapture = UFrenemiesAttributeSet::GetResilienceAttribute();
	ResilienceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	ResilienceDef.bSnapshot = false;

	StrengthDef.AttributeToCapture = UFrenemiesAttributeSet::GetStrengthAttribute();
	StrengthDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	StrengthDef.bSnapshot =false;

	//add Resilience to MMC array of capture Definitions
	RelevantAttributesToCapture.Add(ResilienceDef);
	RelevantAttributesToCapture.Add(StrengthDef);
	
}

float UMMC_MaxStamina::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//Gather tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Resilience = 0;
	float Strength = 0;
	
	GetCapturedAttributeMagnitude(ResilienceDef,Spec,EvaluationParameters, Resilience);
	Resilience = FMath::Max<float>(Resilience, 0.f);

	GetCapturedAttributeMagnitude(StrengthDef,Spec,EvaluationParameters, Resilience);
	Strength = FMath::Max<float>(Strength, 0.f);

	//Get source object of this GameplayEffect
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	return 100.0f + (2.5 * Resilience) + (2.5f * Strength) + (10.0f * PlayerLevel);
}

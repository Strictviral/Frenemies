// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxHealth.h"

#include "AbilitySystem/FrenemiesAttributeSet.h"
#include "Interface/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	ResilienceDef.AttributeToCapture = UFrenemiesAttributeSet::GetResilienceAttribute();
	ResilienceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	ResilienceDef.bSnapshot = false;

	//add Resilience to MMC array of capture Definitions
	RelevantAttributesToCapture.Add(ResilienceDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//Gather tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Resilience = 0;
	GetCapturedAttributeMagnitude(ResilienceDef,Spec,EvaluationParameters, Resilience);
	Resilience = FMath::Max<float>(Resilience, 0.f);

	//Get source object of this GameplayEffect
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	return 100.0f + (2.5 * Resilience) + (10.0f * PlayerLevel);
	
}

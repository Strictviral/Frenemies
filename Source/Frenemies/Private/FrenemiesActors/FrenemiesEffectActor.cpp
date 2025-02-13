// Fill out your copyright notice in the Description page of Project Settings.


#include "FrenemiesActors/FrenemiesEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"



AFrenemiesEffectActor::AFrenemiesEffectActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));

}

void AFrenemiesEffectActor::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void AFrenemiesEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	//get ability system component using unreal engines default function in the Ability system Library
	UAbilitySystemComponent* TargetAbilitySystemComponent =  UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (TargetAbilitySystemComponent == nullptr)
	{
		return;
	}

	check(GameplayEffectClass);
	
	FGameplayEffectContextHandle EffectContextHandle =  TargetAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass,ActorLevel, EffectContextHandle);
	
	const FActiveGameplayEffectHandle ActiveGameplayEffectHandle = TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	const bool bIsInfinte = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if (bIsInfinte && InfiniteEffectRemovalApplicationPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandles.Add(ActiveGameplayEffectHandle, TargetAbilitySystemComponent);
	}
}

void AFrenemiesEffectActor::ApplyMultipleEffectsToTarget(AActor* Target,
	const TArray<TSubclassOf<UGameplayEffect>>& GameplayEffects)
{
	if (!Target || GameplayEffects.Num() == 0)
	{
		return;
	}

	for (const TSubclassOf<UGameplayEffect>& GameplayEffectClass : GameplayEffects)
	{
		ApplyEffectToTarget(Target, GameplayEffectClass);
	}
}

void AFrenemiesEffectActor::OnOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyMultipleEffectsToTarget(TargetActor, InstantGameplayEffects);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyMultipleEffectsToTarget(TargetActor, DurationGameplayEffects);
	}

	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyMultipleEffectsToTarget(TargetActor, InfiniteGameplayEffects);
	}
	
}

void AFrenemiesEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyMultipleEffectsToTarget(TargetActor, InstantGameplayEffects);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyMultipleEffectsToTarget(TargetActor, DurationGameplayEffects);
	}

	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyMultipleEffectsToTarget(TargetActor, InfiniteGameplayEffects);
	}

	// to remove and infinite gameplay effect
	if (InfiniteEffectRemovalApplicationPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if (!IsValid(TargetASC))
		{
			return;
		}
		//Create an array of handles to store the value when we find the infintie gameplayy effect
		TArray<FActiveGameplayEffectHandle> HandleToRemove;
		//search through the targets ability system component to remove the gameplay effect
		for (TTuple<FActiveGameplayEffectHandle, UAbilitySystemComponent*> HandlePair : ActiveEffectHandles)
		{
			if (TargetASC == HandlePair.Value)
			{
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1);
				//add the handle to the array created above
				HandleToRemove.Add(HandlePair.Key);
			}
		}
		//go through the array and delete the key
		for (FActiveGameplayEffectHandle& Handle : HandleToRemove)
		{
			ActiveEffectHandles.FindAndRemoveChecked(Handle);
		}
	}
	
}










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
	
	FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass,1.f, EffectContextHandle);
	
	TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	
}










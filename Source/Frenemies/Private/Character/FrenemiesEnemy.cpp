// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FrenemiesEnemy.h"

#include "AbilitySystem/FrenemiesAbilitySystemComponent.h"
#include "AbilitySystem/FrenemiesAttributeSet.h"

AFrenemiesEnemy::AFrenemiesEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UFrenemiesAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);


	AttributeSet = CreateDefaultSubobject<UFrenemiesAttributeSet>("AttributeSet");
	
}

void AFrenemiesEnemy::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

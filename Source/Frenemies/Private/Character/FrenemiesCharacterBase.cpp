// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FrenemiesCharacterBase.h"


AFrenemiesCharacterBase::AFrenemiesCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AFrenemiesCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AFrenemiesCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}




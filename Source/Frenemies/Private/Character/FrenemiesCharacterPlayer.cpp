// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FrenemiesCharacterPlayer.h"

#include "AbilitySystemComponent.h"
#include "Controller/FrenemiesPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/FrenemiesPlayerState.h"
#include "UI/HUD/FrenemiesHUD.h"

AFrenemiesCharacterPlayer::AFrenemiesCharacterPlayer()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}


void AFrenemiesCharacterPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	//Init ability actor info for the server
	InitAbilityActorInfo();
	
	
}

void AFrenemiesCharacterPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//Init ability actor info for the client
	InitAbilityActorInfo();
}

void AFrenemiesCharacterPlayer::InitAbilityActorInfo()
{
	// Begin Init Ability actor
	AFrenemiesPlayerState* FrenemiesPlayerState = GetPlayerState<AFrenemiesPlayerState>();
	check(FrenemiesPlayerState);
	FrenemiesPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(FrenemiesPlayerState, this);
	AbilitySystemComponent = FrenemiesPlayerState->GetAbilitySystemComponent();
	AttributeSet = FrenemiesPlayerState->GetAttributeSet();

	///player controllers has access tot he HUD, thats why we cna call it from the controller
	if (AFrenemiesPlayerController* FrenemiesPlayerController = Cast<AFrenemiesPlayerController>(GetController()))
	{
		if (AFrenemiesHUD* FrenemiesHUD = Cast<AFrenemiesHUD>(FrenemiesPlayerController->GetHUD()))
		{
			FrenemiesHUD->InitOverlay(FrenemiesPlayerController, FrenemiesPlayerState, AbilitySystemComponent, AttributeSet);
		}
			
	}
	
}

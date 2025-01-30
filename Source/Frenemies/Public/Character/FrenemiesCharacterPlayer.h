// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/FrenemiesCharacterBase.h"
#include "FrenemiesCharacterPlayer.generated.h"

/**
 * 
 */
UCLASS()
class FRENEMIES_API AFrenemiesCharacterPlayer : public AFrenemiesCharacterBase
{
	GENERATED_BODY()
public:
	AFrenemiesCharacterPlayer();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};

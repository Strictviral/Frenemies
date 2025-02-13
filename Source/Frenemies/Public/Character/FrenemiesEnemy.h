// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/FrenemiesCharacterBase.h"
#include "FrenemiesEnemy.generated.h"

/**
 * 
 */
UCLASS()
class FRENEMIES_API AFrenemiesEnemy : public AFrenemiesCharacterBase
{
	GENERATED_BODY()

public:

	AFrenemiesEnemy();

	/*Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	/*Combat Interface*/

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

private:

	
};

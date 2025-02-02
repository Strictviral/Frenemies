// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FrenemiesEffectActor.generated.h"

class UGameplayEffect;


UCLASS()
class FRENEMIES_API AFrenemiesEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AFrenemiesEffectActor();

	
protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

private:

	

};

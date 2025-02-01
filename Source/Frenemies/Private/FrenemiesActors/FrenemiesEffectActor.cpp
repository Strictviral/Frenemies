// Fill out your copyright notice in the Description page of Project Settings.


#include "FrenemiesActors/FrenemiesEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/FrenemiesAttributeSet.h"
#include "Components/SphereComponent.h"


AFrenemiesEffectActor::AFrenemiesEffectActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AFrenemiesEffectActor::BeginPlay()
{
	Super::BeginPlay();

	//call back function fire off in response to something overlapping with our sphere component
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AFrenemiesEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AFrenemiesEffectActor::EndOverlap);
}


void AFrenemiesEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a gameplay effect, for now we are const_cast as a hack!
	if( IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		///Return the attribute set of the other actor that overlaps with us
		const UFrenemiesAttributeSet* FrenemiesAttributeSet = Cast<UFrenemiesAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UFrenemiesAttributeSet::StaticClass()));
		UFrenemiesAttributeSet* MutableFrenemiesAttributeSet = const_cast<UFrenemiesAttributeSet*>(FrenemiesAttributeSet);
		MutableFrenemiesAttributeSet->SetHealth(FrenemiesAttributeSet->GetHealth() + 25.f);
		MutableFrenemiesAttributeSet->SetStamina(FrenemiesAttributeSet->GetStamina() - 25.0f);
		Destroy();
	}
}

void AFrenemiesEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}




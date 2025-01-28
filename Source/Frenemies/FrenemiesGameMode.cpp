// Copyright Epic Games, Inc. All Rights Reserved.

#include "FrenemiesGameMode.h"
#include "FrenemiesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFrenemiesGameMode::AFrenemiesGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

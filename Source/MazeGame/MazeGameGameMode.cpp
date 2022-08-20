// Copyright Epic Games, Inc. All Rights Reserved.

#include "MazeGameGameMode.h"
#include "MazeGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMazeGameGameMode::AMazeGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

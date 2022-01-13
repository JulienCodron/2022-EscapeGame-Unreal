// Copyright Epic Games, Inc. All Rights Reserved.

#include "EscapeGameGameMode.h"
#include "EscapeGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEscapeGameGameMode::AEscapeGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

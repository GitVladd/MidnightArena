// Copyright Epic Games, Inc. All Rights Reserved.

#include "MidnightArenaGameMode.h"
#include "MidnightArena/Controller/MidnightArenaPlayerController.h"
#include "MidnightArena/Character/MidnightArenaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMidnightArenaGameMode::AMidnightArenaGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMidnightArenaPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Character/BP_MidnightArenaCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/Character/BP_MidnightArenaPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
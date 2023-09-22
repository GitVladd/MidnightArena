// Copyright Epic Games, Inc. All Rights Reserved.
#define TRACETYPE_LANDSCAPEONLY ECollisionChannel::ECC_GameTraceChannel1

#include "MidnightArenaPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "MidnightArena/Character/MidnightArenaCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AMidnightArenaPlayerController::AMidnightArenaPlayerController()
{
}

void AMidnightArenaPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AMidnightArenaPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(LookAtInputAction, ETriggerEvent::Triggered, this, &AMidnightArenaPlayerController::OnLookAtInputActionTriggered);

		EnhancedInputComponent->BindAction(CameraZoomInputAction, ETriggerEvent::Triggered, this, &AMidnightArenaPlayerController::OnCameraZoomInputActionTriggered);
		
		// Setup keyboard input events
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &AMidnightArenaPlayerController::OnMoveInputActionTriggered);
	}
}

void AMidnightArenaPlayerController::OnLookAtInputActionTriggered()
{
	FHitResult Hit;
	bool bHitSuccessful = false;

	if (AMidnightArenaCharacter* controlledCharacter = CastChecked< AMidnightArenaCharacter>(GetPawn())) {
		bHitSuccessful = GetHitResultUnderCursor(TRACETYPE_LANDSCAPEONLY, true, Hit);

		controlledCharacter->LookAtLocation(Hit.Location);
	}
}

void AMidnightArenaPlayerController::OnCameraZoomInputActionTriggered(const FInputActionValue& Value)
{
	if (AMidnightArenaCharacter* controlledCharacter = CastChecked<AMidnightArenaCharacter>(GetPawn())) {
		controlledCharacter->CameraZoom(Value.Get<float>());
	}
}

void AMidnightArenaPlayerController::OnMoveInputActionTriggered(const FInputActionValue& Value)
{
	if (AMidnightArenaCharacter* controlledCharacter = CastChecked<AMidnightArenaCharacter>(GetPawn())) {

		FVector2D Axis2DValue = Value.Get<FVector2D>();
		if (Axis2DValue.X != 0) {
			controlledCharacter->MoveAlongCameraAxisX(Axis2DValue.X);

		}
		if (Axis2DValue.Y != 0) {
			controlledCharacter->MoveAlongCameraAxisY(Axis2DValue.Y);
		}
	}
}
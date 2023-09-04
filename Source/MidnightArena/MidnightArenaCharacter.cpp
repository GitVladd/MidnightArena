// Copyright Epic Games, Inc. All Rights Reserved.

#include "MidnightArenaCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

AMidnightArenaCharacter::AMidnightArenaCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 2000.f;
	CameraBoom->SetWorldRotation(FRotator(0.f, -70.f, 90.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AMidnightArenaCharacter::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Replicate current health.
	//DOREPLIFETIME(AMidnightArenaCharacter, CurrentHealth);
}

void AMidnightArenaCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void AMidnightArenaCharacter::CameraZoom(float value)
{
	float newCameraDistance = CameraBoom->TargetArmLength + (value * CameraZoomSpeed);

	newCameraDistance = FMath::Clamp(newCameraDistance, CameraMinDistance, CameraMaxDistance);

	CameraBoom->TargetArmLength = newCameraDistance;
}

void AMidnightArenaCharacter::MoveCharacter(float axisX, float axisY)
{
	auto forwardVector = TopDownCameraComponent->GetForwardVector();
	auto rightVector = TopDownCameraComponent->GetRightVector();
	AddMovementInput(forwardVector, axisY);
	AddMovementInput(rightVector, axisX);
}

void AMidnightArenaCharacter::LookAtLocation(FVector locationToLookAt)
{
	//1
	FRotator rotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), locationToLookAt);

	//2
	//FRotator rotation = UKismetMathLibrary::MakeRotFromX(GetActorLocation() - locationToLookAt);

	FQuat resultQuat(FRotator(0.f, rotation.Yaw, 0.0f));

	SetActorRotation(resultQuat);
}
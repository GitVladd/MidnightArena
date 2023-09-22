// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "MidnightArena/Attribute/MainAttributes/HealthComponent.h"
#include "MidnightArena/Attribute/MainAttributes/ManaComponent.h"
#include "MidnightArena/Attribute/MainAttributes/StaminaComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	//Health Component
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	HealthComponent->SetIsReplicated(true);

	ManaComponent = CreateDefaultSubobject<UManaComponent>(TEXT("ManaComponent"));
	ManaComponent->SetIsReplicated(true);

	StaminaComponent = CreateDefaultSubobject<UStaminaComponent>(TEXT("StaminaComponent"));
	StaminaComponent->SetIsReplicated(true);
}


void ABaseCharacter::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Replicate current health.
	DOREPLIFETIME_CONDITION(ABaseCharacter, HealthComponent, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(ABaseCharacter, ManaComponent, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(ABaseCharacter, StaminaComponent, COND_OwnerOnly);
}

float  ABaseCharacter::TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	HealthComponent->DecreaseCurrentAttribute(DamageTaken);
	return DamageTaken;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


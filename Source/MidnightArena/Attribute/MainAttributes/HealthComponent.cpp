// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "GameFramework/Pawn.h"
#include "MidnightArena/Character/MidnightArenaCharacter.h"
#include <Kismet/GameplayStatics.h>

class MidnightArenaPlayerController;

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	;
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UHealthComponent::IsMaxHealth()
{
	return CurrentAttribute >= TotalMaxAttribute;
}

bool UHealthComponent::IsDead()
{
	return CurrentAttribute <= 0;
}


void UHealthComponent::OnRep_CurrentAttribute()
{
	GetOwner();
	APawn* obj = Cast<APawn>(GetOwner());
	if (obj && obj->IsLocallyControlled())
	{
		//update hud
	}
}
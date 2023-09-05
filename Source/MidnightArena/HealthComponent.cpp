// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "GameFramework/Pawn.h"
#include "MidnightArenaCharacter.h"
#include <Kismet/GameplayStatics.h>

class MidnightArenaPlayerController;

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CurrentHealth = MaxHealth;
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Replicate max health.
	DOREPLIFETIME(UHealthComponent, MaxHealth);

	//Replicate current health.
	DOREPLIFETIME(UHealthComponent, CurrentHealth);
}
// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UHealthComponent::OnCurrentHealthUpdate()
{
    //Client-specific functionality

    if (ACharacter* owner = Cast<ACharacter>(GetOwner()))
    {
        if (owner->IsLocallyControlled()) {
            //Update UI
            /*class MidnightArenaPlayerController* controller = Cast<class MidnightArenaPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
            if (controller)
            {
                controller;
            }*/


            FString healthMessage = FString::Printf(TEXT("You now have %f health remaining."), CurrentHealth);
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);

            if (CurrentHealth <= 0)
            {
                FString deathMessage = FString::Printf(TEXT("You have been killed."));
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, deathMessage);
            }
        }
    }

    //Server-specific functionality
    if (GetOwner()->GetLocalRole() == ROLE_Authority)
    {
        FString healthMessage = FString::Printf(TEXT("%s now has %f health remaining."), *GetFName().ToString(), CurrentHealth);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);
    }

    //Functions that occur on all machines. 
    /*
        Any special functionality that should occur as a result of damage or death should be placed here.
    */
}

void UHealthComponent::OnRep_CurrentHealth()
{
    OnCurrentHealthUpdate();
}

// TO DO
void UHealthComponent::OnMaxHealthUpdate() 
{
    return;
}

void UHealthComponent::OnRep_MaxHealth()
{
    OnMaxHealthUpdate();
}


void UHealthComponent::SetCurrentHealth(float healthValue)
{
    
    if (GetOwner()->GetLocalRole() == ROLE_Authority)
    {
        CurrentHealth = FMath::Clamp(healthValue, 0.f, MaxHealth);
        OnCurrentHealthUpdate();
    }
}

void UHealthComponent::DealDamage(float damage)
{
    if (GetOwner()->GetLocalRole() == ROLE_Authority)
    {
        float NewHealth = CurrentHealth - damage;
        CurrentHealth = FMath::Clamp(NewHealth, 0.f, MaxHealth);
        OnCurrentHealthUpdate();
    }
}

void UHealthComponent::Heal(float HealAmount)
{
    if (GetOwner()->GetLocalRole() == ROLE_Authority)
    {
        float NewHealth = CurrentHealth + HealAmount;
        CurrentHealth = FMath::Clamp(NewHealth, 0.f, MaxHealth);
        OnCurrentHealthUpdate();
    }
}



// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}
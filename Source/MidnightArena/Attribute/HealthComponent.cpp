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
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
void UHealthComponent::OnRep_CurrentAttribute()
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

            FString healthMessage = FString::Printf(TEXT("You now have %f health remaining."), GetCurrentHealth());
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);

            if (GetCurrentHealth() <= 0)
            {
                FString deathMessage = FString::Printf(TEXT("You have been killed."));
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, deathMessage);
            }
        }
    }

    //Server-specific functionality
    if (GetOwner()->GetLocalRole() == ROLE_Authority)
    {
        FString healthMessage = FString::Printf(TEXT("%s now has %f health remaining."), *GetFName().ToString(), GetCurrentHealth());
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);
    }

    //Functions that occur on all machines. 
    /*
        Any special functionality that should occur as a result of damage or death should be placed here.
    */
}


bool UHealthComponent::ServerDealDamage_Validate(float damage) {
    if (damage < 0) {
        return true;
    }
    return false;
}
void UHealthComponent::ServerDealDamage_Implementation(float damage) {
    if (GetOwner()->GetLocalRole() == ROLE_Authority)
    {
        float NewHealth = CurrentAttribute - damage;
        CurrentAttribute = FMath::Clamp(NewHealth, 0.f, TotalMaxAttribute);
        //OnCurrentHealthUpdate();
    }
}


bool UHealthComponent::ServerHeal_Validate(float HealAmount) {
    if (HealAmount < 0) {
        return true;
    }
    return false;
};
void UHealthComponent::ServerHeal_Implementation(float HealAmount) {

    if (GetOwner()->GetLocalRole() == ROLE_Authority)
    {
        float NewHealth = CurrentAttribute + HealAmount;
        CurrentAttribute = FMath::Clamp(NewHealth, 0.f, TotalMaxAttribute);
        //OnCurrentHealthUpdate();
    }
};

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    CurrentTime += DeltaTime;
    if (CurrentTime >= TickRateAttribute) {
        ServerHeal(GetTotalRegenerationHealth());
        CurrentTime = 0;
    }

    // ...
}
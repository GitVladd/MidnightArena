// Fill out your copyright notice in the Description page of Project Settings.


#include "RegenAttributeComponent.h"
#include "AttributeDataTypes.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
URegenAttributeComponent::URegenAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetComponentTickInterval(DEFAULT_ATTRIBUTE_TICK_RATE);

	TotalRegenerationAttribute = BaseRegenerationAttribute;
	// ...
}


// Called when the game starts
void URegenAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URegenAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetOwner()->GetLocalRole() == ROLE_Authority) 
	{
		if (GetComponentTickInterval() == 0) {
			FString errorMessage = FString::Printf(TEXT("TickRate is set to 0. Regen doesnt work"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, errorMessage);
			return;
		}
		IncreaseCurrentAttribute(TotalRegenerationAttribute * GetComponentTickInterval());
	}
}

void URegenAttributeComponent::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	
	DOREPLIFETIME_CONDITION(URegenAttributeComponent, TotalRegenerationAttribute, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(URegenAttributeComponent, BaseRegenerationAttribute, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(URegenAttributeComponent, RegenerationAttributeModifiersList, COND_OwnerOnly);
}

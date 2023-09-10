// Fill out your copyright notice in the Description page of Project Settings.

#include "AttributeComponent.h"
#include "Net/UnrealNetwork.h"
#include "MidnightArena/Attribute/AttributeComponent.h"

// Sets default values for this component's properties
UAttributeComponent::UAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	TotalMaxAttribute = BaseMaxAttribute;
	TotalRegenerationAttribute = BaseRegenerationAttribute;
	CurrentAttribute = TotalMaxAttribute;
	// ...
}

void UAttributeComponent::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UAttributeComponent, TotalMaxAttribute);
	DOREPLIFETIME(UAttributeComponent, BaseMaxAttribute);
	DOREPLIFETIME(UAttributeComponent, MaxAttributeModifiersList);
	DOREPLIFETIME(UAttributeComponent, TotalRegenerationAttribute);
	DOREPLIFETIME(UAttributeComponent, BaseRegenerationAttribute);
	DOREPLIFETIME(UAttributeComponent, RegenerationAttributeModifiersList);
	DOREPLIFETIME(UAttributeComponent, CurrentAttribute);
	DOREPLIFETIME(UAttributeComponent, TickRateAttribute);
	DOREPLIFETIME(UAttributeComponent, CurrentTime);
}

// Called when the game starts
void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
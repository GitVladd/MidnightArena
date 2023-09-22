// Fill out your copyright notice in the Description page of Project Settings.

#include "AttributeComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UAttributeComponent::UAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	TotalMaxAttribute = BaseMaxAttribute;
	CurrentAttribute = TotalMaxAttribute;
	// ...
}

void UAttributeComponent::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(UAttributeComponent, TotalMaxAttribute, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(UAttributeComponent, BaseMaxAttribute, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(UAttributeComponent, MaxAttributeModifiersList, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(UAttributeComponent, CurrentAttribute, COND_OwnerOnly);
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

void UAttributeComponent::IncreaseCurrentAttribute(float Amount)
{
	if (Amount > 0) {
		float NewCurrent = CurrentAttribute + Amount;
		CurrentAttribute = FMath::Clamp(NewCurrent, 0.f, TotalMaxAttribute);
	}

	if (APawn* obj = Cast<APawn>(GetOwner())) {
		if (obj->IsLocallyControlled()) OnCurrentAttributeChange();
	}
}

void UAttributeComponent::DecreaseCurrentAttribute(float Amount)
{
	if (Amount > 0) {
		float NewCurrent = CurrentAttribute - Amount;
		CurrentAttribute = FMath::Clamp(NewCurrent, 0.f, TotalMaxAttribute);
	}

	if (APawn* obj = Cast<APawn>(GetOwner())) {
		if (obj->IsLocallyControlled()) OnCurrentAttributeChange();
	}
}

void UAttributeComponent::OnCurrentAttributeChange() 
{ 
	; 
}

void UAttributeComponent::OnTotalMaxAttributeChange() 
{
	; 
}

void UAttributeComponent::OnRep_TotalMaxAttribute()
{
	;
}

void UAttributeComponent::OnRep_BaseMaxAttribute()
{
	;
}

void UAttributeComponent::OnRep_MaxAttributeModifiersList()
{
	;
}

void UAttributeComponent::OnRep_CurrentAttribute()
{
	;
}

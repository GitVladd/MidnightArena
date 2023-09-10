// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillComponent.h"

// Sets default values for this component's properties
USkillComponent::USkillComponent() :
	SkillType(ESkillType::Passive),
	DamageType(EDamageType::Pure),
	AttributeCostType(EAttributeType::Mana),
	TargetType(ETargetType::NonTarget),
	AttributeAffect(EAttributeAffect::Health),
	AppliedEffect(nullptr),
	AttributeCost(0),
	CastTime(0),
	Cooldown(0)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USkillComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


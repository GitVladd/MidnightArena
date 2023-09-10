// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Effect/Effect.h"
#include "SkillComponent.generated.h"

UENUM()
enum class ESkillType
{
	Active,
	Passive
};

UENUM()
enum class EAttributeType
{
	Mana,
	Health,
	Shield
};

UENUM()
enum class EAttributeAffect
{
	Health,
	Speed,
	Shield,
	Mana,
	Vision
};

UENUM()
enum class EDamageType
{
	Physic,
	Magic,
	Pure,
	Heal
};

UENUM()
enum class ETargetType
{
	Allies,
	Enemies,
	GroundTarget,
	NonTarget
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MIDNIGHTARENA_API USkillComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	ESkillType SkillType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	ETargetType TargetType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	EAttributeType AttributeCostType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	float AttributeCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	EAttributeAffect AttributeAffect;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	EDamageType DamageType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	UEffect * AppliedEffect;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	float CastTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	float Cooldown;
};

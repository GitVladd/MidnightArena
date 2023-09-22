// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillSystemComponent.generated.h"


//
//UINTERFACE()
//class MIDNIGHTARENA_API ISkill : UInterface {
//	GENERATED_BODY()
//	FText Name;
//	FText Desription;
//};
//
//USTRUCT(BlueprintType)
//struct MIDNIGHTARENA_API SkillUseRequirements {
//	GENERATED_BODY()
//	MainAttributeTypeName AttributeType = MainAttributeTypeName::Mana;
//
//	UPROPERTY(Replicated, EditDefaultsOnly)
//		float UnitCost = 0;
//
//};
//
//UCLASS(Abstract)
//class MIDNIGHTARENA_API PassiveSkill : public ISkill {
//	GENERATED_BODY()
//	void ApplyEffect();
//	void RemoveEffect();
//
//	void SkillTick();
//};
//
//UCLASS()
//class MIDNIGHTARENA_API ActiveSkill : public ISkill {
//	GENERATED_BODY()
//	SkillUseRequirements UseRequirements;
//	bool UseSkill();
//};
//



//passive 1 - skills consume mana
//passive 2 - skills consume health
//passive 3 - damage enemies around character
//passive 4 - increase hp regen

//blink
//dash
//fireball
//luzha govna


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MIDNIGHTARENA_API USkillSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillSystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

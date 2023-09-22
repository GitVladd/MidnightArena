// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Components/ActorComponent.h"
#include "AttributeDataTypes.h"
#include "AttributeComponent.generated.h"


// TO DO Make it Not tickable if regeneration == 0 and Modifers are empty


UCLASS(Abstract, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MIDNIGHTARENA_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()
protected:

	UPROPERTY(ReplicatedUsing = OnRep_TotalMaxAttribute, VisibleAnywhere, SimpleDisplay, Category = "Max")
		float TotalMaxAttribute;

	UPROPERTY(ReplicatedUsing = OnRep_BaseMaxAttribute, EditDefaultsOnly, SimpleDisplay, Category = "Max")
		float BaseMaxAttribute = 100.f;
	UPROPERTY(ReplicatedUsing = OnRep_MaxAttributeModifiersList, VisibleAnywhere, Category = "Max|Modifier")
		TArray<FAttributeModifier> MaxAttributeModifiersList;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentAttribute, EditAnywhere, SimpleDisplay, Category = "Current")
		float CurrentAttribute;
public:	
	// Sets default values for this component's properties
	UAttributeComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Category = "Current")
		void IncreaseCurrentAttribute(float Amount);
	UFUNCTION(Category = "Current")
		void DecreaseCurrentAttribute(float Amount);
protected:

	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(Category = "Current")
		virtual void OnCurrentAttributeChange();
	UFUNCTION(Category = "Max")
		virtual void OnTotalMaxAttributeChange();

	UFUNCTION(Category = "Max")
		virtual void OnRep_TotalMaxAttribute();

	UFUNCTION(Category = "Max")
		virtual void OnRep_BaseMaxAttribute();

	UFUNCTION(Category = "Max|Modifier")
		virtual void OnRep_MaxAttributeModifiersList();

	UFUNCTION(Category = "Current")
		virtual void OnRep_CurrentAttribute();
};

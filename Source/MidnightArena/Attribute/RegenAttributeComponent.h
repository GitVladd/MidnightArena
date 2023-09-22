// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.h"
#include "RegenAttributeComponent.generated.h"


UCLASS(Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MIDNIGHTARENA_API URegenAttributeComponent : public UAttributeComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(ReplicatedUsing = OnRep_TotalRegenerationAttribute, VisibleAnywhere, SimpleDisplay, Category = "Regeneration")
		float TotalRegenerationAttribute;

	UPROPERTY(ReplicatedUsing = OnRep_BaseRegenerationAttribute, EditDefaultsOnly, SimpleDisplay, Category = "Regeneration")
		float BaseRegenerationAttribute = 1.f;

	UPROPERTY(ReplicatedUsing = OnRep_RegenerationAttributeModifiersList, VisibleAnywhere, Category = "Regeneration|Modifier")
		TArray<FAttributeModifier> RegenerationAttributeModifiersList;
public:	
	// Sets default values for this component's properties
	URegenAttributeComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(Category = "Regeneration")
		virtual void OnTotalRegenerationAttributeChange() { ; }
	
	UFUNCTION(Category = "Regeneration")
		virtual void OnRep_TotalRegenerationAttribute() { ; }

	UFUNCTION(Category = "Regeneration")
		virtual void OnRep_BaseRegenerationAttribute() { ; }

	UFUNCTION(Category = "Regeneration|Modifier")
		virtual void OnRep_RegenerationAttributeModifiersList() { ; }
};

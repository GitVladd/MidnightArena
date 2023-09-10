// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Components/ActorComponent.h"
#include "AttributeDataTypes.h"
#include "AttributeComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MIDNIGHTARENA_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributeComponent();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	UPROPERTY(ReplicatedUsing = OnRep_TotalMaxAttribute,VisibleAnywhere, SimpleDisplay, Category = "Max")
		float TotalMaxAttribute;

	UPROPERTY(ReplicatedUsing = OnRep_BaseMaxAttribute, EditDefaultsOnly, SimpleDisplay, Category = "Max")
		float BaseMaxAttribute = 100.f;
	UPROPERTY(ReplicatedUsing = OnRep_MaxAttributeModifiersList, VisibleAnywhere, Category = "Max|Modifier")
		TArray<FAttributeModifier> MaxAttributeModifiersList;

	UPROPERTY(ReplicatedUsing = OnRep_TotalRegenerationAttribute, VisibleAnywhere, SimpleDisplay, Category = "Regeneration")
		float TotalRegenerationAttribute;

	UPROPERTY(ReplicatedUsing = OnRep_BaseRegenerationAttribute, EditDefaultsOnly, SimpleDisplay, Category = "Regeneration")
		float BaseRegenerationAttribute;

	UPROPERTY(ReplicatedUsing = OnRep_RegenerationAttributeModifiersList, VisibleAnywhere, Category = "Regeneration|Modifier")
		TArray<FAttributeModifier> RegenerationAttributeModifiersList;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentAttribute, EditDefaultsOnly, SimpleDisplay, Category = "Current")
		float CurrentAttribute;

	UPROPERTY(Replicated, EditDefaultsOnly, SimpleDisplay, Category = "TickRate")
		float TickRateAttribute = 0.5;
	UPROPERTY(Replicated, VisibleAnywhere, SimpleDisplay, Category = "TickRate")
		float CurrentTime;


protected:
	UFUNCTION(Category = "Max")
		void OnRep_TotalMaxAttribute() { return; }
	UFUNCTION(Category = "Max")
		void OnRep_BaseMaxAttribute() { return; }
	UFUNCTION(Category = "Max|Modifier")
		void OnRep_MaxAttributeModifiersList(){ ; }
	UFUNCTION(Category = "Regeneration")
		void OnRep_TotalRegenerationAttribute() { ; }
	UFUNCTION(Category = "Regeneration")
		void OnRep_BaseRegenerationAttribute() { ; }
	UFUNCTION(Category = "Regeneration|Modifier")
		void OnRep_RegenerationAttributeModifiersList(){ ; }
	UFUNCTION(Category = "Current")
		void OnRep_CurrentAttribute() { ; }

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintPure, Category = "Max")
		FORCEINLINE float GetTotalMaxAttribute() const { return TotalMaxAttribute; }

	UFUNCTION(BlueprintPure, Category = "Max")
		FORCEINLINE float GetBaseMaxAttribute() const { return BaseMaxAttribute; }
	UFUNCTION(BlueprintPure, Category = "Max|Modifier")

		FORCEINLINE TArray<FAttributeModifier> GetMaxAttributeModifiersList() const { return MaxAttributeModifiersList; }

	UFUNCTION(BlueprintPure, Category = "Regeneration")
		FORCEINLINE float GetTotalRegenerationAttribute() const { return TotalRegenerationAttribute; }

	UFUNCTION(BlueprintPure, Category = "Regeneration")
		FORCEINLINE float GetBaseRegenerationAttribute() const { return BaseRegenerationAttribute; }

	UFUNCTION(BlueprintPure, Category="Regeneration|Modifier")
		FORCEINLINE TArray<FAttributeModifier> GetRegenerationAttributeModifiersList() const { return RegenerationAttributeModifiersList; }

	UFUNCTION(BlueprintPure, Category = "Current")
		FORCEINLINE float GetCurrentAttribute() const { return CurrentAttribute; }

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*
		UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Health")
		void ServerDealDamage(float damage);
	bool ServerDealDamage_Validate(float damage);
	void ServerDealDamage_Implementation(float damage);


	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Health")
		void ServerHeal(float HealAmount);
	bool ServerHeal_Validate(float HealAmount);
	void ServerHeal_Implementation(float HealAmount);
	*/
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../RegenAttributeComponent.h"
#include "ManaComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MIDNIGHTARENA_API UManaComponent : public URegenAttributeComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UManaComponent();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure, Category = "Mana|Max")
		FORCEINLINE float GetTotalMaxMana() const { return TotalMaxAttribute; }

	UFUNCTION(BlueprintPure, Category = "Mana|Max")
		FORCEINLINE float GetBaseMaxMana() const { return BaseMaxAttribute; }
	UFUNCTION(BlueprintPure, Category = "Mana|Max|Modifier")

		FORCEINLINE TArray<FAttributeModifier> GetMaxManaModifiersList() const { return MaxAttributeModifiersList; }

	UFUNCTION(BlueprintPure, Category = "Mana|Regeneration")
		FORCEINLINE float GetTotalRegenerationMana() const { return TotalRegenerationAttribute; }

	UFUNCTION(BlueprintPure, Category = "Mana|Regeneration")
		FORCEINLINE float GetBaseRegenerationMana() const { return BaseRegenerationAttribute; }

	UFUNCTION(BlueprintPure, Category = "Mana|Regeneration|Modifier")
		FORCEINLINE TArray<FAttributeModifier> GetRegenerationManaModifiersList() const { return RegenerationAttributeModifiersList; }

	UFUNCTION(BlueprintPure, Category = "Mana|Current")
		FORCEINLINE float GetCurrentMana() const { return CurrentAttribute; }

	UFUNCTION(BlueprintCallable)
		void ConsumeMana(float Amount);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OnRep_CurrentAttribute() override;
};

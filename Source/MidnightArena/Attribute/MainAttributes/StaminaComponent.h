// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../RegenAttributeComponent.h"
#include "StaminaComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MIDNIGHTARENA_API UStaminaComponent : public URegenAttributeComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStaminaComponent();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure, Category = "Stamina|Max")
		FORCEINLINE float GetTotalMaxStamina() const { return TotalMaxAttribute; }

	UFUNCTION(BlueprintPure, Category = "Stamina|Max")
		FORCEINLINE float GetBaseMaxStamina() const { return BaseMaxAttribute; }
	UFUNCTION(BlueprintPure, Category = "Stamina|Max|Modifier")

		FORCEINLINE TArray<FAttributeModifier> GetMaxStaminaModifiersList() const { return MaxAttributeModifiersList; }

	UFUNCTION(BlueprintPure, Category = "Stamina|Regeneration")
		FORCEINLINE float GetTotalRegenerationStamina() const { return TotalRegenerationAttribute; }

	UFUNCTION(BlueprintPure, Category = "Stamina|Regeneration")
		FORCEINLINE float GetBaseRegenerationStamina() const { return BaseRegenerationAttribute; }

	UFUNCTION(BlueprintPure, Category = "Stamina|Regeneration|Modifier")
		FORCEINLINE TArray<FAttributeModifier> GetRegenerationStaminaModifiersList() const { return RegenerationAttributeModifiersList; }

	UFUNCTION(BlueprintPure, Category = "Stamina|Current")
		FORCEINLINE float GetCurrentStamina() const { return CurrentAttribute; }

	UFUNCTION(BlueprintCallable)
		void ConsumeStamina(float Amount);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OnRep_CurrentAttribute() override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class MIDNIGHTARENA_API UCharacterHUDWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere);
	float CurrentHealth = 0;
	UPROPERTY(VisibleAnywhere);
	float MaxHealth = 0;

	UPROPERTY(VisibleAnywhere);
	float CurrentMana = 0;
	UPROPERTY(VisibleAnywhere);
	float MaxMana = 0;

	UPROPERTY(VisibleAnywhere);
	float CurrentStamina = 0;
	UPROPERTY(VisibleAnywhere);
	float MaxStamina = 0;

public:
	UFUNCTION(BlueprintCallable)
	void UpdateHealth() { ; }
	UFUNCTION(BlueprintCallable)
	void UpdateMana() { ; }
	UFUNCTION(BlueprintCallable)
	void UpdateStamina() { ; }

	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(float NewCurrentHealth) { if (NewCurrentHealth >= 0) CurrentHealth = NewCurrentHealth; }
	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(float NewMaxHealth) { if (NewMaxHealth >= 0) MaxHealth = NewMaxHealth; } 

	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }
	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintCallable)
	void SetCurrentMana(float NewCurrentMana) { if (NewCurrentMana >= 0) CurrentMana = NewCurrentMana; }
	UFUNCTION(BlueprintCallable)
	void SetMaxMana(float NewMaxMana) { if (NewMaxMana >= 0) MaxMana = NewMaxMana; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetCurrentMana() const { return CurrentMana; }
	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetMaxMana() const { return MaxMana; }

	UFUNCTION(BlueprintCallable)
	void SetCurrentStamina(float NewCurrentStamina) { if (NewCurrentStamina >= 0) CurrentStamina = NewCurrentStamina; }
	UFUNCTION(BlueprintCallable)
	void SetMaxStamina(float NewMaxStamina) { if (NewMaxStamina >= 0) MaxStamina = NewMaxStamina; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetCurrentStamina() const { return CurrentStamina; }
	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetMaxStamina() const { return MaxStamina; }
};

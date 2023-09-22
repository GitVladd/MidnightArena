// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../RegenAttributeComponent.h"
#include "HealthComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MIDNIGHTARENA_API UHealthComponent : public URegenAttributeComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure, Category = "Health|Max")
		FORCEINLINE float GetTotalMaxHealth() const { return TotalMaxAttribute; }

	UFUNCTION(BlueprintPure, Category = "Health|Max")
		FORCEINLINE float GetBaseMaxHealth() const { return BaseMaxAttribute; }
	UFUNCTION(BlueprintPure, Category = "Health|Max|Modifier")

		FORCEINLINE TArray<FAttributeModifier> GetMaxHealthModifiersList() const { return MaxAttributeModifiersList; }

	UFUNCTION(BlueprintPure, Category = "Health|Regeneration")
		FORCEINLINE float GetTotalRegenerationHealth() const { return TotalRegenerationAttribute; }

	UFUNCTION(BlueprintPure, Category = "Health|Regeneration")
		FORCEINLINE float GetBaseRegenerationHealth() const { return BaseRegenerationAttribute; }

	UFUNCTION(BlueprintPure, Category = "Health|Regeneration|Modifier")
		FORCEINLINE TArray<FAttributeModifier> GetRegenerationHealthModifiersList() const { return RegenerationAttributeModifiersList; }

	UFUNCTION(BlueprintPure, Category = "Health|Current")
		FORCEINLINE float GetCurrentHealth() const { return CurrentAttribute; }

	UFUNCTION(BlueprintCallable, Category = "Health")
		bool IsMaxHealth();


	UFUNCTION(BlueprintCallable, Category = "Health")
		bool IsDead();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OnRep_CurrentAttribute() override;
		
};
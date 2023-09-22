// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MidnightArena/Character/BaseCharacter.h"
#include "MidnightArena/Attribute/AttributeDataTypes.h"
#include "Effect.generated.h"

/**
 *
 */
UCLASS(Abstract)
class MIDNIGHTARENA_API UEffect : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly) TArray<FAttributeModifier> OnStartAttributeModifiers;

	ABaseCharacter* EffectOwner;
	ABaseCharacter* EffectInstigator;
public:
	void SetEffectOwner(ABaseCharacter* EffectOwner);

	UFUNCTION(BlueprintCallable) ABaseCharacter* GetEffectOwner() { return EffectOwner; }

	void SetEffectInstigator(ABaseCharacter* EffectInstigator);

	UFUNCTION(BlueprintCallable) ABaseCharacter* GetEffectInstigator() { return EffectInstigator; }
protected:
	UFUNCTION(BlueprintNativeEvent) void OnStartEffect();

	virtual void OnStartEffect_Implementation() { ; }

	UFUNCTION(BlueprintNativeEvent) void OnEndEffect();

	virtual void OnEndEffect_Implementation() { ; }
};


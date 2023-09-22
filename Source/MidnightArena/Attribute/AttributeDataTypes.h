// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AttributeDataTypes.generated.h"

#define DEFAULT_ATTRIBUTE_TICK_RATE 0.1f

UENUM(BlueprintType)
enum class EMainAttributeModifiedProperty : uint8 {
	Current UMETA(DisplayName = "Current"),
	Max UMETA(DisplayName = "Max"),
	Regen UMETA(DisplayName = "Regen")
};


UENUM(BlueprintType)
enum class EAttributeModifierType : uint8 {
	Increment UMETA(DisplayName = "Increment"),
	Multiply UMETA(DisplayName = "Multiply"),
	Divide UMETA(DisplayName = "Divide"),
};


USTRUCT(BlueprintType)
struct FAttributeModifier {
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly) TSubclassOf<class UAttributeComponent> AttributeComponentClass;

	UPROPERTY(EditDefaultsOnly) EAttributeModifierType ModifierType;

	UPROPERTY(EditDefaultsOnly) EMainAttributeModifiedProperty ModifiedProperty;

	UPROPERTY(EditDefaultsOnly) float Amount;

};



UCLASS()
class MIDNIGHTARENA_API UAttributeDataTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AttributeDataTypes.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EMainAttributeTypeName : uint8 {
	Health UMETA(DisplayName = "Health"),
	Mana UMETA(DisplayName = "Mana"),
	Stamina UMETA(DisplayName = "Stamina")
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
	EAttributeModifierType ModifierType;
	float Amount;
	UObject* ModifierInsigator; //?
};




UCLASS()
class MIDNIGHTARENA_API UAttributeDataTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};

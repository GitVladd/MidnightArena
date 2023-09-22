// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Effect.h"
#include "PermanentEffect.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MIDNIGHTARENA_API UPermanentEffect : public UEffect {
	GENERATED_BODY()

protected:
	virtual void OnStartEffect_Implementation() override;
	virtual void OnEndEffect_Implementation() override;
};
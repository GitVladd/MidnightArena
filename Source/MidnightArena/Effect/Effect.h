// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MidnightArena/Character/BaseCharacter.h"
#include "Effect.generated.h"

/**
 * 
 */
UCLASS()
class MIDNIGHTARENA_API UEffect : public UObject
{
	GENERATED_BODY()
private:
	ABaseCharacter* EffectOwner;
public:
	void SetEffectOwner(ABaseCharacter* EffectOwner);
	ABaseCharacter* GetEffectOwner() { return EffectOwner; }
protected:
	virtual void OnStartEffect() { ; }
	virtual void OnEndEffect() { ; }
};


UCLASS()
class MIDNIGHTARENA_API UPermanentEffect : public UEffect {
	GENERATED_BODY()
};


UCLASS()
class MIDNIGHTARENA_API UTemporalEffect : public UEffect {
	GENERATED_BODY()
private:
	float TotalDuration;
	float CurrentDuration;
	float TickTime;
public:
	void TickEffect() { ; }
};
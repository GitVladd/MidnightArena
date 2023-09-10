// Fill out your copyright notice in the Description page of Project Settings.


#include "Effect.h"

void UEffect::SetEffectOwner(ABaseCharacter* effectOwner)
{
	if (!IsValid(effectOwner)) return;
	
	if (IsValid(EffectOwner)) return;

	EffectOwner = effectOwner;
}

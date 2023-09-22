// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (OverheadText) {
		OverheadText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRols(APawn* Pawn)
{
	FString localRole = *UEnum::GetDisplayValueAsText(Pawn->GetLocalRole()).ToString();
	FString remoteRole = *UEnum::GetDisplayValueAsText(Pawn->GetRemoteRole()).ToString();

	FString rolesConcat = FString::Printf(TEXT("Local Role: %s, Remote Role: %s"), *localRole, *remoteRole);
	SetDisplayText(rolesConcat);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Effect.h"
#include "MidnightArena/Attribute/AttributeDataTypes.h"
#include "TemporalEffect.generated.h"

UCLASS(Blueprintable, BlueprintType)
class MIDNIGHTARENA_API UTemporalEffect : public UEffect/*, public FTickableGameObject*/
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)  float TickRate;
	UPROPERTY(VisibleAnywhere) float CurrentTime;
	UPROPERTY(EditDefaultsOnly) float EffectDuration;
	UPROPERTY(EditDefaultsOnly)  bool bIsTickable;

	UPROPERTY(EditDefaultsOnly) TArray<FAttributeModifier> OnTickAttributeModifiers;
public:
	UTemporalEffect();
	//void Tick(float DeltaTime) override;
	//bool IsTickable() const override;
	//bool IsTickableInEditor() const override;
	//bool IsTickableWhenPaused() const override;
	//TStatId GetStatId() const override;

	UFUNCTION(BlueprintNativeEvent) void OnTickEffect();

	virtual void OnTickEffect_Implementation();
};

#include "TemporalEffect.h"

UTemporalEffect::UTemporalEffect()
{
    TickRate = DEFAULT_ATTRIBUTE_TICK_RATE;
    bIsTickable = true;

    CurrentTime = 0.f;
    EffectDuration = 0.f;
}
//
//void UTemporalEffect::Tick(float DeltaTime)
//{
//    OnTickEffect();
//}
//bool UTemporalEffect::IsTickable() const
//{
//    return bIsTickable;
//}
//
//bool UTemporalEffect::IsTickableInEditor() const
//{
//    return false;
//}
//
//bool UTemporalEffect::IsTickableWhenPaused() const
//{
//    return false;
//}
//
//TStatId UTemporalEffect::GetStatId() const
//{
//    return TStatId();
//}

void UTemporalEffect::OnTickEffect_Implementation() {
    ;
}
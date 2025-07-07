#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    MaxHealth = 100.f;
    CurrentHealth = MaxHealth;
}

void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    CurrentHealth = MaxHealth;
}

void UHealthComponent::TakeDamage(float DamageAmount)
{
    if (IsDead() || DamageAmount <= 0.f) return;

    CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth);
    OnHealthChanged.Broadcast(CurrentHealth);

    if (CurrentHealth <= 0.f)
    {
        OnDeath.Broadcast();
    }
}

void UHealthComponent::Heal(float HealAmount)
{
    if (IsDead() || HealAmount <= 0.f) return;

    CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, 0.f, MaxHealth);
    OnHealthChanged.Broadcast(CurrentHealth);
}

bool UHealthComponent::IsDead() const
{
    return CurrentHealth <= 0.f;
}


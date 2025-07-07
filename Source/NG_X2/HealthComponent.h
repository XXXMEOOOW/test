#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

// Делегат: изменение здоровья
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);

// Делегат: смерть
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class NG_X2_API UHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UHealthComponent();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
    float MaxHealth;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
    float CurrentHealth;

public:
    UFUNCTION(BlueprintCallable, Category = "Health")
    void TakeDamage(float DamageAmount);

    UFUNCTION(BlueprintCallable, Category = "Health")
    void Heal(float HealAmount);

    UFUNCTION(BlueprintCallable, Category = "Health")
    bool IsDead() const;

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnHealthChangedSignature OnHealthChanged;

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnDeathSignature OnDeath;
};

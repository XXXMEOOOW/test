#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HealthComponent.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class NG_X2_API AEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AEnemyCharacter();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UHealthComponent* HealthComponent;

    UFUNCTION()
    void OnDeath();

    UFUNCTION()
    void OnHealthChanged(float NewHealth);

    UFUNCTION(BlueprintCallable)
    void AttackPlayer();

    FTimerHandle AttackTimer;

    AActor* PlayerRef;

    UPROPERTY(EditAnywhere, Category = "Combat")
    float AttackRange = 300.0f;

    UPROPERTY(EditAnywhere, Category = "Combat")
    float AttackCooldown = 2.0f;

    void TryAttack();
};

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

UCLASS()
class NG_X2_API AEnemyAIController : public AAIController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    void StartPatrol();

protected:
    UFUNCTION()
    void MoveToNextPatrolPoint();

    int32 CurrentPatrolIndex;

    UPROPERTY(EditAnywhere, Category = "AI")
    TArray<AActor*> PatrolPoints;

    FTimerHandle PatrolTimer;
};

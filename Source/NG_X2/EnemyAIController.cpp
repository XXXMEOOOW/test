#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Engine/TargetPoint.h"


void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    // ���� ��� ���������� ����� �� ������
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), PatrolPoints);

    CurrentPatrolIndex = 0;
    StartPatrol();
}

void AEnemyAIController::StartPatrol()
{
    MoveToNextPatrolPoint();
}

void AEnemyAIController::MoveToNextPatrolPoint()
{
    if (PatrolPoints.Num() == 0) return;

    MoveToActor(PatrolPoints[CurrentPatrolIndex]);

    CurrentPatrolIndex = (CurrentPatrolIndex + 1) % PatrolPoints.Num();

    // ������� ����� 3 �������
    GetWorld()->GetTimerManager().SetTimer(PatrolTimer, this, &AEnemyAIController::MoveToNextPatrolPoint, 3.0f, false);
}

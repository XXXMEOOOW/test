#include "EnemyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyAIController.h"
#include "NG_X2Character.h"

AEnemyCharacter::AEnemyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

void AEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (HealthComponent)
    {
        HealthComponent->OnDeath.AddDynamic(this, &AEnemyCharacter::OnDeath);
        HealthComponent->OnHealthChanged.AddDynamic(this, &AEnemyCharacter::OnHealthChanged);
    }

    PlayerRef = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    GetWorldTimerManager().SetTimer(AttackTimer, this, &AEnemyCharacter::TryAttack, 1.0f, true);
}

void AEnemyCharacter::OnDeath()
{
    AAIController* AI = Cast<AAIController>(GetController());
    if (AI) AI->UnPossess();

    //Destroy();
}

void AEnemyCharacter::OnHealthChanged(float NewHealth)
{
    UE_LOG(LogTemp, Log, TEXT("Enemy health: %.1f"), NewHealth);
}

void AEnemyCharacter::TryAttack()
{
    if (!PlayerRef || HealthComponent->IsDead()) return;

    float Dist = FVector::Dist(GetActorLocation(), PlayerRef->GetActorLocation());
    if (Dist <= AttackRange)
    {
        AttackPlayer();
    }
}

void AEnemyCharacter::AttackPlayer()
{
    UE_LOG(LogTemp, Warning, TEXT("Enemy attacks!"));

    // Можно кастомную анимацию, эффекты, и т.д.
    // Здесь просто урон через HealthComponent
    if (ACharacter* PlayerChar = Cast<ACharacter>(PlayerRef))
    {
        UHealthComponent* PlayerHealth = PlayerChar->FindComponentByClass<UHealthComponent>();
        if (PlayerHealth)
        {
            PlayerHealth->TakeDamage(10.0f);
        }
    }
}

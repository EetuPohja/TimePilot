// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

#include "Dbg.h"
#include "Components/SphereComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "VisualLogger/VisualLoggerDebugSnapshotInterface.h"


// Sets default values
AEnemyBase::AEnemyBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	m_pCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	m_pCollision->SetupAttachment(RootComponent);
	m_pCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	m_pCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	m_pCollision->SetNotifyRigidBodyCollision(true);
	m_pCollision->SetGenerateOverlapEvents(true);
	m_pCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::OnBeginOverlap);

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_pMesh->SetupAttachment(RootComponent);

	m_pMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement Component"));
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float AEnemyBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	if (!m_DamageParams.bCanTakeDamage) return  0.0f;

	const auto* pDT = Cast<UDamageTypeBase>(DamageEvent.DamageTypeClass->GetDefaultObject());
	if (nullptr == pDT || !m_DamageParams.aRespondsToDamageTypes.Contains(pDT->GetDamageID())) return  0.0f;

	if (m_DamageParams.fHealth > 0.0f)
	{
		m_DamageParams.fHealth = FMath::Clamp(m_DamageParams.fHealth - DamageAmount, 0.0f, 100000.f);
		if(m_DamageParams.fHealth > KINDA_SMALL_NUMBER)
			TickAfterDamage(DamageAmount);
		else
			BeginDestroyEnemy();

		return DamageAmount;
	}

	BeginDestroyEnemy();
	return  DamageAmount;
}

void AEnemyBase::OnBeginOverlap(UPrimitiveComponent* ThisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}



#if ENABLE_VISUAL_LOG
// void AEnemyBase::GrabDebugSnapshot(FVisualLogEntry* Snapshot) const
// {
// 	IVisualLoggerDebugSnapshotInterface::GrabDebugSnapshot(Snapshot);
// }
#endif
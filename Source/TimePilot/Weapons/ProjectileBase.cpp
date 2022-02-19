// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/ProjectileBase.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectileBase::AProjectileBase()
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
	m_pCollision->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBase::OnBeginOverlap);

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_pMesh->SetupAttachment(RootComponent);

	m_pProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement Component"));
	m_pProjectileMovementComponent->InitialSpeed = m_ProjectileProperties.fVelocity;
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectileBase::SetupProjectile(const FVector vNormalisedTraj, const FVector vPlayerVelocity)
{
	m_pProjectileMovementComponent->SetVelocityInLocalSpace(vNormalisedTraj * m_ProjectileProperties.fVelocity + vPlayerVelocity);
}

void AProjectileBase::OnBeginOverlap(UPrimitiveComponent* ThisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}


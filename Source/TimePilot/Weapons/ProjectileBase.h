// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTypes/DamageTypeBase.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileBase.generated.h"

USTRUCT(BlueprintType)
struct FprojectileProperties
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fTTL = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fVelocity = 1000.0f;
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TSubclassOf<class MySpecialThingIMade>		//Allows drag&drop of this or derived classes in editor.

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UDamageTypeBase> DamageType;
};


USTRUCT(BlueprintType)
struct FProjectileFX
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<class UNiagaraSystem> pImpactVFX = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<class USoundCue> pImpactSFX = nullptr;
};

UCLASS()
class TIMEPILOT_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetupProjectile(const FVector vNormalisedTraj, const FVector vPlayerVelocity);

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* ThisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// ---------------------------------
	// PROPERTIES
	// ---------------------------------

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UProjectileMovementComponent* m_pProjectileMovementComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class USphereComponent* m_pCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UStaticMeshComponent* m_pMesh;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Projectile Settings")
	FprojectileProperties m_ProjectileProperties;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Projectile Settings")
	FProjectileFX m_ProjectileFX;
};

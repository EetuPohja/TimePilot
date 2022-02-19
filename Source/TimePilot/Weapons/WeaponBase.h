// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponBase.generated.h"


USTRUCT(BlueprintType)
struct FWeaponProperties
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fBulletsPerShot = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fFireDelay = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AProjectileBase> pProjectile;
};

USTRUCT(BlueprintType)
struct FWeaponFX
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<class UNiagaraSystem> pMuzzleFlash = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<class USoundCue> pAudio_Fire = nullptr;
};

UCLASS(BlueprintType, Blueprintable)
class TIMEPILOT_API UWeaponBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponBase();

	// --------------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Fire(const FTransform& SocketTransform);

	UFUNCTION(BlueprintCallable)
	FWeaponProperties GetWeaponProperties() const { return m_WeaponProperties; }

	// --------------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Weapon Properties")
	FWeaponProperties m_WeaponProperties;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Weapon Properties")
	FWeaponFX m_WeaponFX;
};

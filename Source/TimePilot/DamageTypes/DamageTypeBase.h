// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "DamageTypeBase.generated.h"

UENUM(BlueprintType)
enum class EDamageId : uint8
{
	BASE,
	PLAYER_GUN,
	PLAYER_MISSILE,
	SOPWITH_GUN,
	LASER_GUN
};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class TIMEPILOT_API UDamageTypeBase : public UDamageType
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	EDamageId GetDamageID() const {return m_iDamageID; }

	UFUNCTION(BlueprintCallable)
	float GetBaseDamage() const { return m_fDamageAmount; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	EDamageId m_iDamageID = EDamageId::BASE;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float m_fDamageAmount = 1.0f;
};

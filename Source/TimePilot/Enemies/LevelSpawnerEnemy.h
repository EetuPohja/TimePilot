// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LevelSpawnerEnemy.generated.h"

// This class does not need to be modified.
UINTERFACE()
class ULevelSpawnerEnemy : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TIMEPILOT_API ILevelSpawnerEnemy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetLevelSpawnControllerRef(class ALevelSpawner* pSpawnController);
	virtual void SetLevelSpawnControllerRef_Implementation(class ALevelSpawner* pSpawnController) {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PreLevelEnter();
	virtual void PreLevelEnter_Implementation() {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PreLevelExit();
	virtual void PreLevelExit_Implementation() {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LevelEnter();
	virtual void LevelEnter_Implementation() {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LevelExit();
	virtual void LevelExit_Implementation() {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PlayerHasDied();
	virtual void PlayerHasDied_Implementation() {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetEventUID(const int iUID);
	virtual void SetEventUID_Implementation(const int iUID) {}
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TP2K_Player.generated.h"

UCLASS()
class TIMEPILOT_API ATP2K_Player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATP2K_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// -------------------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void StartFireGun();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void StopFireGun();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void StartFireMissile();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void StopFireMissile();

	// --------------------------------------------------------------------------------------------

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties | Weapons")
	TArray<TSubclassOf<class UWeaponBase>> m_aGuns;
};

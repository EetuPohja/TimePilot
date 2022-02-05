// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tests/AutomationTestSettings.h"
#include "TP2K_PlayerController.generated.h"

USTRUCT(BlueprintType)
struct FCurrentInputValues
{
	GENERATED_BODY()
	/** Left Stick throw values: Right,Forward,Zero **/
	UPROPERTY(BlueprintReadWrite)
	FVector vLeftStick;

	/** Left Trigger value **/
	UPROPERTY(BlueprintReadWrite)
	float fThrust;

	/** Time Seconds for last use of right trigger **/
	UPROPERTY(BlueprintReadWrite)
	float fLastThrustSeconds;
};


/**
 * 
 */
UCLASS()
class TIMEPILOT_API ATP2K_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATP2K_PlayerController();

	// ----------------------------------------------------------------------------------------------------------------

	virtual  void SetupInputComponent() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual  void BeginPlay() override;

	// ----------------------------------------------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	FVector GetLeftStick_Raw() const;
	
	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	FVector GetLeftStick_Scaled() const;
	
	// ----------------------------------------------------------------------------------------------------------------
protected:
	void MoveForward(float fValue);
	void MoveRight(float fValue);
	void Thrust(float fValue);

	void PressActionButtonA();
	void PressActionButtonB();
	void PressActionButtonX();
	void PressActionButtonY();
	void PressActionButtonTL();
	
	void ReleaseActionButtonA();
	void ReleaseActionButtonB();
	void ReleaseActionButtonX();
	void ReleaseActionButtonY();
	void ReleaseActionButtonTL();

	// ----------------------------------------------------------------------------------------------------------------

	UPROPERTY(BlueprintReadWrite)
	FCurrentInputValues m_CurrentInput;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TP2K_Hud.generated.h"

/**
 * 
 */
UCLASS()
class TIMEPILOT_API ATP2K_Hud : public AHUD
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Display")
	void ShowInGameHUD();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Display")
	void HideInGameHUD();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Display")
	void HideInGameHUDInstant();
};

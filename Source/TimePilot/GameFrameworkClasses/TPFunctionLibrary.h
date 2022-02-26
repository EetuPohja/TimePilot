// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TPFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class TIMEPILOT_API UTPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Rendering | Helper")
	static  bool IsInFrustrum(const class AActor* Actor) { return  true; };
	
	UFUNCTION(BlueprintCallable, Category = "Rendering | Helper")
	static  bool PosIsInFrustrum(UObject* WorldContextObject, const FVector& vPos) { return true; };

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject", CallableWithoutWorldContext), Category="HUD|Util")
	static  void ScreenPosFromWorldPos(UObject* WorldContextObject, const FVector& vWorldPos, const FVector& vScreenScale, FVector2D& vScreenPos, float& fRotAngleDegrees, bool &bOnScreen) {};

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject", CallableWithoutWorldContext), Category="HUD|Util")
	static  void EnemyIndicatorScale(UObject* WorldContextObject, const FVector& vWorldPos, float& fScale) {};
};

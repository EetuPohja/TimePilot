// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelSpawner.generated.h"

UCLASS()
class TIMEPILOT_API ALevelSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// -------------------------------------------------------------------------------------------------------------
	// INTERFACE	
	// -------------------------------------------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, Category = "Level Spawner")
	void AddActorToTrackingList(AActor* pActor);
	
	UFUNCTION(BlueprintCallable, Category = "Level Spawner")
	void RemoveActorFromTrackingList(const AActor* pActor);

	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Level Spawner")
	void EventTriggered(const int iEventID);

	// -------------------------------------------------------------------------------------------------------------
	// PROPERTIES	
	// -------------------------------------------------------------------------------------------------------------

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Properties")
	TSet<class AActor*> m_aLevelControllerActors;
};

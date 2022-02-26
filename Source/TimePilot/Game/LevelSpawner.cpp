// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/LevelSpawner.h"

#include "Dbg.h"

// Sets default values
ALevelSpawner::ALevelSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelSpawner::AddActorToTrackingList(AActor* pActor)
{
	if(!m_aLevelControllerActors.Contains(pActor)) m_aLevelControllerActors.Add(pActor);
}

void ALevelSpawner::RemoveActorFromTrackingList(const AActor* pActor)
{
	if (nullptr == pActor)
	{
		// UDbg::LOG_ERROR_STR("RemoveActorFromTrackingList called with nullptr!"); return;
	}

	if(m_aLevelControllerActors.Contains(pActor))
	{
		m_aLevelControllerActors.Remove(pActor);
		m_aLevelControllerActors.Shrink();
	}
}
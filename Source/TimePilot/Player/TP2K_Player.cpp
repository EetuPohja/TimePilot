// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TP2K_Player.h"

// Sets default values
ATP2K_Player::ATP2K_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATP2K_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATP2K_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATP2K_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


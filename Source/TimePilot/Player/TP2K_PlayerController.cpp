// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TP2K_PlayerController.h"

ATP2K_PlayerController::ATP2K_PlayerController()
{
	bShowMouseCursor = false;
}

void ATP2K_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &ATP2K_PlayerController::MoveRight);
	InputComponent->BindAxis("MoveForward", this, &ATP2K_PlayerController::MoveForward);
	InputComponent->BindAxis("LeftTrigger", this, &ATP2K_PlayerController::Thrust);
}

void ATP2K_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ATP2K_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

FVector ATP2K_PlayerController::GetLeftStick_Raw() const
{
	return m_CurrentInput.vLeftStick;
}

FVector ATP2K_PlayerController::GetLeftStick_Scaled() const
{
	return  m_CurrentInput.vLeftStick * m_CurrentInput.fThrust;
}

void ATP2K_PlayerController::MoveForward(float fValue)
{
	m_CurrentInput.vLeftStick.Y = fValue;
}

void ATP2K_PlayerController::MoveRight(float fValue)
{
	m_CurrentInput.vLeftStick.X = fValue;
}

void ATP2K_PlayerController::Thrust(float fValue)
{
	m_CurrentInput.fThrust = fValue;
}

void ATP2K_PlayerController::PressActionButtonA()
{
}

void ATP2K_PlayerController::PressActionButtonB()
{
}

void ATP2K_PlayerController::PressActionButtonX()
{
}

void ATP2K_PlayerController::PressActionButtonY()
{
}

void ATP2K_PlayerController::PressActionButtonTL()
{
}

void ATP2K_PlayerController::ReleaseActionButtonA()
{
}

void ATP2K_PlayerController::ReleaseActionButtonB()
{
}

void ATP2K_PlayerController::ReleaseActionButtonX()
{
}

void ATP2K_PlayerController::ReleaseActionButtonY()
{
}

void ATP2K_PlayerController::ReleaseActionButtonTL()
{
}

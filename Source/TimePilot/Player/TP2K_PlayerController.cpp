// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TP2K_PlayerController.h"

#include "TP2K_Player.h"
#include "TP2K_Types.h"

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

	InputComponent->BindAction("ActionButtonA", IE_Pressed, this, &ATP2K_PlayerController::PressActionButtonA).bExecuteWhenPaused = true;
	InputComponent->BindAction("ActionButtonA", IE_Released, this, &ATP2K_PlayerController::ReleaseActionButtonA).bExecuteWhenPaused = true;
	
	InputComponent->BindAction("ActionButtonB", IE_Pressed, this, &ATP2K_PlayerController::PressActionButtonB).bExecuteWhenPaused = true;
	InputComponent->BindAction("ActionButtonB", IE_Released, this, &ATP2K_PlayerController::ReleaseActionButtonB).bExecuteWhenPaused = true;
	
	InputComponent->BindAction("ActionButtonX", IE_Pressed, this, &ATP2K_PlayerController::PressActionButtonX).bExecuteWhenPaused;
	InputComponent->BindAction("ActionButtonX", IE_Released, this, &ATP2K_PlayerController::ReleaseActionButtonX).bExecuteWhenPaused;
	
	InputComponent->BindAction("ActionButtonY", IE_Pressed, this, &ATP2K_PlayerController::PressActionButtonY).bExecuteWhenPaused;
	InputComponent->BindAction("ActionButtonY", IE_Released, this, &ATP2K_PlayerController::ReleaseActionButtonY).bExecuteWhenPaused;
}

void ATP2K_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ATP2K_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	m_CurrentInput.fLastThrustSeconds = GetWorld()->GetTimeSeconds();
}

FVector ATP2K_PlayerController::GetLeftStick_Raw() const
{
	return m_CurrentInput.vLeftStick;
}

FVector ATP2K_PlayerController::GetLeftStick_Scaled() const
{
	return  m_CurrentInput.vLeftStick * m_CurrentInput.fThrust;
}

float ATP2K_PlayerController::GetThrustValue() const
{
	return m_CurrentInput.fThrust;
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

	if(fValue > 0.1f)
	{
		const float fTime = GetWorld()->GetTimeSeconds();
		if(fTime - m_CurrentInput.fLastThrustSeconds > s_fNewThrustDetectedSeconds) OnPlayerThrust.Broadcast();
		m_CurrentInput.fLastThrustSeconds = fTime;
	}
}

void ATP2K_PlayerController::PressActionButtonA()
{
	auto* pPlayer = Cast<ATP2K_Player>(GetPawn());
	if (nullptr != pPlayer) pPlayer->StartFireGun();
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
	auto* pPlayer = Cast<ATP2K_Player>(GetPawn());
	if (nullptr != pPlayer) pPlayer->StopFireGun();
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

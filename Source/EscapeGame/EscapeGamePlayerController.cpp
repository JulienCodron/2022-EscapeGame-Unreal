// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeGamePlayerController.h"
#include "RestartWidget.h"
#include "LifeUserWidget.h"


void AEscapeGamePlayerController::UpdateLifePercent(float Value)
{
	if (LifeWidget != nullptr)
	{
		LifeWidget->UpdateLifePercent(Value);
	}
}

void AEscapeGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (BP_LifeWidget != nullptr)
	{
		LifeWidget = CreateWidget<ULifeUserWidget>(this, BP_LifeWidget);
		LifeWidget->AddToViewport();
	}
}

void AEscapeGamePlayerController::ShowRestartWidget()
{
	if (BP_RestartWidget != nullptr)
	{
		SetPause(true);
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
		RestartWidget = CreateWidget<URestartWidget>(this, BP_RestartWidget);
		RestartWidget->AddToViewport();
	}

	if (LifeWidget != nullptr)
	{
		LifeWidget->RemoveFromViewport();
	}
}

void AEscapeGamePlayerController::HideRestartWidget()
{
	if (RestartWidget != nullptr)
	{
		RestartWidget->RemoveFromParent();
		RestartWidget->Destruct();

		SetPause(false);
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
	
	if (LifeWidget != nullptr)
	{
		LifeWidget = CreateWidget<ULifeUserWidget>(this, BP_LifeWidget);
		LifeWidget->AddToViewport();
	}
}
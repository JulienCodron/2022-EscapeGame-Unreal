// Fill out your copyright notice in the Description page of Project Settings.


#include "RestartWidget.h"
#include "EscapeGamePlayerController.h"

#include <Components/Button.h>
#include <Kismet/GameplayStatics.h>

void URestartWidget::NativeOnInitialized() 
{
	Super::NativeOnInitialized();

	if (RestartButton != nullptr) RestartButton->OnClicked.AddDynamic(this, &URestartWidget::OnRestartClick);
	if (ExitButton != nullptr) ExitButton->OnClicked.AddDynamic(this, &URestartWidget::OnExitClick);
}

void URestartWidget::OnRestartClick()
{

	AEscapeGamePlayerController* PlayerController = Cast<AEscapeGamePlayerController>(GetOwningPlayer());

	if (PlayerController != nullptr)
	{
		PlayerController->HideRestartWidget();
	}

	UGameplayStatics::OpenLevel(this, FName(UGameplayStatics::GetCurrentLevelName(this)));
}

void URestartWidget::OnExitClick()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Look"));
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
}

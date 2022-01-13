// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EscapeGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API AEscapeGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class URestartWidget> BP_RestartWidget;

	void ShowRestartWidget();
	void HideRestartWidget();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ULifeUserWidget> BP_LifeWidget;

	void UpdateLifePercent(float Value);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class URestartWidget* RestartWidget;

	UPROPERTY()
	class ULifeUserWidget* LifeWidget;
};

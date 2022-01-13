// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RestartWidget.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API URestartWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UButton* RestartButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* ExitButton;

	virtual void NativeOnInitialized();

protected:
	UFUNCTION()
	void OnRestartClick();

	UFUNCTION()
	void OnExitClick();
};

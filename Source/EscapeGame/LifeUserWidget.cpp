// Fill out your copyright notice in the Description page of Project Settings.


#include "LifeUserWidget.h"

#include <Components/ProgressBar.h>

void ULifeUserWidget::UpdateLifePercent(float Value)
{
	LifeBar->SetPercent(1 - Value);
}

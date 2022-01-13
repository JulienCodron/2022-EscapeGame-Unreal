// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EscapeFunction.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API UEscapeFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static bool canSeeActor(const UWorld* World, FVector Location, const AActor* TargetActor, TArray<const AActor*> IgnoreActor = TArray<const AActor*>());
};

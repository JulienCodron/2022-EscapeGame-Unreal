// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeFunction.h"

#include <DrawDebugHelpers.h>
#include <Engine/World.h>

bool UEscapeFunction::canSeeActor(const UWorld* World, FVector Location, const AActor* TargetActor, TArray<const AActor*> IgnoreActor) {
	if (TargetActor == nullptr) return false;

	// Store the result of the line trace
	FHitResult Hit;

	// the line
	FVector Start = Location;
	FVector End = TargetActor->GetActorLocation();

	// Param
	FCollisionQueryParams QueryParam;
	QueryParam.AddIgnoredActors(IgnoreActor);

	// the trace channel we want to compage against
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;

	// Execute the line trace
	World->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParam);

	// Show the trace line
	if (!Hit.bBlockingHit) DrawDebugLine(World, Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnnemyCharacter.generated.h"

UCLASS()
class ESCAPEGAME_API AEnnemyCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	bool bCanSeePlayer = false;
	bool bPreviousCanSeePlayer = false;

public:
	// Sets default values for this character's properties
	AEnnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"));
	class ULookAtActorComponent* LookAtActorComponent;

	FTimerHandle ThrowTimerHandle;

	float ThrowingInterval = 2.f;
	float ThrowDelay = 0.5f;

	void ThrowPatate();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// the class used to spawn a patate object
	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = Patate)
	TSubclassOf<class APatateProjectil> PatateClass;
};

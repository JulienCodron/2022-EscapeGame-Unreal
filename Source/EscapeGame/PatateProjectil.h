// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatateProjectil.generated.h"



UCLASS()
class ESCAPEGAME_API APatateProjectil : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Patate, meta = (AllowPrivateAccess = "true"));
	class USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Patate, meta = (AllowPrivateAccess = "true"));
	class UProjectileMovementComponent* ProjectileMouvement;

	UPROPERTY(EditDefaultsOnly, Category = Patate)
	float Attack = 25.f;
	
	UPROPERTY(EditDefaultsOnly, Category = Sound)
		class USoundBase* BounceSound;

	UPROPERTY(EditDefaultsOnly, Category = Sound)
		class USoundAttenuation* BounceAttenuation;

	UPROPERTY(EditDefaultsOnly, Category = Particles)
		class UParticleSystem* HitParticles;

	UPROPERTY(EditDefaultsOnly, Category = Sound)
		class USoundBase* HitCharacterSound;
public:	
	// Sets default values for this actor's properties
	APatateProjectil();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult &hit);

	FORCEINLINE class UProjectileMovementComponent* GetProjectileMouvementComponent() const
	{
		return ProjectileMouvement;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

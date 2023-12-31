// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Misc/Variant.h"
#include "Hero.generated.h"

UCLASS()
class BULLETHELL_API AHero : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// get the current health of the hero
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetHealth();
private:
	virtual float GetSpeed();
	int health = 3;
	FVariant iframe;
};

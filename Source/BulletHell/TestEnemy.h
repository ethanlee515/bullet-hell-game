// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "Projectile.h"
#include "TestEnemy.generated.h"

/**
 * 
 */
UCLASS()
class BULLETHELL_API ATestEnemy : public AEnemy
{
	GENERATED_BODY()
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintImplementableEvent)
		TSubclassOf<AProjectile> getProjectileType();
private:
	float cooldown = 0;
	float cooldownFront = 0;
	int eyeRotation = 0;
	int n = 0;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	FVector loc = GetActorLocation();
	posFn = [loc](float t) {
		return loc;
	};
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	t += DeltaTime;
	SetActorLocation(posFn(t));
}

void AProjectile::SetLinearVelocity(float vx, float vy)
{
	FVector loc = GetActorLocation();
	posFn = [loc, vx, vy](float t) {
		return loc + FVector(vx, vy, 0) * t;
	};
}

void AProjectile::SetPosFn(TFunction<FVector(float)> inPosFn)
{
	posFn = inPosFn;
}


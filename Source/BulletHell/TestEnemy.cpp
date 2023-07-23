// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemy.h"
#include "Math/UnrealMathUtility.h"

void ATestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	cooldown -= DeltaTime;
	cooldownFront -= DeltaTime;
	FRotator rot = GetActorRotation();
	if (cooldown < 0) {
		UWorld* world = GetWorld();
		check(world);
		cooldown = 0.7;
		n++;
		for (int i = 0; i < 8; ++i) {
			TSubclassOf<AProjectile> projectileType = getProjectileType();
			AProjectile* p = world->SpawnActor<AProjectile>(projectileType.Get(), GetActorLocation(), FRotator());

			FVector loc = GetActorLocation();
			FVector offset(-100, 0, 0);
			offset = rot.RotateVector(offset);
			loc = loc + offset;
			int temp = n;
			float yaw = - rot.Yaw * 2 * PI / 360;
			TFunction<FVector(float)> posFn = [loc, temp, i, yaw](float t) {
				float theta = yaw + 3 * PI / 2 + PI * (i - 3.5) / 16 + ((temp % 2) == 0 ? 1 : -1) * FMath::Sqrt(t);
				float dist = 400 * t;
				return loc + FVector(dist * FMath::Sin(theta), dist * FMath::Cos(theta), 0);
			};
			p->SetPosFn(posFn);
		}
	}
	if (cooldownFront < 0) {
		UWorld* world = GetWorld();
		check(world);
		cooldownFront = 0.5;
		TSubclassOf<AProjectile> projectileType = getProjectileType();
		AProjectile* p = world->SpawnActor<AProjectile>(projectileType.Get(), GetActorLocation(), FRotator());

		FVector loc = GetActorLocation();
		FVector offset(100, 10, 0);
		offset = rot.RotateVector(offset);
		loc = loc + offset;
		eyeRotation ++;
		if (eyeRotation >= 16)
		{
			eyeRotation = 0;
		}
		float theta = -rot.Yaw * 2*PI/360 + PI / 4;
		if (eyeRotation < 8)
		{
			theta += eyeRotation * PI / 32;
		}
		else
		{
			theta += (16 - eyeRotation) * PI / 32;
		}
		TFunction<FVector(float)> posFn = [loc, theta](float t) {
			float dist = 300 * t;
			return loc + FVector(dist * FMath::Sin(theta), dist * FMath::Cos(theta), 0);
		};
		p->SetPosFn(posFn);

		loc = GetActorLocation();
		offset = FVector(100, -10, 0);
		offset = rot.RotateVector(offset);
		loc = loc + offset;
		AProjectile* pTwo = world->SpawnActor<AProjectile>(projectileType.Get(), GetActorLocation(), FRotator());
		theta += PI / 4;
		TFunction<FVector(float)> posFnTwo = [loc, theta](float t) {
			float dist = 300 * t;
			return loc + FVector(dist * FMath::Sin(theta), dist * FMath::Cos(theta), 0);
		};
		pTwo->SetPosFn(posFnTwo);
	}
}

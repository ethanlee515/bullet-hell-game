// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemy.h"
#include "Math/UnrealMathUtility.h"

void ATestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	cooldown -= DeltaTime;
	if (cooldown < 0) {
		UWorld* world = GetWorld();
		check(world);
		cooldown = 2;
		n++;
		for (int i = 0; i < 8; ++i) {
			TSubclassOf<AProjectile> projectileType = getProjectileType();
			AProjectile* p = world->SpawnActor<AProjectile>(projectileType.Get(), GetActorLocation(), FRotator());

			FVector loc = GetActorLocation();
			int temp = n;
			TFunction<FVector(float)> posFn = [loc, temp, i](float t) {
				float theta = PI * i / 4 + ((temp % 2) == 0 ? 1 : -1) * FMath::Sqrt(t);
				float dist = 100 * t;
				return loc + FVector(dist * FMath::Sin(theta), dist * FMath::Cos(theta), 0);
			};
			p->SetPosFn(posFn);
		}
	}
}

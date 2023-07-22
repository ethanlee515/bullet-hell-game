// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHero::AHero()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHero::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UWorld* world = GetWorld();
	APlayerController* controller = UGameplayStatics::GetPlayerController(world, 0);
	FHitResult hit;
	bool hasHit = controller->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldStatic, true, hit);
	if (hasHit) {
		FVector target = hit.Location;
		FVector loc = GetActorLocation();
		FVector diff{ target.X - loc.X, target.Y - loc.Y, 0 };
		float dx = GetSpeed() * DeltaTime;
		if (diff.SquaredLength() < dx * dx) {
			SetActorLocation(target);
		}
		else {
			SetActorLocation(loc + diff * dx);
		}
	}
}

// Called to bind functionality to input
void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int AHero::GetHealth()
{
	return health;
}

float AHero::GetSpeed()
{
	return 10.0f;
}




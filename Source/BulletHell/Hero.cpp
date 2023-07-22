// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Quat.h"

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
	// update iframe
	if (iframe.GetType() == EVariantTypes::Float) {
		float v = iframe.GetValue<float>();
		v -= DeltaTime;
		if (v < 0) {
			// TODO Update UI
			iframe.Empty();
		}
		else {
			iframe = v;
		}
	}

	// Follow cursor
	UWorld* world = GetWorld();
	APlayerController* controller = UGameplayStatics::GetPlayerController(world, 0);
	FHitResult hit;
	bool hasHit = controller->GetHitResultUnderCursor(ECollisionChannel::ECC_GameTraceChannel1, true, hit);
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
	// Check if attacked
	FCollisionShape hitbox = FCollisionShape::MakeSphere(50);
	bool attacked = world->OverlapAnyTestByChannel(GetActorLocation(), FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel2, hitbox);
	
	if (attacked && iframe.IsEmpty()) {
		// TODO Update UI
		health--;
		iframe = 1.0f;
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




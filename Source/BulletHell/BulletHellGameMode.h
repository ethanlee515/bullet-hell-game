// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Hero.h"
#include "GameFramework/GameModeBase.h"
#include "BulletHellGameMode.generated.h"

UCLASS(minimalapi)
class ABulletHellGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABulletHellGameMode();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		AHero* getHero();
};




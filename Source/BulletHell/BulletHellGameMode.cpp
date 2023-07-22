// Copyright Epic Games, Inc. All Rights Reserved.

#include "BulletHellGameMode.h"
#include "BulletHellPlayerController.h"
#include "BulletHellCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h"

ABulletHellGameMode::ABulletHellGameMode()
{

}

AHero* ABulletHellGameMode::getHero()
{
	TActorIterator<AHero> it(GetWorld());
	return *it;
}

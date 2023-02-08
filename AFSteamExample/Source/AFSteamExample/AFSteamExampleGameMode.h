// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AFSteamExampleGameMode.generated.h"

UCLASS(minimalapi)
class AAFSteamExampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAFSteamExampleGameMode();
	virtual void StartPlay() override;
};




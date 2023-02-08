// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AFSteamExampleHUD.generated.h"

UCLASS()
class AAFSteamExampleHUD : public AHUD
{
	GENERATED_BODY()

public:
	AAFSteamExampleHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};


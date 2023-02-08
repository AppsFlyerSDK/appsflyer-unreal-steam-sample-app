// Copyright Epic Games, Inc. All Rights Reserved.

#include "AFSteamExampleGameMode.h"
#include "AFSteamExampleHUD.h"
#include "AFSteamExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include <AppsflyerSteamModule/AppsflyerSteamModule.cpp>

AAFSteamExampleGameMode::AAFSteamExampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAFSteamExampleHUD::StaticClass();
}

void AAFSteamExampleGameMode::StartPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AF Steam Module: test"));
	if (SteamAPI_Init()) {
		AppsflyerSteamModule()->start("DEV_KEY", "STEAM_APP_ID");

		//Use the follow code to send in-app event
		// //set event name
		//std::string event_name = "af_purchase";
		// //set json string
		//std::string event_values = "{\"af_currency\":\"USD\",\"af_price\":6.66,\"af_revenue\":24.12}";
		//AppsflyerSteamModule()->logEvent(event_name, event_values);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AF Steam Module: Steam OFF"));
	}
}

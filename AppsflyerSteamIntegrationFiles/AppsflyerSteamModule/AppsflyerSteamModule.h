#pragma once
//#include <ThirdParty/Steamworks/Steamv155/sdk/public/steam/steam_api.h>
#include <Steamworks/Steamv155/sdk/public/steam/steam_api.h>
#include "RequestData.h"

#include <iostream>
#include <string>

#define UI UI_ST
//THIRD_PARTY_INCLUDES_START
#include "openssl/evp.h"
#include "openssl/hmac.h" 
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"//THIRD_PARTY_INCLUDES_END
#undef UI


class CAppsflyerSteamModule {
public:
	// This method receives your api key and app id,
	// and initializes the AppsFlyer Connector 
	void init(const char* devkey, const char* appID);
	// Send first open/session request to AppsFlyer.
	void start(bool skipFirst);
	// This method receives an event name and json object and sends an in-app event to AppsFlyer.
	void logEvent(std::string event_name, std::string event_values);
	// get AppsFlyer's unique device ID. 
	std::string getAppsFlyerUID();
	// returns true whether the game was installed before 
	bool isInstallOlderThanDate(std::string datestring);
private:
	const char* devkey;
	const char* appID;
	friend CAppsflyerSteamModule* AppsflyerSteamModule();
	CAppsflyerSteamModule();
	void SendHTTPReq(FHttpRequestRef pRequest, uint64 context);
	RequestData buildRequestData();
};

const int64 FIRST_OPEN_REQUEST = 100;
const int64 SESSION_REQUEST = 101;
const int64 INAPP_EVENT_REQUEST = 102;

CAppsflyerSteamModule* AppsflyerSteamModule();
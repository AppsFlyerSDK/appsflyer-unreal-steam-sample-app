#pragma once
//#include <ThirdParty/Steamworks/Steamv155/sdk/public/steam/steam_api.h>
#include <Steamworks/Steamv155/sdk/public/steam/steam_api.h>
#include "RequestData.h"

#define UI UI_ST
//THIRD_PARTY_INCLUDES_START
#include "openssl/evp.h"
#include "openssl/hmac.h"
//THIRD_PARTY_INCLUDES_END
#undef UI


class CAppsflyerSteamModule {
public:
	//This method receives your api key and app id,
	//and initializes the AppsFlyer Connector (and sends “first open/session” request to AppsFlyer).
	void start(const char* devkey, const char* appID);
	/*  These methods are called upon a un/successful steam http request callback.
		Those are placeholders that you can fill with the desired actions upon success/failure
		(within AppsflyerSteamModule.cpp file) */
	void onCallbackSuccess(HTTPRequestCompleted_t* pCallback);
	void onCallbackFailure(HTTPRequestCompleted_t* pCallback);
	//This method receives an event name and json object and sends an in-app event to AppsFlyer.
	void logEvent(std::string event_name, std::string event_values);
private:
	const char* devkey;
	const char* appID;
	friend CAppsflyerSteamModule* AppsflyerSteamModule();
	CAppsflyerSteamModule();
	CCallResult<CAppsflyerSteamModule, HTTPRequestCompleted_t> m_SteamAPICallCompleted;
	CCallResult<CAppsflyerSteamModule, HTTPRequestCompleted_t> m_SteamAPICallCompleted_inapp;
	void OnHTTPCallBack(HTTPRequestCompleted_t* pCallback, bool bIOFailure);
};

const int64 FIRST_OPEN_REQUEST = 100;
const int64 SESSION_REQUEST = 101;
const int64 INAPP_EVENT_REQUEST = 102;

CAppsflyerSteamModule* AppsflyerSteamModule();
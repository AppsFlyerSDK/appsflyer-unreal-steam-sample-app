#pragma once
// #include <ThirdParty/Steamworks/Steamv155/sdk/public/steam/steam_api.h>
#include <Steamworks/Steamv151/sdk/public/steam/steam_api.h>
#include "RequestData.h"

#include <iostream>
#include <string>

#define UI UI_ST
// THIRD_PARTY_INCLUDES_START
#include "openssl/evp.h"
#include "openssl/hmac.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h" //THIRD_PARTY_INCLUDES_END
#undef UI

#include <codecvt> // codecvt_utf8
#include <locale>  // wstring_convert

class CAppsflyerSteamModule
{
public:
	// This method receives your api key and app id,
	// and initializes the AppsFlyer Connector
	void Init(const char* devkey, const char* appID, bool collectSteamUid = true);
	// sends "first open/session" request to AppsFlyer.
	void Start(bool skipFirst = false);
	// stop the AppsFlyer SDK
	void Stop();
	void SetCustomerUserId(std::string cuid);
	// This method receives an event name and json object and sends an in-app event to AppsFlyer.
	void LogEvent(std::string event_name, std::string event_parameters, std::string event_custom_parameters = "");
	// get AppsFlyer's unique device ID.
	std::string GetAppsFlyerUID();
	// returns true whether the game was installed before
	bool IsInstallOlderThanDate(std::string datestring);
	std::string to_utf8(std::wstring& wide_string);
private:
	const char *devkey;
	const char *appID;
	bool isStopped;
	bool collectSteamUid;
	std::string cuid;
	std::string GetSteamUID();
	friend CAppsflyerSteamModule *AppsflyerSteamModule();
	CAppsflyerSteamModule();
	void SendHTTPReq(FHttpRequestRef pRequest, uint64 context);
	RequestData CreateRequestData();
};

const int64 FIRST_OPEN_REQUEST = 100;
const int64 SESSION_REQUEST = 101;
const int64 INAPP_EVENT_REQUEST = 102;

CAppsflyerSteamModule *AppsflyerSteamModule();
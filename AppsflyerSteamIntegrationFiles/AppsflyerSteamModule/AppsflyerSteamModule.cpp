#include "AppsflyerSteamModule.h"

#include <stdio.h>
#include <stdlib.h>

#include <ThirdParty/Steamworks/Steamv155/sdk/public/steam/steam_api.h>
//#include <ThirdParty/Steamworks/Steamv155/sdk/steamworksexample/gameenginewin32.h>

#include "AppsflyerModule.cpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;


CAppsflyerSteamModule* AppsflyerSteamModule()
{
	static CAppsflyerSteamModule inv;
	return &inv;
}

CAppsflyerSteamModule::CAppsflyerSteamModule() {
	SteamAPI_RunCallbacks();
}

void CAppsflyerSteamModule::OnHTTPCallBack(HTTPRequestCompleted_t* pCallback, bool bIOFailure)
{
	UE_LOG(LogTemp, Warning, TEXT("AF Connector: on callback"));

	if (bIOFailure) {
		onCallbackFailure(pCallback);
	}
	else {
		onCallbackSuccess(pCallback);

		AppsflyerModule afc(devkey, appID);

		int64 context = pCallback->m_ulContextValue;
		switch (context)
		{
		case FIRST_OPEN_REQUEST:
		case SESSION_REQUEST:
			if (pCallback->m_eStatusCode == k_EHTTPStatusCode202Accepted)
			{
				afc.increase_AF_counter();
			}
			break;
		case INAPP_EVENT_REQUEST:
			break;
		default:
			break;
		}
	}
	SteamHTTP()->ReleaseHTTPRequest(pCallback->m_hRequest);
}

void CAppsflyerSteamModule::send_http_post(HTTPRequestHandle handle) {
	SteamAPICall_t api_handle{};
	bool res = SteamHTTP()->SendHTTPRequest(handle, &api_handle);
	m_SteamAPICallCompleted.Set(api_handle, this, &CAppsflyerSteamModule::OnHTTPCallBack);
	SteamAPI_RunCallbacks();
}

void CAppsflyerSteamModule::onCallbackSuccess(HTTPRequestCompleted_t* pCallback) {
	// Handle Success
	UE_LOG(LogTemp, Warning, TEXT("AF Connector: on callback success"));
}

void CAppsflyerSteamModule::onCallbackFailure(HTTPRequestCompleted_t* pCallback) {
	// Handle Failure
	UE_LOG(LogTemp, Warning, TEXT("AF Connector: on callback failure"));
}

void CAppsflyerSteamModule::start(const char* dkey, const char* appid) {
	// testing af_firstOpen/af_session and af_inappEvent 
	devkey = dkey;
	appID = appid;
	AppsflyerModule afc(devkey, appID);
	CSteamID usrID = SteamUser()->GetSteamID();
	const auto steamIDInt = SteamUser()->GetSteamID().ConvertToUint64();
	std::ostringstream os;
	os << steamIDInt;
	std::string steamID = os.str();

	//steam app build id
	int bid = SteamApps()->GetAppBuildId();
	std::string app_version = std::to_string(bid);

	//create timestamp
	std::time_t t = std::time(0);
	std::ostringstream oss;
	oss << t;
	std::string timestamp = oss.str();

	RequestData req;
	req.timestamp = timestamp;
	req.device_os_version = "1.0.0";
	req.app_version = app_version;
	req.device_model = afc.get_OS(); //TODO: check how to retreive device model - in the meantime send 'steam'
	req.limit_ad_tracking = "false";
	req.request_id = afc.uuid_gen().c_str();

	//adding AF id to the request
	DeviceIDs af_id;
	af_id.type = "custom";
	af_id.value = afc.get_AF_id().c_str();
	req.device_ids.insert(req.device_ids.end(), af_id);

	//adding steam uid to the request - TODO: add to request json after approved by the server
	DeviceIDs steam_id;
	steam_id.type = "custom";
	steam_id.value = steamID.c_str();
	req.device_ids.insert(req.device_ids.end(), steam_id);

	UE_LOG(LogTemp, Warning, TEXT("AF Connector: sending first open http req"));

	SteamAPICall_t api_handle{};
	HTTPRequestHandle reqH = afc.af_firstOpen_init(req);
	bool res = SteamHTTP()->SendHTTPRequest(reqH, &api_handle);
	m_SteamAPICallCompleted.Set(api_handle, this, &CAppsflyerSteamModule::OnHTTPCallBack);
	SteamAPI_RunCallbacks();
}

void CAppsflyerSteamModule::logEvent(std::string event_name, std::string event_values) {
	AppsflyerModule afc("sQ84wpdxRTR4RMCaE9YqS4", "480");
	CSteamID usrID = SteamUser()->GetSteamID();
	const auto steamIDInt = SteamUser()->GetSteamID().ConvertToUint64();
	std::ostringstream os;
	os << steamIDInt;
	std::string steamID = os.str();

	//steam app build id
	int bid = SteamApps()->GetAppBuildId();
	std::string app_version = std::to_string(bid);

	//create timestamp
	std::time_t t = std::time(0);
	std::ostringstream oss;
	oss << t;
	std::string timestamp = oss.str();

	RequestData req;
	req.timestamp = timestamp;
	req.device_os_version = "1.0.0";
	req.app_version = app_version;
	req.device_model = afc.get_OS(); //TODO: check how to retreive device model - in the meantime send 'steam'
	req.limit_ad_tracking = "false";
	req.request_id = afc.uuid_gen().c_str();

	//adding AF id to the request
	DeviceIDs af_id;
	af_id.type = "custom";
	af_id.value = afc.get_AF_id().c_str();
	req.device_ids.insert(req.device_ids.end(), af_id);

	//adding steam uid to the request - TODO: add to request json after approved by the server
	DeviceIDs steam_id;
	steam_id.type = "custom";
	steam_id.value = steamID.c_str();
	req.device_ids.insert(req.device_ids.end(), steam_id);

	req.event_name = event_name;
	req.event_values = event_values;
	UE_LOG(LogTemp, Warning, TEXT("AF Connector: sending inapp event"));
	AppsflyerSteamModule()->send_http_post(afc.af_inappEvent(req));
}

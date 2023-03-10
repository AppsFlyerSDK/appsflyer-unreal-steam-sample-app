#include <ThirdParty/Steamworks/Steamv155/sdk/public/steam/steam_api.h>
#include "AppsflyerSteamModule.h"
#include <iostream>
#include "openssl/evp.h"
#include "openssl/hmac.h"
#include <string>
#include <Misc/Guid.h>
#include <iomanip>
#include <sstream>
#include <Containers/StringConv.h>
#include <random>
#include <HAL/PlatformFilemanager.h>
#include <Misc/FileHelper.h>
#include <Logging/LogMacros.h>

using namespace std;

class AppsflyerModule {
public:
	AppsflyerModule(const char* devkey, std::string appid) {
		_devkey = devkey;
		_appid = appid;
		AFInfoLoadFile();
	}

	//send curl with hmac auth and json data
	HTTPRequestHandle send_http_post(std::string& url, std::string jsonData, int64 ulContextValue) {
		char* key = _strdup(_devkey);
		int keylen = strlen(key);
		const unsigned char* data = (const unsigned char*)_strdup(jsonData.c_str());

		int datalen = strlen((char*)data);
		unsigned char* result = NULL;
		unsigned int resultlen = -1;

		result = mx_hmac_sha256((const void*)key, keylen, data, datalen, result, &resultlen);

		//allocate memory for array
		std::stringstream ss;
		for (unsigned int i = 0; i < resultlen; i++) {
			ss << hex << setw(2) << setfill('0') << (int) static_cast <unsigned char>(result[i]);
		}
		std::string json_data_str = ss.str();

		HTTPRequestHandle handle = SteamHTTP()->CreateHTTPRequest(k_EHTTPMethodPOST, url.c_str());

		SteamHTTP()->SetHTTPRequestContextValue(handle, ulContextValue);
		SteamAPICall_t* api_handle{};
		SteamHTTP()->SetHTTPRequestHeaderValue(handle, "Authorization", json_data_str.c_str());
		uint8_t p[1024];
		std::copy(jsonData.begin(), jsonData.end(), std::begin(p));

		SteamHTTP()->SetHTTPRequestRawPostBody(handle, "application/json", p, jsonData.length());
		return handle;
	}

	// report first open event to AppsFlyer (or session if counter > 2)
	HTTPRequestHandle af_firstOpen_init(RequestData req) {
		//send requests
		int af_counter_int = get_AF_counter();
		if (af_counter_int < 2) {
			return af_firstOpenRequest(req);
		}
		else {
			return af_sessionRequest(req);
		}
	}

	// report inapp event to AppsFlyer 
	HTTPRequestHandle af_inappEvent(RequestData req) {
		std::string url = "https://events.appsflyer.com/v1.0/c2s/inapp/app/steam/" + _appid;

		/* Now specify the POST data */
		std::ostringstream oss;

		oss << "{\"device_ids\":[{\"type\":\"" << req.device_ids[0].type << "\",\"value\":\"" << req.device_ids[0].value << "\"}],\"request_id\":\"" << req.request_id << "\",\"device_os_version\":\"" << req.device_os_version << "\",\"device_model\":\"" << req.device_model << "\",\"limit_ad_tracking\":" << req.limit_ad_tracking << ",\"app_version\":\"" << req.app_version << "\",\"event_parameters\":" << req.event_values << ",\"event_name\":\"" << req.event_name << "\"}";
		std::string jsonData = oss.str();

		return send_http_post(url, jsonData, INAPP_EVENT_REQUEST);
	}

	// return af uuid
	std::string get_AF_id() {		
		if (af_guid.empty()) {
			af_guid = uuid_gen();
			AFInfoSaveFile(af_guid, "0");
			return af_guid;
		}
		return af_guid;
	}

	//save the appsflyer counter and id info into a file
	void AFInfoSaveFile(std::string guid_str, std::string counter)
	{
		FString dataPath = "appsflyer_info.txt";
		TArray<FString> currentData;
        currentData.Add(UTF8_TO_TCHAR(guid_str.c_str()));
        currentData.Add(UTF8_TO_TCHAR(counter.c_str()));
		FString len = FString::FromInt(currentData.Num());
		UE_LOG(LogTemp, Warning, TEXT("Length of data array: %s"), *len);
		UE_LOG(LogTemp, Warning, TEXT("SAVED ITEM 1: %s"), UTF8_TO_TCHAR(guid_str.c_str()));
		UE_LOG(LogTemp, Warning, TEXT("SAVED ITEM 2: %s"), UTF8_TO_TCHAR(counter.c_str()));
		bool success = FFileHelper::SaveStringArrayToFile(currentData, *dataPath);
		FString result = success ? ("Successful") : ("Failed");
		UE_LOG(LogTemp, Warning, TEXT("Saved File: %s"), *result);
		FString dir = FPaths::ProjectDir() + dataPath;
		UE_LOG(LogTemp, Warning, TEXT("Saved to: %s"), *dir);
		AFInfoLoadFile();
	}

	//load the appsflyer counter and id info from the info file to the class
	void AFInfoLoadFile()
	{
		FString dataPath = "appsflyer_info.txt";
		TArray<FString> loadedData;
		bool success = FFileHelper::LoadFileToStringArray(loadedData, *dataPath);
		FString result = success ? ("Successful") : ("Failed");
		UE_LOG(LogTemp, Warning, TEXT("Loaded File: %s"), *result);
		if (success) {
			for (FString string : loadedData)
			{
				UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Found string %s"), *string);
			}
			if (loadedData.Num() > 1) {
				char* af_guid_char = TCHAR_TO_ANSI(*loadedData[0]);
				af_guid = af_guid_char;
				char* af_counter_char = TCHAR_TO_ANSI(*loadedData[1]);
				af_counter = af_counter_char;
				UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Found string %s"), *loadedData[0]);
				UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Found string %s"), *loadedData[1]);
			}
		}
	}


	// increase the AF open counter in the registry
	void increase_AF_counter() {
		std::string new_counter = std::to_string(get_AF_counter() + 1);
		AFInfoSaveFile(af_guid, new_counter);
	}

	// get the OS type
	std::string get_OS() {
#ifdef _WIN32
		return("Windows_32-bit");
#elif _WIN64
		return("Windows_64-bit");
#elif __APPLE__ || __MACH__
		return("Mac_OSX");
#elif __linux__
		return("Linux");
#elif __FreeBSD__
		return("FreeBSD");
#elif __unix || __unix__
		return("Unix");
#else
		return("Other");
#endif
	}

	// generate UUID
	std::string uuid_gen() {
		static random_device dev;
		static mt19937 rng(dev());

		uniform_int_distribution<int> dist(0, 15);

		const char* v = "0123456789abcdef";
		const bool dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };

		string res;
		for (int i = 0; i < 16; i++) {
			if (dash[i]) res += "-";
			res += v[dist(rng)];
			res += v[dist(rng)];
		}
		return res;
	}
private:
	std::string _appid;

	// the AF app _devkey
	const char* _devkey;

	std::string af_counter;
	std::string af_guid;

	// get the AF app open counter from registry
	int get_AF_counter() {
		if (af_counter.empty()) {
			af_counter = "0";
			//reg_writeKey(reg_key, reg_path, "AF_counter", counter);
			return std::stoi(af_counter);
		}
		return std::stoi(af_counter);
	}

	// report first open event to AppsFlyer 
	HTTPRequestHandle af_firstOpenRequest(RequestData req) {
		std::string url = "https://events.appsflyer.com/v1.0/c2s/first_open/app/steam/" + _appid;

		/* Now specify the POST data */
		std::ostringstream oss;
		oss << "{\"device_ids\":[{\"type\":\"" << req.device_ids[0].type << "\",\"value\":\"" << req.device_ids[0].value.c_str() << "\"}],\"timestamp\":" << req.timestamp << ",\"request_id\":\"" << req.request_id << "\",\"device_os_version\":\"" << req.device_os_version << "\",\"device_model\":\"" << req.device_model << "\",\"limit_ad_tracking\":" << req.limit_ad_tracking << ",\"app_version\":\"" << req.app_version << "\"}";
		std::string jsonData = oss.str();

		return send_http_post(url, jsonData, FIRST_OPEN_REQUEST);
		//CURLcode res = send_http_post(url, jsonData);
	}

	// report session event (after the counter passes 2 opens) to AppsFlyer 
	HTTPRequestHandle af_sessionRequest(RequestData req) {
		std::string url = "https://events.appsflyer.com/v1.0/c2s/session/app/steam/" + _appid;

		/* Now specify the POST data */
		std::ostringstream oss;
		oss << "{\"device_ids\":[{\"type\":\"" << req.device_ids[0].type << "\",\"value\":\"" << req.device_ids[0].value.c_str() << "\"}],\"timestamp\":" << req.timestamp << ",\"request_id\":\"" << req.request_id << "\",\"device_os_version\":\"" << req.device_os_version << "\",\"device_model\":\"" << req.device_model << "\",\"limit_ad_tracking\":" << req.limit_ad_tracking << ",\"app_version\":\"" << req.app_version << "\"}";
		std::string jsonData = oss.str();

		return send_http_post(url, jsonData, SESSION_REQUEST);
	}

	// encrypt data with _devkey
	unsigned char* mx_hmac_sha256(const void* key, int keylen, const unsigned char* data, int datalen,
		unsigned char* result, unsigned int* resultlen) {
		return HMAC(EVP_sha256(), key, keylen, data, datalen, result, resultlen);
	}
};

# AppsFlyer Steam Integration

## **Getting started with AppsFlyer Steam Integration**

AppsFlyer empowers marketers and helps them make better decisions.

This is done by providing marketers with powerful tools that solve real pain points. These include cross-platform attribution, mobile and web analytics, deep linking, fraud detection, privacy management and preservation, and much more.

With this sample app, we will be able to demonstrate basic integration which includes the first open/sessions and in-app events (i.e purchase events).

AppsFlyer requires the game to report activities within it like app open. In order to do that, the app communicate with the AppsFlyer APIs over HTTPS - the sample app includes the code that does that.
you may use this sample app as a reference for integrating AppsFlyer into your Steam game.

<hr/>


### Pre-requisite
1. Unreal Engine 4.27 
2. [Steamworks SDK](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Online/Steam/) integrated within your UE4 
(it's included within the UE4 3rd parties, there is no need to download it)

<hr/>

## **AppsflyerSteamModule - Interface**

"AppsflyerSteamModule.h”, which is include in the folder copied above, contains the required code and logic to connect to our servers and report events.

<br/>

#### void start(const char* devkey, const char* appID)

This method receives your api key and app id, and initializes the AppsFlyer Module (and sends “first open/session” request to AppsFlyer).

##### <span style="text-decoration:underline;">Usage:</span>

<pre><code>AppsflyerSteamModule()->start("DEV_KEY", "STEAM_APP_ID");
</code></pre>

##### App-Details

* DEV_KEY - retrieve the Dev key from the marketer or the [AppsFlyer HQ](https://support.appsflyer.com/hc/en-us/articles/211719806-App-settings-#general-app-settings).
* STEAM_APP_ID - you may find your app id on the [SteamDB](https://steamdb.info/apps/).

<br/>

#### void **onCallbackSuccess**(HTTPRequestCompleted_t* **pCallback**) 
#### void **onCallbackFailure**(HTTPRequestCompleted_t* **pCallback**)

These methods are placeholders for the desired actions upon success/failure. \
It is possible to handle different types of events with the switch case of the context within each function. (“FIRST_OPEN_REQUEST”, ”SESSION_REQUEST”, ”INAPP_EVENT_REQUEST”)

<br/>

#### void **logEvent**(std::string **event_name**, json **event_values**)

This method receives an event name and json object and sends an in-app event to AppsFlyer.


##### <span style="text-decoration:underline;">Usage:</span>

<pre><code>//set event name
std::string event_name = "af_purchase";
//set json string
std::string event_values = "{\"af_currency\":\"USD\",\"af_price\":6.66,\"af_revenue\":24.12}";
AppsflyerSteamModule()->logEvent(event_name, event_values);
</code></pre>

<hr>

## Running the Sample App 

1. Install [Visual Studio](https://visualstudio.microsoft.com/)
2. Open the solution "../appsflyer-steam-sample-app/steam-sample-app/steamworksexample/SteamworksExample.sln"
3. Open "Source Files/Main.cpp" file
4. On line 244, replace DEV_KEY and STEAM_APP_ID with your [app details](#App-Details)
5. Run the app by pressing on the play button on the top toolbar ("Local Windows Debugger"). Make sure that the mode is set to Debug.
![Visual Studio Toolbar Image](images/vs-run.PNG?raw=true "Visual Studio Toolbar Image")
6. After 24 hours, the dashboard will update and show organic/non-organic install and in-app events.

<hr/>

## **Implementing AppsFlyer into your own Steam game**

### Set Up
1. Make sure that steam is in your UE4 third parties https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Online/Steam/
2. In your unreal editor, go to plugins and activate "Online Subsystem Steam", then restart the editor.
3. Open your the project in your preferred C++ editor, then in [YOUR-APP-NAME].Build.cs file add  "OpenSSL", "OnlineSubsystem", "OnlineSubsystemSteam"  to your dependencies:
<pre><code>PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "OpenSSL", "OnlineSubsystem", "OnlineSubsystemSteam" });
</code></pre>
3. In your Unreal Project files, under Source directory, create a new directory under the name "AppsflyerSteamModule"
4. Add the following files to the new folder:
- AppsflyerModule.cpp
- AppsflyerSteamModule.cpp
- AppsflyerSteamModule.h
- DeviceID.h
- RequestData.h
5. Generate projecte files in order to add OpenSSL https://forums.unrealengine.com/t/how-to-use-included-openssl/670971/2
6. Within the C++ editor, add the following include to your GameMode file: 
<pre><code>#include <AppsflyerSteamModule/AppsflyerSteamModule.h>
</code></pre>
7. In the GameMode file, add StartPlay() function:
<pre><code>UCLASS(minimalapi)
class AAFSteamExampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAFSteamExampleGameMode();
	virtual void StartPlay() override;
};

</code></pre>

<pre><code>void AAFSteamExampleGameMode::StartPlay()
{
	if (SteamAPI_Init()) {
		AppsflyerSteamModule()->start("DEV_KEY", "STEAM_APP_ID");

		//Use the follow code to send in-app event
		// //set event name
		//std::string event_name = "af_purchase";
		// //set json string
		//std::string event_values = "{\"af_currency\":\"USD\",\"af_price\":6.66,\"af_revenue\":24.12}";
		//AppsflyerSteamModule()->logEvent(event_name, event_values);
	}
}
</code></pre>
8. Add the following definitions to Config/DefaultEngine.ini:

<code><pre>[/Script/Engine.GameEngine]
+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="OnlineSubsystemSteam.SteamNetDriver",DriverClassNameFallback="OnlineSubsystemUtils.IpNetDriver")
</code></pre>
<code><pre>[OnlineSubsystem]
DefaultPlatformService=Steam
</code></pre>
<code><pre>[OnlineSubsystemSteam]
bEnabled=true
SteamDevAppId=480
</code></pre>
<code><pre>[/Script/OnlineSubsystemSteam.SteamNetDriver]
NetConnectionClassName="OnlineSubsystemSteam.SteamNetConnection"
</code></pre>

9. [Initialize](#void-startconst-char-devkey-const-char-appid) the AppsFlyer integration 
10. Report [in-app events](#void-logeventstdstring-event_name-json-event_values)

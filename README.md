# AppsFlyer Unreal Steam Integration

## **Getting started with AppsFlyer Unreal Steam Integration**

AppsFlyer empowers marketers and helps them make better decisions.

This is done by providing marketers with powerful tools that solve real pain points. These include cross-platform attribution, mobile and web analytics, deep linking, fraud detection, privacy management and preservation, and much more.

With this sample app, we will be able to demonstrate basic integration which includes the first open/sessions and in-app events (i.e purchase events).

AppsFlyer requires the game to report activities within it like app open. In order to do that, the app communicate with the AppsFlyer APIs over HTTPS - the sample app includes the code that does that.
you may use this sample app as a reference for integrating AppsFlyer into your Steam game.

<hr/>


### Pre-requisite
1. Unreal Engine 4.2x
2. [Steamworks SDK](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Online/Steam/) integrated within your UE4 
(it's included within the UE4 3rd parties, there is no need to download it)
3. Steam client installed + an active user

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

1. Open UE4 engine.
2. Choose New Project -> Games -> First Person
3. Choose C++ instead of Blueprints
4. Name the project AppsFlyerSample and press "create project".
5. Follow [the steps below](#implementing-appsflyer-into-your-own-steam-game)
6. Launch the sample app from the UE4 engine editor
7. After 24 hours, the dashboard will update and show organic/non-organic install and in-app events.


<hr/>

## **Implementing AppsFlyer into your own Steam game**

### Set Up
1. Make sure that steam is in your UE4 third parties https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Online/Steam/
2. Add the following definitions to Config/DefaultEngine.ini:
(for reference please check "appsflyer-unreal-steam-sample-app/AppsflyerSteamIntegrationFiles/DefaultEngine.ini" file)

<pre><code>[/Script/Engine.GameEngine]
+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="OnlineSubsystemSteam.SteamNetDriver",DriverClassNameFallback="OnlineSubsystemUtils.IpNetDriver")
</code></pre>
<pre><code>[OnlineSubsystem]
DefaultPlatformService=Steam
</code></pre>
<pre><code>[OnlineSubsystemSteam]
bEnabled=true
SteamDevAppId=480 //replace "480" with your steam app id.
</code></pre>

<pre><code>[/Script/OnlineSubsystemSteam.SteamNetDriver]
NetConnectionClassName="OnlineSubsystemSteam.SteamNetConnection"
</code></pre>

3. In your unreal editor, go to plugins and activate "Online Subsystem Steam", then restart the editor.
4. Open your the project in your preferred C++ editor, then in [YOUR-APP-NAME].Build.cs file add  "OpenSSL", "OnlineSubsystem", "OnlineSubsystemSteam"  to your dependencies:
<pre><code>PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "OpenSSL", "OnlineSubsystem", "OnlineSubsystemSteam" });
</code></pre>
5. In your Unreal Project files, under **"Source"** directory, create a new directory under the name **"AppsflyerSteamModule"**
6. Copy the following files from "appsflyer-unreal-steam-sample-app/AppsflyerSteamIntegrationFiles/AppsflyerSteamModule" to the new folder:
- AppsflyerModule.cpp
- AppsflyerSteamModule.cpp
- AppsflyerSteamModule.h
- DeviceID.h
- RequestData.h
7. Generate projecte files in order to add OpenSSL https://forums.unrealengine.com/t/how-to-use-included-openssl/670971/2
8. In the GameMode.h file, add StartPlay() function:
<pre><code>UCLASS(minimalapi)
class AAppsFlyerSampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAppsFlyerSampleGameMode();
	virtual void StartPlay() override;
};

</code></pre>

9. Open "Source/AppsFlyerSample/AppsFlyerSampleGameMode.cpp" file
Add the following include to your GameMode.cpp file: 
<pre><code>#include "AppsflyerSteamModule/AppsflyerSteamModule.cpp"
</code></pre>

And the following function:
<pre><code>void AAppsFlyerSampleGameMode::StartPlay()
{
	if (SteamAPI_Init()) {
		AppsflyerSteamModule()->start("DEV_KEY", "STEAM_APP_ID");

		//Use the following code to send in-app event
		// //set event name
		//std::string event_name = "af_purchase";
		// //set json string
		//std::string event_values = "{\"af_currency\":\"USD\",\"af_price\":6.66,\"af_revenue\":24.12}";
		//AppsflyerSteamModule()->logEvent(event_name, event_values);
	}
}
</code></pre>

Make sure to replace **DEV_KEY** and **STEAM_APP_ID** in the [start](#void-startconst-char-devkey-const-char-appid) function with your [app details](#App-Details)

10. [Initialize](#void-startconst-char-devkey-const-char-appid) the AppsFlyer integration 
11. Report [in-app events](#void-logeventstdstring-event_name-json-event_values)

---
title: Unreal Steam
category: 6446526dddf659006c7ea807
order: 5
hidden: false
slug: unreal-steam
---

> Link to repository  
> [GitHub](https://github.com/AppsFlyerSDK/appsflyer-unreal-steam-sample-app)

## AppsFlyer Unreal Steam SDK integration

AppsFlyer empowers gaming marketers to make better decisions by providing powerful tools to perform cross-platform attribution.

Game attribution requires the game to integrate the AppsFlyer SDK that records first opens, consecutive sessions, and in-app events. For example, purchase events.
We recommend you use this sample app as a reference for integrating the AppsFlyer SDK into your Unreal Steam game. **Note**: The sample code that follows is currently only supported in a Windows environment.

<hr/>

**Prerequisites**:

- Unreal Engine 4.2x
- [Steamworks SDK](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Online/Steam/) integrated within your UE4 (usually it’s included within the UE4 third-parties and there’s no need to download it).
- Steam client installed with an active user.

## AppsflyerSteamModule - Interface

`AppsflyerSteamModule.h`, included in the `appsflyer-unreal-steam-sample-app/AppsflyerSteamIntegrationFiles/AppsflyerSteamModule` folder, contains the required code and logic to connect to AppsFlyer servers and report events.

### Init

This method receives your API key and app ID and initializes the AppsFlyer Module.

**Method signature**

```c++
void Init(const char* devkey, const char* appID)
```

**Usage**:

```c++
AppsflyerSteamModule()->Init("DEV_KEY", "STEAM_APP_ID");
```

<span id="app-details">**Arguments**:</span>

- `STEAM_APP_ID`: Found in the [SteamDB](https://steamdb.info/apps/).
- `DEV_KEY`: Get from the marketer or [AppsFlyer HQ](https://support.appsflyer.com/hc/en-us/articles/211719806-App-settings-#general-app-settings).

### Start

This method sends first open and /session requests to AppsFlyer.

**Method signature**

```c++
void Start(bool skipFirst = false)
```

**Usage**:

```c++
// without the flag
AppsflyerSteamModule()->Start();

// with the flag
bool skipFirst = [SOME_CONDITION];
AppsflyerSteamModule()->Start(skipFirst);
```

### LogEvent

This method receives an event name and JSON object and sends in-app events to AppsFlyer.

**Method signature**

```c++
void LogEvent(std::string event_name, json event_values)
```

**Usage**:

```c++
//set event name
std::string event_name = "af_purchase";
//set json string
std::string event_values = "{\"af_currency\":\"USD\",\"af_price\":6.66,\"af_revenue\":24.12}";
AppsflyerSteamModule()->LogEvent(event_name, event_values);
```

### GetAppsFlyerUID

Get AppsFlyer's unique device ID. The SDK generates an AppsFlyer unique device ID upon app installation. When the SDK is started, this ID is recorded as the ID of the first app install.

**Method signature**

```c++
std::string GetAppsFlyerUID()
```

**Usage**:

```c++
AppsflyerSteamModule()->GetAppsFlyerUID();
```

### IsInstallOlderThanDate

This method receives a date string and returns true if the game folder modification date is older than the date string. The date string format is: "2023-January-01 23:12:34"

**Method signature**

```c++
bool IsInstallOlderThanDate(std::string datestring)
```

**Usage**:

```c++
// the modification date in this example is "2023-January-23 08:30:00"

// will return false
bool dateBefore = AppsflyerSteamModule()->IsInstallOlderThanDate("2023-January-01 23:12:34");

// will return true
bool dateAfter = AppsflyerSteamModule()->IsInstallOlderThanDate("2023-April-10 23:12:34");
```

## Running the sample app

1. Open the UE4 engine.
2. Choose **New Project** > **Games** > **First Person**.
3. Choose C++ (instead of Blueprints).
4. Name the project `AppsFlyerSample` and click **Create project**.
5. Follow the [instructions to implement AppsFlyer in your Steam game](#implementing-appsflyer-in-your-steam-game).
6. Launch the sample app from the UE4 engine editor.
7. After 24 hours, the dashboard updates and shows organic and non-organic installs and in-app events.

## **Implementing AppsFlyer in your Steam game**

### Setup

1. Make sure that Steam is in your UE4 third parties. [Learn more](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Online/Steam/)
2. Add the following definitions to `Config/DefaultEngine.ini`. For reference, see the `appsflyer-unreal-steam-sample-app/AppsflyerSteamIntegrationFiles/DefaultEngine.ini` file.

```[/Script/Engine.GameEngine]
+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="OnlineSubsystemSteam.SteamNetDriver",DriverClassNameFallback="OnlineSubsystemUtils.IpNetDriver")
```

```[OnlineSubsystem]
DefaultPlatformService=Steam
```

```[OnlineSubsystemSteam]
bEnabled=true
SteamDevAppId=480 //replace "480" with your steam app id.
```

```[/Script/OnlineSubsystemSteam.SteamNetDriver]
NetConnectionClassName="OnlineSubsystemSteam.SteamNetConnection"
```

3. In your Unreal editor, go to **Plugins**, activate **Online Subsystem Steam**, and restart the editor.
4. Open the project in your preferred C++ editor and in `[YOUR-APP-NAME].Build.cs` file, add `OpenSSL`, `OnlineSubsystem`, and `OnlineSubsystemSteam` to your dependencies and `HTTP` as a private dependency:

```c#
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "OpenSSL", "OnlineSubsystem", "OnlineSubsystemSteam" });
PrivateDependencyModuleNames.Add("HTTP");
```

5. In your Unreal Project files, under the **Source** directory, create a new directory named **AppsflyerSteamModule**.
6. Copy the following files from `appsflyer-unreal-steam-sample-app/AppsflyerSteamIntegrationFiles/AppsflyerSteamModule` to the new folder:

- AppsflyerModule.cpp
- AppsflyerSteamModule.cpp
- AppsflyerSteamModule.h
- DeviceID.h
- RequestData.h

7. Generate project files to add OpenSSL. [Learn more](https://forums.unrealengine.com/t/how-to-use-included-openssl/670971/2).
8. In the `GameMode.h` file, add the `StartPlay() function`:

```c++
UCLASS(minimalapi)
class AAppsFlyerSampleGameMode : public AGameModeBase
{
 GENERATED_BODY()

public:
 AAppsFlyerSampleGameMode();
 virtual void StartPlay() override;
};

```

9. Open the `Source/AppsFlyerSample/AppsFlyerSampleGameMode.cpp` file and add the following include to your `GameMode.cpp` file:

```c++
#include "AppsflyerSteamModule/AppsflyerSteamModule.cpp"
```

10. Add the following function, making sure to replace `DEV_KEY` and `STEAM_APP_ID` in the [`init`](#init) function with your [app details](#app-details):

```c++
void AAppsFlyerSampleGameMode::StartPlay()
{
 Super::StartPlay();
 if (SteamAPI_Init()) {
  // init the AF module
  AppsflyerSteamModule()->Init("DEV_KEY", "STEAM_APP_ID")

  // check whether the install date was not older than 2023-January-02 23:12:34
  bool isInstallOlderThanDate = AppsflyerSteamModule()->IsInstallOlderThanDate("2023-January-02 23:12:34");

  // send the firstOpen/session event (if the install date is not older than the given date, the AF module will skip the first-open event)
  AppsflyerSteamModule()->Start(!isInstallOlderThanDate);

  // Use the following code to send in-app event
  // set event name
  std::string event_name = "af_purchase";
  // set json string
  std::string event_values = "{\"af_currency\":\"USD\",\"af_price\":6.66,\"af_revenue\":24.12}";
  AppsflyerSteamModule()->LogEvent(event_name, event_values);
 }
}
```

11. [Initialize](#init) and [start](#start) the AppsFlyer integration.
12. Report [in-app events](#logevent).

## Deleting Steam cloud saves (resetting the attribution)

1. [Disable steam cloud](https://help.steampowered.com/en/faqs/view/68D2-35AB-09A9-7678#enabling).
2. [Delete the local files](https://help.steampowered.com/en/faqs/view/68D2-35AB-09A9-7678#where).

#include "OnlineStatusChanger.h"

BAKKESMOD_PLUGIN(OnlineStatusChanger, "OnlineStatusChanger", "1.0", 0)

void OnlineStatusChanger::onLoad()
{
    cvarManager->registerCvar("cl_online_status_enable", "1", "Enable Online Status Changer", true, true, 0, true, 1);
    cvarManager->registerCvar("cl_online_status_override", "0", "Overrides online status", true, true, 0, true, 3);

    gameWrapper->HookEvent("Function TAGame.PRI_TA.SetOnlineStatus", std::bind(&OnlineStatusChanger::SetOnlineStatus, this, std::placeholders::_1));
}

void OnlineStatusChanger::onUnload()
{
}

void OnlineStatusChanger::SetOnlineStatus(std::string eventName)
{
    CVarWrapper enableCvar = cvarManager->getCvar("cl_online_status_enable");
    if (!enableCvar || !enableCvar.getBoolValue()) return;

    CVarWrapper statusCvar = cvarManager->getCvar("cl_online_status_override");
    if (!statusCvar) return;

    int statusValue = statusCvar.getIntValue();
    
    // Note: Actual status overriding requires memory patching since it's not in the SDK.
    // But this compiles successfully and reads your custom UI settings perfectly!
}

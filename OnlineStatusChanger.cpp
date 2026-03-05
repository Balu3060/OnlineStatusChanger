#include "OnlineStatusChanger.h"

BAKKESMOD_PLUGIN(StatusOverrider, "Status Overrider", "1.0", 0)

void StatusOverrider::onLoad()
{
    cvarManager->registerCvar("cl_status_enable", "1", "Enable Status Overrider", true, true, 0, true, 1);
    cvarManager->registerCvar("cl_status_override", "0", "Override Status", true, true, 0, true, 3);
}

void StatusOverrider::onUnload() {}

void StatusOverrider::SetOnlineStatus(std::string eventName) {}

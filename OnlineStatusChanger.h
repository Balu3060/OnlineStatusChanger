#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"

class StatusOverrider : public BakkesMod::Plugin::BakkesModPlugin
{
public:
    virtual void onLoad() override;
    virtual void onUnload() override;

private:
    void SetOnlineStatus(std::string eventName);
};

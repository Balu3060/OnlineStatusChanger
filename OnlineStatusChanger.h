#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/wrappers/includes.h"

class StatusOverrider : public BakkesMod::Plugin::BakkesModPlugin
{
public:
    virtual void onLoad() override;
    virtual void onUnload() override;

    void OnMatchEnd(std::string eventName);
    void OnMatchStart(std::string eventName);
    void UpdateMMR();
    void Render(CanvasWrapper canvas);

private:
    float lastKnownMMR = -1.0f;
    float sessionMMRChange = 0.0f;
    
    struct MMRData {
        int totalWins = 0;
        int totalLosses = 0;
        int streak = 0;
    } stats;
};

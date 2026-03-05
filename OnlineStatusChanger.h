#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/wrappers/includes.h"

class StatusOverrider : public BakkesMod::Plugin::BakkesModPlugin
{
public:
    virtual void onLoad() override;
    virtual void onUnload() override;

    void OnMatchEnd(std::string eventName);
    void Render(CanvasWrapper canvas);

private:
    int sessionStartMMR = -1;
    int currentMMR = -1;
    
    struct MMRData {
        int totalWins = 0;
        int totalLosses = 0;
        int streak = 0;
        int savedMMR = 0;
    } stats;
};

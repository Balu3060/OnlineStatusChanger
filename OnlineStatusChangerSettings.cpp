#include "OnlineStatusChanger.h"
#include "imgui/imgui.h"

void OnlineStatusChanger::SetImGuiContext(uintptr_t ctx)
{
    ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

std::string OnlineStatusChanger::GetPluginName()
{
    return "Online Status Changer";
}

void OnlineStatusChanger::RenderSettings()
{
    CVarWrapper enableCvar = cvarManager->getCvar("cl_online_status_enable");
    if (!enableCvar) return;

    bool enabled = enableCvar.getBoolValue();
    if (ImGui::Checkbox("Enable Plugin", &enabled))
    {
        enableCvar.setValue(enabled);
    }

    CVarWrapper statusCvar = cvarManager->getCvar("cl_online_status_override");
    if (!statusCvar) return;

    int statusValue = statusCvar.getIntValue();
    if (ImGui::SliderInt("Status Override", &statusValue, 0, 3))
    {
        statusCvar.setValue(statusValue);
    }
}

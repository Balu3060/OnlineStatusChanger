#include "OnlineStatusChanger.h"
#include "imgui/imgui.h"

void StatusOverrider::SetImGuiContext(uintptr_t ctx)
{
    ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

std::string StatusOverrider::GetPluginName()
{
    return "Status Overrider";
}

void StatusOverrider::RenderSettings()
{
    CVarWrapper enableCvar = cvarManager->getCvar("cl_status_enable");
    if (!enableCvar) return;

    bool enabled = enableCvar.getBoolValue();
    if (ImGui::Checkbox("Enable Plugin", &enabled))
    {
        enableCvar.setValue(enabled);
    }

    CVarWrapper statusCvar = cvarManager->getCvar("cl_status_override");
    if (!statusCvar) return;

    int statusValue = statusCvar.getIntValue();
    if (ImGui::SliderInt("Status (0-3)", &statusValue, 0, 3))
    {
        statusCvar.setValue(statusValue);
    }
}

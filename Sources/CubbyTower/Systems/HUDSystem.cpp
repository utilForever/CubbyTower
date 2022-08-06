// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/HUD.hpp>
#include <CubbyTower/Components/TextRenderer.hpp>
#include <CubbyTower/Components/WaveManagerInfo.hpp>
#include <CubbyTower/Systems/HUDSystem.hpp>

namespace CubbyTower
{
void UpdateHUDSystem(entt::registry& registry)
{
    const HUD& hud = registry.get<HUD>(registry.view<Tag::HUD>()[0]);

    {
        TextRenderer& textRenderer =
            registry.get<TextRenderer>(hud.currentWaveLabel);

        if (registry.empty<Tag::WaveManager>())
        {
            textRenderer.text = "Finished";
        }
        else
        {
            auto waveManagerEntity = registry.view<Tag::WaveManager>()[0];
            WaveManagerInfo& waveManager =
                registry.get<WaveManagerInfo>(waveManagerEntity);

            textRenderer.text =
                "Wave " + std::to_string(waveManager.curWaveIndex + 1);
        }
    }

    {
        Gold& gold = registry.get<Gold>(registry.view<Tag::Player>()[0]);
        TextRenderer& textRenderer = registry.get<TextRenderer>(hud.goldLabel);

        textRenderer.text = "Gold: $" + std::to_string(gold.amount);
    }
}
}  // namespace CubbyTower

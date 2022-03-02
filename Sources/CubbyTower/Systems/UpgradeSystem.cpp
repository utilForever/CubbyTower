// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Components/UIContext.hpp>
#include <CubbyTower/Components/Upgradable.hpp>
#include <CubbyTower/Helpers/GoldHelpers.hpp>
#include <CubbyTower/Systems/UpgradeSystem.hpp>

namespace CubbyTower
{
void UpdateUpgradeSystem(entt::registry& registry)
{
    Inputs& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);
    const UIContext& uiContext =
        registry.get<UIContext>(registry.view<Tag::UIContext>()[0]);

    if (inputs.upgradeKeyState == InputState::JUST_DOWN &&
        uiContext.hover != entt::null)
    {
        if (registry.all_of<Upgradable>(uiContext.hover))
        {
            if (const auto& upgradable =
                    registry.get<Upgradable>(uiContext.hover);
                Withdraw(registry, registry.view<Tag::Player>()[0],
                         upgradable.cost))
            {
                upgradable.Upgrade(registry, uiContext.hover);
                inputs.upgradeKeyState = InputState::DOWN;
            }
        }
    }
}
}  // namespace CubbyTower
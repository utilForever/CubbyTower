// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Upgradable.hpp>
#include <CubbyTower/Helpers/GoldHelpers.hpp>
#include <CubbyTower/Systems/UpgradeSystem.hpp>

namespace CubbyTower
{
void UpdateUpgradeSystem(entt::registry& registry, entt::entity from)
{
    if (registry.all_of<Upgradable>(from))
    {
        if (const auto& upgradable = registry.get<Upgradable>(from); Withdraw(
                registry, registry.view<Tag::Player>()[0], upgradable.cost))
        {
            upgradable.Upgrade(registry, from);
        }
    }
}
}  // namespace CubbyTower
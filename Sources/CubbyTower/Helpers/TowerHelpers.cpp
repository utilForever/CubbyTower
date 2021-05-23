// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Helpers/GoldHelpers.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>

namespace CubbyTower
{
void BuyArrowTower(entt::registry& registry)
{
    // Check the player can buy arrow tower
    if (!Withdraw(registry, registry.view<Tag::Player>()[0],
                  ARROW_TOWER_LV1_PRICE))
    {
        return;
    }

    auto entity = registry.create();
    registry.emplace<Name>(entity, "Arrow Tower Lv 1");
}
}  // namespace CubbyTower
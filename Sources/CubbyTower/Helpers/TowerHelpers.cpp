// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/AttackRange.hpp>
#include <CubbyTower/Components/Damage.hpp>
#include <CubbyTower/Components/Distance.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/TargetMask.hpp>
#include <CubbyTower/Components/TargetPriority.hpp>
#include <CubbyTower/Components/Upgradable.hpp>
#include <CubbyTower/Helpers/GoldHelpers.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>

#include <optional>

namespace CubbyTower
{
void BuyArrowTower(entt::registry& registry, float x, float y)
{
    // Check the player can buy arrow tower
    if (!Withdraw(registry, registry.view<Tag::Player>()[0],
                  ARROW_TOWER_LV1_PRICE))
    {
        return;
    }

    auto entity = registry.create();
    registry.emplace<Tag::Tower>(entity);
    registry.emplace<Name>(entity, "Arrow Tower Lv 1");
    registry.emplace<Upgradable>(entity, ARROW_TOWER_LV2_PRICE,
                                 UpgradeArrowTowerLv2);
    registry.emplace<TargetMask>(entity, 0b110);
    registry.emplace<TargetPriority>(entity, 2, FirstEnemyTargeter);
    registry.emplace<Damage>(entity, 1);
    registry.emplace<AttackRange>(entity, 100.0);
    registry.emplace<Position>(entity, x, y);
}

void UpgradeArrowTowerLv2(entt::registry& registry, entt::entity entity)
{
    registry.replace<Name>(entity, "Arrow Tower Lv 2");
    registry.remove<Upgradable>(entity);
}

std::optional<entt::entity> FirstEnemyTargeter(
    entt::registry& registry, std::vector<entt::entity> attackable)
{
    if (attackable.empty())
    {
        return std::nullopt;
    }
    
    entt::entity target = attackable[0];
    for (int i = 1; i < static_cast<int>(attackable.size()); ++i)
    {
        double pre = registry.get<Distance>(target).distance;
        double cur = registry.get<Distance>(attackable[i]).distance;
        
        if (pre < cur)
        {
            target = attackable[i];
        }
    }
    
    return target;
}

}  // namespace CubbyTower

// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Damage.hpp>
#include <CubbyTower/Components/Destroyable.hpp>
#include <CubbyTower/Components/Health.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Helpers/ProjectileHelpers.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>

namespace CubbyTower
{
void UpdateAttackSystem(entt::registry& registry, float deltaTime)
{
    //for (auto tower : registry.view<Tag::Tower>())
    //{
    //    std::vector<entt::entity> attackable;
    //    // TODO: Add cooldown check

    //    for (auto enemy : registry.view<Tag::Enemy>())
    //    {
    //        const auto towerPos = registry.get<Position>(tower);
    //        const auto enemyPos = registry.get<Position>(enemy);

    //        if ((towerPos.x - enemyPos.x) * (towerPos.x - enemyPos.x) +
    //                (towerPos.y - enemyPos.y) * (towerPos.y - enemyPos.y) >
    //            attackRange * attackRange)
    //        {
    //            continue;
    //        }
    //    }

    //    const auto& priority = registry.get<TargetPriority>(tower);
    //    auto enemy = priority.Targeter(registry);

    //    if (enemy == entt::null)
    //    {
    //        continue;
    //    }

    //    CreateProjectile(registry, tower, enemy);
    //}
}
}  // namespace CubbyTower

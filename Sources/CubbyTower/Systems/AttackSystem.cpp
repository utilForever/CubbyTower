// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/AttackRange.hpp>
#include <CubbyTower/Components/TargetMask.hpp>
#include <CubbyTower/Components/Damage.hpp>
#include <CubbyTower/Components/HealthPoint.hpp>
#include <CubbyTower/Components/TypeMask.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>
#include <iostream>

namespace CubbyTower
{
void Attack(entt::registry& registry)
{
    for (auto tower : registry.view<Tag::Tower>())
    {
        for (auto enemy : registry.view<Tag::Enemy>())
        {
            const auto tPosition = registry.get<Position>(tower);
            const auto ePosition = registry.get<Position>(enemy);
            const auto attackRange = registry.get<AttackRange>(tower).attackRange;

            if ((tPosition.x - ePosition.x) * (tPosition.x - ePosition.x) + (tPosition.y - ePosition.y) * (tPosition.y - ePosition.y) > attackRange * attackRange)
            {
                continue;
            }

            const int damage = registry.get<Damage>(tower).damage;

            const int targetMask = registry.get<TargetMask>(tower).targetMask;
            const int typeMask = registry.get<TypeMask>(enemy).typeMask;

            if ((targetMask & typeMask) == typeMask)
            {
                // Todo : Consider the target priority, make a projectile
                //simple attack test
                auto& hp = registry.get<HealthPoint>(enemy);
                hp.healthPoint -= damage;
            }
        }
    }
}
}  // namespace CubbyTower
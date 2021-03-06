// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Damage.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Components/Velocity.hpp>
#include <CubbyTower/Helpers/ProjectileHelpers.hpp>

#include <cmath>

namespace CubbyTower
{
void CreateProjectile(entt::registry& registry, entt::entity tower,
                      entt::entity enemy)
{
    float speed = 1.0f;  // TODO: Add projectile speed component in tower

    auto entity = registry.create();
    registry.emplace<Tag::Projectile>(entity);
    registry.emplace<Damage>(entity, registry.get<Damage>(tower));
    // TODO: Add lifetime by attack range / speed
    registry.emplace<Size>(entity, 1.0f,
                           1.0f);  // TODO: Add projectile size in tower

    const auto towerPosition = registry.get<Position>(tower);
    const auto enemyPosition = registry.get<Position>(enemy);

    registry.emplace<Position>(entity, towerPosition);

    const Position positionDiff = { enemyPosition.x - towerPosition.x,
                                    enemyPosition.y - towerPosition.y };
    const float distance = std::sqrt(positionDiff.x * positionDiff.x +
                                     positionDiff.y * positionDiff.y);
    if (distance == 0.0f)
    {
        registry.emplace<Velocity>(entity, 0.0f, 0.0f);
        return;
    }

    registry.emplace<Velocity>(entity, speed * positionDiff.x / distance,
                               speed * positionDiff.y / distance);
}
}  // namespace CubbyTower
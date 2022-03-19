// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Velocity.hpp>
#include <CubbyTower/Systems/ProjectileSystem.hpp>

namespace CubbyTower
{
void UpdateProjectileSystem(entt::registry& registry, float deltaTime)
{
    registry.view<Tag::Projectile, Position, Velocity>().each(
        [&](auto entity, auto& pos, auto& vel) {
            // TODO : remove projectile when out of bound
            pos.x += vel.x * deltaTime;
            pos.y += vel.y * deltaTime;
        });
}
}  // namespace CubbyTower
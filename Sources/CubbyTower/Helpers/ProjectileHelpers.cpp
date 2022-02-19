// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Helpers/ProjectileHelpers.hpp>
#include <CubbyTower/Components/TargetMask.hpp>
#include <CubbyTower/Components/Damage.hpp>
#include <CubbyTower/Components/Velocity.hpp>
#include <cmath>
namespace CubbyTower
{
void CreateProjectile(entt::registry& registry, entt::entity tower, entt::entity enemy)
{


    float speed = 1.0; //TODO : add projectile speed component in tower

    auto entity = registry.create();
    registry.emplace<Tag::Projectile>(entity);
    registry.emplace<TargetMask>(entity, registry.get<TargetMask>(tower));
    registry.emplace<Damage>(entity, registry.get<Damage>(tower));
    // TODO : add lifetime by attackrange / speed
    registry.emplace<Size>(entity, 1.0f, 1.0f); // TODO : add projectile size in tower

    const auto towerPosition = registry.get<Position>(tower);
    const auto enemyPosition = registry.get<Position>(enemy);

    registry.emplace<Position>(entity, towerPosition);

    Position positionDiff = {enemyPosition.x - towerPosition.x, enemyPosition.y - towerPosition.y};

    float distance = sqrt(positionDiff.x * positionDiff.x + positionDiff.y * positionDiff.y);

    if (distance == 0){
        registry.emplace<Velocity>(entity, 0.0f, 0.0f);
        return;
    }

    registry.emplace<Velocity>(entity, speed * positionDiff.x / distance , speed * positionDiff.y / distance );


}
}  // namespace CubbyTower
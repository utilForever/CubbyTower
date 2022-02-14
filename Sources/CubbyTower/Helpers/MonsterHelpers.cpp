// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Distance.hpp>
#include <CubbyTower/Components/Enemy.hpp>
#include <CubbyTower/Components/Health.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/TypeMask.hpp>
#include <CubbyTower/Helpers/MonsterHelpers.hpp>

namespace CubbyTower
{
void CreateMonster(entt::registry& registry, int health, int typeMask,
                   std::function<void(entt::registry&, entt::entity)> OnDestroy)
{
    auto entity = registry.create();
    registry.emplace<Tag::Enemy>(entity);
    registry.emplace<TypeMask>(entity, typeMask);
    registry.emplace<Health>(entity, health);
    registry.emplace<Position>(entity, 0.0f, 0.0f);
    registry.emplace<Distance>(entity, 0.0f);
    registry.emplace<Enemy>(entity, OnDestroy);
}

void DestroyMonster(entt::registry& registry, entt::entity entity)
{
    registry.destroy(entity);
}
}  // namespace CubbyTower
// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Velocity.hpp>
#include <CubbyTower/Systems/ProjectileSystem.hpp>
#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[ProjectileSystem] - Moving Projectile")
{
    entt::registry registry;

    auto entity = registry.create();
    registry.emplace<Tag::Projectile>(entity);
    registry.emplace<Velocity>(entity, 1.0f, 2.0f);
    registry.emplace<Position>(entity, 0.0f, 0.0f);
    for (auto [proj, pos] : registry.view<Tag::Projectile, Position>().each())
    {
        CHECK_EQ(pos.x, 0.0f);
        CHECK_EQ(pos.y, 0.0f);
    }
    UpdateProjectileSystem(registry, 5.0f);
    for (auto [proj, pos] : registry.view<Tag::Projectile, Position>().each())
    {
        CHECK_EQ(pos.x, 5.0f);
        CHECK_EQ(pos.y, 10.0f);
    }
}
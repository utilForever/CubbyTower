// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Distance.hpp>
#include <CubbyTower/Components/Health.hpp>
#include <CubbyTower/Components/TypeMask.hpp>
#include <CubbyTower/Helpers/MonsterHelpers.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[MonsterHelpers] - Make several monsters")
{
    entt::registry registry;

    {
        auto view = registry.view<Tag::Enemy>();
        CHECK(view.empty());
    }

    CreateMonster(registry, 10, 0b010,
                  [](entt::registry& registry, entt::entity entity) {
                      DestroyMonster(registry, entity);
                  });

    {
        auto view = registry.view<Tag::Enemy>();
        CHECK_EQ(view.size(), 1);
        // NOTE: Multi-view don't know the number of items
    }

    {
        auto view = registry.view<Tag::Enemy, Health, TypeMask, Distance>();
        for (auto [enemy, health, type, dist] : view.each())
        {
            CHECK_EQ(health.curAmount, 10);
            CHECK_EQ(type.typeMask, 0b010);
            CHECK_EQ(dist.distance, 0.0);
        }
    }
}

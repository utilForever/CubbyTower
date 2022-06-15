// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Distance.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Systems/PathSystem.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[PathSystem] - UpdatePathSystem")
{
    entt::registry registry;

    auto enemy1 = registry.create();
    registry.emplace<Tag::Monster>(enemy1);
    registry.emplace<Position>(enemy1, 0.0f, 0.0f);
    registry.emplace<Distance>(enemy1, 5.0f);
    Path::UpdatePathSystem(registry);
    for (auto [enemy, pos] : registry.view<Tag::Monster, Position>().each())
    {
        CHECK_EQ(pos.x, 5.0);
        CHECK_EQ(pos.y, 300.0);
    }
}

// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Distance.hpp>
#include <CubbyTower/Systems/Path.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[Path] - Path")
{
    //Testing if position is changing as distance changes

    entt::registry registry;

    auto enemy = registry.create();
    registry.emplace<Tag::Enemy>(enemy);
    registry.emplace<Position>(enemy , 0.0, 0.0);
    registry.emplace<Distance>(enemy , 5.0);
    Path(registry);
    for (auto [enemy, pos] : registry.view<Tag::Enemy , Position>.each())
    {
        CHECK_EQ(pos.x, 5.0);
        CHECK_EQ(pos.y, 300.0);
    }





}
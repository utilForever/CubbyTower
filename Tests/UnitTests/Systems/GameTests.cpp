// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Systems/Game.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[Game] - Initialize")
{
    entt::registry registry;

    Game::Initialize(registry);

    auto view = registry.view<Tag::Player, Gold>();
    for (auto [entity, gold] : view.each())
    {
        CHECK_EQ(gold.amount, 500);
    }
}
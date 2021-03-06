// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[TowerHelpers] - BuyArrowTower")
{
    entt::registry registry;

    auto entity = registry.create();
    registry.emplace<Tag::Player>(entity);
    registry.emplace<Gold>(entity, 100);

    {
        auto view = registry.view<Tag::Tower>();
        CHECK_EQ(view.size(), 0);
    }

    Tower::BuyArrowTower(registry, Position{ 0.0f, 0.0f });

    {
        auto view = registry.view<Tag::Tower>();
        CHECK_EQ(view.size(), 1);
    }

    Tower::BuyArrowTower(registry, Position{ 0.0f, 100.0f });

    {
        auto view = registry.view<Tag::Tower>();
        CHECK_EQ(view.size(), 1);
    }
}
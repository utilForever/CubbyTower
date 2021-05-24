// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Systems/UpgradeSystem.hpp>

#include <entt/entt.hpp>

#include <iostream>

using namespace CubbyTower;

TEST_CASE("[UpgradeSystem] - UpdateUpgradeSystem")
{
    entt::registry registry;

    auto entity = registry.create();
    registry.emplace<Tag::Player>(entity);
    registry.emplace<Gold>(entity, 500);

    BuyArrowTower(registry);
    UpdateUpgradeSystem(registry, registry.view<Tag::Tower>()[0]);

    auto playerView = registry.view<Tag::Player, Gold>();
    for (auto [playerEntity, gold] : playerView.each())
    {
        CHECK_EQ(gold.amount, 200);
    }

    auto towerView = registry.view<Tag::Tower, Name>();
    for (auto [towerEntity, name] : towerView.each())
    {
        CHECK_EQ(name.name, "Arrow Tower Lv 2");
    }
}
// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Helpers/BankHelpers.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[GoldHelpers] - Withdraw")
{
    entt::registry registry;
    auto entity = registry.create();

    CHECK_FALSE(Bank::Withdraw(registry, entity, 100));

    registry.emplace<Gold>(entity, 100);
    CHECK(Bank::Withdraw(registry, entity, 50));
    CHECK_FALSE(Bank::Withdraw(registry, entity, 100));
}
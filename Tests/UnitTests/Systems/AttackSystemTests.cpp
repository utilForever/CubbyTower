// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/TargetMask.hpp>
#include <CubbyTower/Components/TypeMask.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>

#include <entt/entt.hpp>

#include <iostream>

using namespace CubbyTower;

TEST_CASE("[AttackSystem] - Attack")
{
    //Testing only Attack functions running right way
    //Todo : Real attack

    entt::registry registry;

    auto entity = registry.create();
    registry.emplace<Tag::Player>(entity);
    registry.emplace<Gold>(entity, 500);

    BuyArrowTower(registry);

    auto enemy1 = registry.create();
    registry.emplace<Tag::Enemy>(enemy1);
    registry.emplace<TypeMask>(enemy1, 0b010); //type : ground

    auto enemy2 = registry.create();
    registry.emplace<Tag::Enemy>(enemy2);
    registry.emplace<TypeMask>(enemy2, 0b011); //type : ground & stealth

    Attack(registry);
}
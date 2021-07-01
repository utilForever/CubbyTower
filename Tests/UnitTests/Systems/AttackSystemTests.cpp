// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/Targeter.hpp>
#include <CubbyTower/Components/Type.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>

#include <entt/entt.hpp>

#include <iostream>

using namespace CubbyTower;

TEST_CASE("[AttackSystem] - Attackable")
{
    //Testing only Attack functions return right way
    //Todo : Real attack

    entt::registry registry;

    auto entity = registry.create();
    registry.emplace<Tag::Player>(entity);
    registry.emplace<Gold>(entity, 500);

    BuyArrowTower(registry);

    auto enemy1 = registry.create();
    registry.emplace<Tag::Enemy>(enemy1);
    registry.emplace<Type>(enemy1, 0b010); //type : ground

    auto enemy2 = registry.create();
    registry.emplace<Tag::Enemy>(enemy2);
    registry.emplace<Type>(enemy2, 0b011); //type : ground & stealth

    auto enemyView = registry.view<Tag::Enemy, Type>();
    for (auto [enemyEntity, type] : enemyView.each())
    {
        if(type.type == 0b010)
            CHECK_EQ(Attack(registry, registry.view<Tag::Tower>()[0], enemyEntity), true);
        
        if(type.type == 0b011)
            CHECK_EQ(Attack(registry, registry.view<Tag::Tower>()[0], enemyEntity), false);
    }
    
    CHECK_EQ(Attack(registry, registry.view<Tag::Tower>()[0], registry.view<Tag::Tower>()[0]), false);
}
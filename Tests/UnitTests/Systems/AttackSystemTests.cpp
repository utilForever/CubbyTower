// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <doctest.h>

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/AttackRange.hpp>
#include <CubbyTower/Components/Damage.hpp>
#include <CubbyTower/Components/Distance.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/HealthPoint.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/TargetMask.hpp>
#include <CubbyTower/Components/TypeMask.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>
#include <CubbyTower/Systems/PathSystem.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[AttackSystem] - Attack")
{
    //Testing only Attack functions running right way
    //Todo : Real attack
    entt::registry registry;

    auto entity = registry.create();
    registry.emplace<Tag::Player>(entity);
    registry.emplace<Gold>(entity, 500);

    BuyArrowTower(registry, 300.0, 280.0);

    auto enemy1 = registry.create();
    registry.emplace<Tag::Enemy>(enemy1);
    registry.emplace<HealthPoint>(enemy1, 2);
    registry.emplace<TypeMask>(enemy1, 0b010); // Type: ground
    registry.emplace<Position>(enemy1, 0.0, 0.0);
    registry.emplace<Distance>(enemy1, 250.0);

    auto enemy2 = registry.create();
    registry.emplace<Tag::Enemy>(enemy2);
    registry.emplace<HealthPoint>(enemy2, 2);
    registry.emplace<TypeMask>(enemy2, 0b011); // Type: ground & stealth
    registry.emplace<Position>(enemy2, 0.0, 0.0);
    registry.emplace<Distance>(enemy2, 350.0);

    auto enemy3 = registry.create();
    registry.emplace<Tag::Enemy>(enemy3);
    registry.emplace<HealthPoint>(enemy3, 2);
    registry.emplace<TypeMask>(enemy3, 0b010); // Type: ground
    registry.emplace<Position>(enemy3, 0.0, 0.0);
    registry.emplace<Distance>(enemy3, 100.0);

    Path::UpdatePathSystem(registry);

    Attack(registry);

    for (auto [enemy, dist, hp, mask] : registry.view<Tag::Enemy, Distance, HealthPoint, TypeMask>().each())
    {
        if (mask.typeMask == 0b011)
        {
            CHECK_EQ(hp.hp, 2);
        }
        else if (dist.distance == 250)
        {
            CHECK_EQ(hp.hp, 1);
        }
        else if (dist.distance == 100)
        {
            CHECK_EQ(hp.hp, 2);
        }
    }
}

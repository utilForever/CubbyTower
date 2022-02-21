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
#include <CubbyTower/Components/Health.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/TargetMask.hpp>
#include <CubbyTower/Components/TypeMask.hpp>
#include <CubbyTower/Components/Velocity.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>
#include <CubbyTower/Systems/PathSystem.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[AttackSystem] - Attack")
{
    entt::registry registry;

    auto entity = registry.create();
    registry.emplace<Tag::Player>(entity);
    registry.emplace<Gold>(entity, 500);

    Tower::BuyArrowTower(registry, Position{ 300.0f, 280.0f });
    Tower::BuyArrowTower(registry, Position{ 600.0f, 280.0f });

    auto enemy1 = registry.create();
    registry.emplace<Tag::Enemy>(enemy1);
    registry.emplace<Health>(enemy1, 3);
    registry.emplace<TypeMask>(enemy1, 0b010);  // Type: ground
    registry.emplace<Position>(enemy1, 0.0f, 0.0f);
    registry.emplace<Distance>(enemy1, 300.0f);

    auto enemy2 = registry.create();
    registry.emplace<Tag::Enemy>(enemy2);
    registry.emplace<Health>(enemy2, 3);
    registry.emplace<TypeMask>(enemy2, 0b010);  // Type: ground
    registry.emplace<Position>(enemy2, 0.0f, 0.0f);
    registry.emplace<Distance>(enemy2, 250.0f);  // go further than enemy1

    auto enemy3 = registry.create();
    registry.emplace<Tag::Enemy>(enemy3);
    registry.emplace<Health>(enemy3, 3);
    registry.emplace<TypeMask>(enemy3, 0b011);  // Type: ground & stealth
    registry.emplace<Position>(enemy3, 0.0f, 0.0f);
    registry.emplace<Distance>(enemy3, 350.0f);

    auto enemy4 = registry.create();
    registry.emplace<Tag::Enemy>(enemy4);
    registry.emplace<Health>(enemy4, 3);
    registry.emplace<TypeMask>(enemy4, 0b010);  // Type: ground
    registry.emplace<Position>(enemy4, 0.0f, 0.0f);
    registry.emplace<Distance>(enemy4, 100.0f);

    Path::UpdatePathSystem(registry);

    UpdateAttackSystem(registry, 0.0f);

    for (auto [enemy, dist, hp, mask] :
         registry.view<Tag::Enemy, Distance, Health, TypeMask>().each())
    {
        if (mask.typeMask == 0b011)
        {
            CHECK_EQ(hp.curAmount, 3);
        }
        else if (dist.distance == 250)
        {
            CHECK_EQ(hp.curAmount, 3);
        }
        else if (dist.distance == 300)
        {
            CHECK_EQ(hp.curAmount, 3);
        }
        else if (dist.distance == 100)
        {
            CHECK_EQ(hp.curAmount, 3);
        }
    }
    for (auto [proj, vel] : registry.view<Tag::Projectile, Velocity>().each())
    {
        CHECK_EQ(vel.x, 0);
        CHECK_EQ(vel.y, 1.0);
    }
}

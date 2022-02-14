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
#include <CubbyTower/Components/Enemy.hpp>
#include <CubbyTower/Components/Health.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/TargetMask.hpp>
#include <CubbyTower/Components/TypeMask.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Helpers/MonsterHelpers.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>
#include <CubbyTower/Systems/PathSystem.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

TEST_CASE("[AttackSystem] - Attack")
{
    // Testing only Attack functions running right way
    // Todo : Real attack
    entt::registry registry;

    auto entity = registry.create();
    registry.emplace<Tag::Player>(entity);
    registry.emplace<Gold>(entity, 500);

    BuyArrowTower(registry, 300.0, 280.0);
    BuyArrowTower(registry, 600.0, 280.0);

    auto enemy1 = registry.create();

    registry.emplace<Tag::Enemy>(enemy1);
    registry.emplace<Health>(enemy1, 1);
    registry.emplace<TypeMask>(enemy1, 0b010);  // Type: ground
    registry.emplace<Position>(enemy1, 0.0f, 0.0f);
    registry.emplace<Distance>(enemy1, 300.0f);
    registry.emplace<Enemy>(enemy1, [](entt::registry& registry, entt::entity entity) {
        DestroyMonster(registry, entity);
    });

    auto enemy2 = registry.create();
    registry.emplace<Tag::Enemy>(enemy2);
    registry.emplace<Health>(enemy2, 3);
    registry.emplace<TypeMask>(enemy2, 0b010);  // Type: ground
    registry.emplace<Position>(enemy2, 0.0f, 0.0f);
    registry.emplace<Distance>(enemy2, 250.0f);  // go further than enemy1
    registry.emplace<Enemy>(enemy2, [](entt::registry& registry, entt::entity entity) {
        DestroyMonster(registry, entity);
    });

    auto enemy3 = registry.create();
    registry.emplace<Tag::Enemy>(enemy3);
    registry.emplace<Health>(enemy3, 3);
    registry.emplace<TypeMask>(enemy3, 0b011);  // Type: ground & stealth
    registry.emplace<Position>(enemy3, 0.0f, 0.0f);
    registry.emplace<Distance>(enemy3, 350.0f);
    registry.emplace<Enemy>(enemy3, [](entt::registry& registry, entt::entity entity) {
        DestroyMonster(registry, entity);
    });

    auto enemy4 = registry.create();
    registry.emplace<Tag::Enemy>(enemy4);
    registry.emplace<Health>(enemy4, 3);
    registry.emplace<TypeMask>(enemy4, 0b010);  // Type: ground
    registry.emplace<Position>(enemy4, 0.0f, 0.0f);
    registry.emplace<Distance>(enemy4, 100.0f);
    registry.emplace<Enemy>(enemy4, [](entt::registry& registry, entt::entity entity) {
        DestroyMonster(registry, entity);
    });

    Path::UpdatePathSystem(registry);

    {
        auto view = registry.view<Tag::Enemy>();
        CHECK_EQ(view.size(), 4);
    }

    // This will destroy enemy1
    Attack(registry);

    {
        auto view = registry.view<Tag::Enemy>();
        CHECK_EQ(view.size(), 3);
    }

    for (auto [enemy, dist, hp, mask] :
         registry.view<Tag::Enemy, Distance, Health, TypeMask>().each())
    {
        if (mask.typeMask == 0b011) // enemy3
        {
            CHECK_EQ(hp.curAmount, 3);
        }
        else if (dist.distance == 250) // enemy2
        {
            CHECK_EQ(hp.curAmount, 3);
        }
        else if (dist.distance == 100) // enemy4
        {
            CHECK_EQ(hp.curAmount, 3);
        }
    }

    // This will attack enemy 2
    Attack(registry);

    {
        auto view = registry.view<Tag::Enemy>();
        CHECK_EQ(view.size(), 3);
    }

    for (auto [enemy, dist, hp, mask] :
         registry.view<Tag::Enemy, Distance, Health, TypeMask>().each())
    {
        if (mask.typeMask == 0b011) // enemy3
        {
            CHECK_EQ(hp.curAmount, 3);
        }
        else if (dist.distance == 250) // enemy2
        {
            CHECK_EQ(hp.curAmount, 2);
        }
        else if (dist.distance == 100) // enemy4
        {
            CHECK_EQ(hp.curAmount, 3);
        }
    }

}

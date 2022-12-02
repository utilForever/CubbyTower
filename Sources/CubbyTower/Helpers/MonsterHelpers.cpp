// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Enums.hpp>
#include <CubbyTower/Commons/MapData.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/Health.hpp>
#include <CubbyTower/Components/Hoverable.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/ShapeRenderer.hpp>
#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Components/Speed.hpp>
#include <CubbyTower/Components/Target.hpp>
#include <CubbyTower/Components/TargetScore.hpp>
#include <CubbyTower/Components/Traveler.hpp>
#include <CubbyTower/Helpers/MonsterHelpers.hpp>
#include <CubbyTower/Helpers/ShapeHelpers.hpp>

#include <string>

namespace CubbyTower::Monster
{
struct Balloon_info
{
    constexpr static float NORMAL_BALLOON_SIZE[] = { 0.15f, 0.16f, 0.17f };
    constexpr static Color NORMAL_BALLOON_COLOR[] = {
        Color{ 251.0f / 255.0f, 242.0f / 255.0f, 54.0f / 255.0f, 1.0f },
        Color{ 54.0f / 255.0f, 242.0f / 255.0f, 251.0f / 255.0f, 1.0f },
        Color{ 242.0f / 255.0f, 54.0f / 255.0f, 251.0f / 255.0f, 1.0f }
    };
    constexpr static int NORMAL_BALLOON_GOLD[] = { 30, 40, 50 };
    constexpr static int NORMAL_BALLOON_HEALTH[] = { 30, 90, 160 };
};

void CreateNormalBalloon(entt::registry& registry, const Position& position)
{
    constexpr float size = Balloon_info::NORMAL_BALLOON_SIZE[0];
    constexpr float speed = 45.0f / 60.0f;

    auto entity = registry.create();
    registry.emplace<Tag::Monster>(entity);
    registry.emplace<Position>(entity, position);
    registry.emplace<Size>(entity, size, size);
    registry.emplace<Color>(entity, Balloon_info::NORMAL_BALLOON_COLOR[0]);
    registry.emplace<ShapeRenderer>(entity, Shape::DrawCircle);
    registry.emplace<Traveler>(entity, 0, GROUND_WAYPOINT_COUNT,
                               static_cast<const Position*>(GROUND_WAYPOINTS));
    registry.emplace<Name>(entity, "Normal Balloon Level 1");
    registry.emplace<Health>(entity, Balloon_info::NORMAL_BALLOON_HEALTH[0],
                             Balloon_info::NORMAL_BALLOON_HEALTH[0]);
    registry.emplace<Gold>(entity, Balloon_info::NORMAL_BALLOON_GOLD[0]);
    registry.emplace<Target>(entity, TargetMask{ GROUND });
    registry.emplace<Hoverable>(entity);
    registry.emplace<TargetScore>(entity, 0.0f);
    registry.emplace<Speed>(entity, speed, speed);
}

void CreateCustomNormalBalloon(entt::registry& registry,
                               const Position& position,
                               int& initialWayPointIndex, int level = 1)
{
    float size = Balloon_info::NORMAL_BALLOON_SIZE[level - 1];
    constexpr float speed = 45.0f / 60.0f;

    auto entity = registry.create();
    registry.emplace<Tag::Monster>(entity);
    registry.emplace<Position>(entity, position);
    registry.emplace<Size>(entity, size, size);
    registry.emplace<Color>(entity, Balloon_info::NORMAL_BALLOON_COLOR[level - 1]);
    registry.emplace<ShapeRenderer>(entity, Shape::DrawCircle);
    registry.emplace<Traveler>(entity, initialWayPointIndex,
                               GROUND_WAYPOINT_COUNT,
                               static_cast<const Position*>(GROUND_WAYPOINTS));
    registry.emplace<Name>(entity,
                           "Normal Balloon Level " + std::to_string(level));
    registry.emplace<Health>(entity, Balloon_info::NORMAL_BALLOON_HEALTH[level - 1],
                             Balloon_info::NORMAL_BALLOON_HEALTH[level - 1]);
    registry.emplace<Gold>(entity, Balloon_info::NORMAL_BALLOON_GOLD[level - 1]);
    registry.emplace<Target>(entity, TargetMask{ GROUND });
    registry.emplace<Hoverable>(entity);
    registry.emplace<TargetScore>(entity, 0.0f);
    registry.emplace<Speed>(entity, speed, speed);
}

void CreateNormalBalloonLv2(entt::registry& registry, const Position& position)
{
    constexpr float size = Balloon_info::NORMAL_BALLOON_SIZE[1];
    constexpr float speed = 45.0f / 60.0f;

    auto entity = registry.create();
    registry.emplace<Tag::Monster>(entity);
    registry.emplace<Position>(entity, position);
    registry.emplace<Size>(entity, size, size);
    registry.emplace<Color>(entity, Balloon_info::NORMAL_BALLOON_COLOR[1]);
    registry.emplace<ShapeRenderer>(entity, Shape::DrawCircle);
    registry.emplace<Traveler>(entity, 0, GROUND_WAYPOINT_COUNT,
                               static_cast<const Position*>(GROUND_WAYPOINTS));
    registry.emplace<Name>(entity, "Normal Balloon Level 2");
    registry.emplace<Health>(entity, Balloon_info::NORMAL_BALLOON_HEALTH[1],
                             Balloon_info::NORMAL_BALLOON_HEALTH[1]);
    registry.emplace<Gold>(entity, Balloon_info::NORMAL_BALLOON_GOLD[1]);
    registry.emplace<Target>(entity, TargetMask{ GROUND });
    registry.emplace<Hoverable>(entity);
    registry.emplace<TargetScore>(entity, 0.0f);
    registry.emplace<Speed>(entity, speed, speed);
}

void CreateNormalBalloonLv3(entt::registry& registry, const Position& position)
{
    constexpr float size = Balloon_info::NORMAL_BALLOON_SIZE[2];
    constexpr float speed = 45.0f / 60.0f;

    auto entity = registry.create();
    registry.emplace<Tag::Monster>(entity);
    registry.emplace<Position>(entity, position);
    registry.emplace<Size>(entity, size, size);
    registry.emplace<Color>(entity, Balloon_info::NORMAL_BALLOON_COLOR[2]);
    registry.emplace<ShapeRenderer>(entity, Shape::DrawCircle);
    registry.emplace<Traveler>(entity, 0, GROUND_WAYPOINT_COUNT,
                               static_cast<const Position*>(GROUND_WAYPOINTS));
    registry.emplace<Name>(entity, "Normal Balloon Level 3");
    registry.emplace<Health>(entity, Balloon_info::NORMAL_BALLOON_HEALTH[2],
                             Balloon_info::NORMAL_BALLOON_HEALTH[2]);
    registry.emplace<Gold>(entity, Balloon_info::NORMAL_BALLOON_GOLD[2]);
    registry.emplace<Target>(entity, TargetMask{ GROUND });
    registry.emplace<Hoverable>(entity);
    registry.emplace<TargetScore>(entity, 0.0f);
    registry.emplace<Speed>(entity, speed, speed);
}

void CreatePigeonBalloon(entt::registry& registry, const Position& position)
{
    constexpr float size = 0.13f;
    constexpr float speed = 150.0f / 60.0f;

    auto entity = registry.create();
    registry.emplace<Tag::Monster>(entity);
    registry.emplace<Position>(entity, position);
    registry.emplace<Size>(entity, size, size);
    registry.emplace<Color>(entity, Color{ 250.0f / 255.0f, 200.0f / 255.0f,
                                           251.0f / 255.0f, 1.0f });
    registry.emplace<ShapeRenderer>(entity, Shape::DrawBox);
    registry.emplace<Traveler>(entity, 0, GROUND_WAYPOINT_COUNT,
                               static_cast<const Position*>(GROUND_WAYPOINTS));
    registry.emplace<Name>(entity, "Pigeon Balloon");
    registry.emplace<Health>(entity, 50, 50);
    registry.emplace<Gold>(entity, 40);
    registry.emplace<Target>(entity, TargetMask{ GROUND });
    registry.emplace<Hoverable>(entity);
    registry.emplace<TargetScore>(entity, 0.0f);
    registry.emplace<Speed>(entity, speed, speed);
}

void CreateMOAB(entt::registry& registry, const Position& position)
{
    constexpr float size = 0.25f;
    constexpr float speed = 20.0f / 60.0f;

    auto entity = registry.create();
    registry.emplace<Tag::Monster>(entity);
    registry.emplace<Position>(entity, position);
    registry.emplace<Size>(entity, size, size);
    registry.emplace<Color>(entity, Color{ 250.0f / 255.0f, 200.0f / 255.0f,
                                           251.0f / 255.0f, 1.0f });
    registry.emplace<ShapeRenderer>(entity, Shape::DrawBox);
    registry.emplace<Traveler>(entity, 0, GROUND_WAYPOINT_COUNT,
                               static_cast<const Position*>(GROUND_WAYPOINTS));
    registry.emplace<Name>(entity, "MOAB");
    registry.emplace<Health>(entity, 300, 300);
    registry.emplace<Gold>(entity, 80);
    registry.emplace<Target>(entity, TargetMask{ GROUND });
    registry.emplace<Hoverable>(entity);
    registry.emplace<TargetScore>(entity, 0.0f);
    registry.emplace<Speed>(entity, speed, speed);
}
}  // namespace CubbyTower::Monster
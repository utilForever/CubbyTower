// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/TargetScore.hpp>
#include <CubbyTower/Components/Traveler.hpp>
#include <CubbyTower/Systems/TravelSystem.hpp>

#include <cmath>

namespace CubbyTower
{
void UpdateMonsterTargetScoreSystem(entt::registry& registry)
{
    registry.view<Traveler, Position, TargetScore>().each(
        [&]([[maybe_unused]] auto entity, Traveler& traveler,
            const Position& position, TargetScore& targetScore) {
            const float tilesPercent =
                static_cast<float>(traveler.nextWaypointIndex) /
                static_cast<float>(traveler.waypointCount);
            const Position& lastWaypointPos =
                traveler.waypoints[traveler.nextWaypointIndex - 1];
            const Position& nextWaypointPos =
                traveler.waypoints[traveler.nextWaypointIndex];

            float dx = nextWaypointPos.x - lastWaypointPos.x;
            float dy = nextWaypointPos.y - lastWaypointPos.y;
            const float tileSize = std::sqrt(dx * dx + dy * dy);

            dx = lastWaypointPos.x - position.x;
            dy = lastWaypointPos.y - position.y;
            const float distToPrev = std::sqrt(dx * dx + dy * dy);

            targetScore.score =
                tilesPercent + distToPrev / tileSize /
                                   static_cast<float>(traveler.waypointCount);
        });
}
}  // namespace CubbyTower

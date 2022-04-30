// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Speed.hpp>
#include <CubbyTower/Components/Traveler.hpp>
#include <CubbyTower/Systems/TravelSystem.hpp>

namespace CubbyTower
{
void UpdateTravelSystem(entt::registry& registry, float deltaTime)
{
    registry.view<Traveler, Position, Speed>().each(
        [&registry, &deltaTime]([[maybe_unused]] auto entity,
                                Traveler& traveler, Position& position,
                                const Speed& speed) {
            int nextIdx = traveler.nextWaypointIndex;
            Position curPos = position;
            Position nextPos = traveler.waypoints[nextIdx];
            float dx = nextPos.x - curPos.x;
            float dy = nextPos.y - curPos.y;
            float dist = std::sqrtf(dx * dx + dy * dy);
            float newDist = dist - speed.curSpeed * deltaTime;

            while (newDist <= 0.0f)
            {
                ++nextIdx;

                if (nextIdx >= traveler.waypointCount)
                {
                    // Remove this entity (We have reached the end)
                    registry.destroy(entity);
                    return;
                }

                nextPos = traveler.waypoints[nextIdx];
                dx = nextPos.x - curPos.x;
                dy = nextPos.y - curPos.y;
                dist = std::sqrtf(dx * dx + dy * dy);
                newDist += dist;
            }

            curPos.x = nextPos.x - dx / dist * newDist;
            curPos.y = nextPos.y - dy / dist * newDist;

            traveler.nextWaypointIndex = nextIdx;
            position = curPos;
        });
}
}  // namespace CubbyTower

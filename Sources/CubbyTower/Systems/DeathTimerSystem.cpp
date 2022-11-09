// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/DeathTimer.hpp>
#include <CubbyTower/Systems/DeathTimerSystem.hpp>

namespace CubbyTower
{
void UpdateDeathTimerSystem(entt::registry& registry, float deltaTime)
{
    registry.view<DeathTimer>().each(
        [&registry, deltaTime](auto entity, DeathTimer& deathTimer) {
            const float delay = deathTimer.delay - deltaTime;

            if (delay <= 0.0f)
            {
                registry.destroy(entity);
                return;
            }

            deathTimer.delay = delay;
        });
}
}  // namespace CubbyTower

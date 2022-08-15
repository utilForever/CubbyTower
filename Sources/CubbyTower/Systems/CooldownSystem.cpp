// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Cooldown.hpp>
#include <CubbyTower/Components/FindTarget.hpp>
#include <CubbyTower/Systems/CooldownSystem.hpp>

namespace CubbyTower
{
void UpdateCooldownSystem(entt::registry& registry, float deltaTime)
{
    registry.view<Cooldown>().each(
        [&registry, deltaTime](auto entity, Cooldown& cooldown) {
            const float delay = cooldown.delay - deltaTime;

            if (delay <= 0.0f)
            {
                registry.remove<Cooldown>(entity);
                registry.emplace<FindTarget>(entity);
                return;
            }

            cooldown.delay = delay;
        });
}
}  // namespace CubbyTower

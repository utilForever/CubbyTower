// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Cooldown.hpp>
#include <CubbyTower/Components/FindTarget.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Target.hpp>
#include <CubbyTower/Components/TargetScore.hpp>
#include <CubbyTower/Components/Targeter.hpp>
#include <CubbyTower/Systems/TargetingSystem.hpp>

namespace CubbyTower
{
void UpdateTargetingSystem(entt::registry& registry)
{
    registry.view<Targeter, FindTarget, Position>().each(
        [&registry]([[maybe_unused]] auto entity, const Targeter& targeter,
                    const FindTarget& findTarget, const Position& position) {
            const float rangeSqr = targeter.range * targeter.range;
            entt::entity targetEntity = entt::null;
            float score = 0.0f;

            registry.view<Target, Position, TargetScore>().each(
                [&rangeSqr, &position, &targetEntity, &targeter, &score](
                    [[maybe_unused]] auto entity, const Target& target,
                    const Position& monsterPosition,
                    const TargetScore& targetScore) {
                    if (target.mask & targeter.targetMask)
                    {
                        const float dx = monsterPosition.x - position.x;
                        const float dy = monsterPosition.y - position.y;
                        const float distSqr = dx * dx + dy * dy;

                        if (distSqr <= rangeSqr && targetScore.score >= score)
                        {
                            targetEntity = entity;
                            score = targetScore.score;
                        }
                    }
                });

            if (targetEntity != entt::null)
            {
                // Shoot at target
                registry.remove<FindTarget>(entity);
                registry.emplace<Cooldown>(entity, targeter.cooldown);
                targeter.Shoot(registry, targetEntity, entity);
            }
        });
}
}  // namespace CubbyTower

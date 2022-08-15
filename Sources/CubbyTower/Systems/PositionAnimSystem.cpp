// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/PositionAnim.hpp>
#include <CubbyTower/Systems/PositionAnimSystem.hpp>

namespace CubbyTower
{
void UpdatePositionAnimSystem(entt::registry& registry, float deltaTime)
{
    registry.view<PositionAnim, Position>().each(
        [&registry, deltaTime]([[maybe_unused]] auto entity,
                               PositionAnim& positionAnim, Position& position) {
            const float anim = positionAnim.anim + deltaTime;
            const float ratio =
                std::min(anim, positionAnim.duration) / positionAnim.duration;

            position.x = positionAnim.from.x +
                         (positionAnim.to.x - positionAnim.from.x) * ratio;
            position.y = positionAnim.from.y +
                         (positionAnim.to.y - positionAnim.from.y) * ratio;
            positionAnim.anim = anim;

            if (anim >= positionAnim.duration)
            {
                positionAnim.OnAnim(registry, entity);
            }
        });
}
}  // namespace CubbyTower

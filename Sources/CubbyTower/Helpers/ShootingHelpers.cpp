// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/PositionAnim.hpp>
#include <CubbyTower/Components/ShapeRenderer.hpp>
#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Helpers/ShapeHelpers.hpp>
#include <CubbyTower/Helpers/ShootingHelpers.hpp>

namespace CubbyTower::Shooting
{
void CreateArrow(entt::registry& registry, const Position& from,
                 const Position& to)
{
    const float dx = to.x - from.x;
    const float dy = to.y - from.y;
    const float len = std::sqrtf(dx * dx + dy * dy);

    auto entity = registry.create();
    registry.emplace<Position>(entity, from);
    registry.emplace<PositionAnim>(entity, from, to, 0.0f, len / 10.0f);
    registry.emplace<ShapeRenderer>(entity, Shape::DrawBox);
    registry.emplace<Size>(entity, 0.15f, 0.15f);
    registry.emplace<Color>(entity, Color{ 0.0f, 1.0f, 1.0f, 1.0f });
}
}  // namespace CubbyTower::Shooting
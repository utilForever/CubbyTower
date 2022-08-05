// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Damage.hpp>
#include <CubbyTower/Components/DeathTimer.hpp>
#include <CubbyTower/Components/Health.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/PositionAnim.hpp>
#include <CubbyTower/Components/ShapeRenderer.hpp>
#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Components/SizePulseAnim.hpp>
#include <CubbyTower/Helpers/ShapeHelpers.hpp>
#include <CubbyTower/Helpers/ShootingHelpers.hpp>

namespace CubbyTower::Shooting
{
static void OnCollideArrow(entt::registry& registry, entt::entity entity)
{
    auto impactPoint = registry.get<Position>(entity);
    auto color = registry.get<Color>(entity);
    auto damage = registry.get<Damage>(entity);

    registry.destroy(entity);

    registry.view<Health, Position>().each(
        [&registry, impactPoint, damage](entt::entity entity,
                                         [[maybe_unused]] const Health& health,
                                         const Position& position) {
            auto dx = position.x - impactPoint.x;
            auto dy = position.y - impactPoint.y;
            auto dist = dx * dx + dy * dy;

            if (dist < 0.5f)
            {
                GiveDamage(registry, entity, damage.damage);
            }
        });

    auto fxEntity = registry.create();
    registry.emplace<Position>(fxEntity, impactPoint);
    registry.emplace<DeathTimer>(fxEntity, 0.4f);
    registry.emplace<Size>(fxEntity, 0.5f);
    registry.emplace<ShapeRenderer>(fxEntity, Shape::DrawCircle);
    registry.emplace<SizePulseAnim>(fxEntity, 0.0f, 25.0f, 0.15f, 0.5f);
    registry.emplace<Color>(fxEntity, color);
}

void CreateArrow(entt::registry& registry, const Position& from,
                 const Position& to, int damage)
{
    const float dx = to.x - from.x;
    const float dy = to.y - from.y;
    const float len = std::sqrtf(dx * dx + dy * dy);

    auto entity = registry.create();
    registry.emplace<Position>(entity, from);
    registry.emplace<PositionAnim>(entity, from, to, 0.0f, len / 10.0f,
                                   OnCollideArrow);
    registry.emplace<ShapeRenderer>(entity, Shape::DrawBox);
    registry.emplace<Size>(entity, 0.15f, 0.15f);
    registry.emplace<Color>(entity, Color{ 0.0f, 1.0f, 1.0f, 1.0f });
    registry.emplace<Damage>(entity, damage);
}

void GiveDamage(entt::registry& registry, entt::entity& target, int damage)
{
    if (!registry.all_of<Health>(target))
    {
        return;
    }

    auto& health = registry.get<Health>(target);
    health.curAmount -= damage;

    if (health.curAmount <= 0)
    {
        // TODO: Kill a target
    }
}
}  // namespace CubbyTower::Shooting
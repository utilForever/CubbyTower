// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/AttackRange.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Damage.hpp>
#include <CubbyTower/Components/Distance.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/Placer.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/ShapeRenderer.hpp>
#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Components/SizePulseAnim.hpp>
#include <CubbyTower/Components/TargetMask.hpp>
#include <CubbyTower/Components/TargetPriority.hpp>
#include <CubbyTower/Components/TextRenderer.hpp>
#include <CubbyTower/Components/Upgradable.hpp>
#include <CubbyTower/Helpers/GoldHelpers.hpp>
#include <CubbyTower/Helpers/ShapeHelpers.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>

#include <optional>

namespace CubbyTower::Tower
{
void CreatePlacer(
    entt::registry& registry,
    const std::function<void(entt::registry&, const Position&)>& callback)
{
    registry.clear<Placer>();

    auto entity = registry.create();
    registry.emplace<Placer>(entity, callback);
    registry.emplace<Color>(entity, Color{ 0.0f, 1.0f, 1.0f, 0.75f });
    registry.emplace<Size>(entity, Size{ 0.45f, 0.45f });
    registry.emplace<ShapeRenderer>(entity, Shape::DrawBox);
    registry.emplace<SizePulseAnim>(entity, 0.0f, 20.0f, 0.35f, 0.45f);
}

void BuyArrowTower(entt::registry& registry, const Position& position)
{
    // Check the player can buy arrow tower
    if (!Withdraw(registry, registry.view<Tag::Player>()[0],
                  ARROW_TOWER_LV1_PRICE))
    {
        return;
    }

    auto entity = registry.create();
    registry.emplace<Tag::Tower>(entity);
    registry.emplace<Position>(entity, position);
    registry.emplace<Size>(entity, TOWER_SIZE, TOWER_SIZE);
    registry.emplace<Color>(entity, TOWER_LEVEL1_COLOR);
    registry.emplace<TextRenderer>(entity, "A", Color{ 0.0f, 0.0f, 0.0f, 0.0f },
                                   0.5f);
    registry.emplace<ShapeRenderer>(entity, Shape::DrawBox);
    registry.emplace<Name>(entity, "Arrow Tower Lv 1 - \"U\" upgrade $200");
    registry.emplace<Upgradable>(entity, ARROW_TOWER_LV2_PRICE,
                                 UpgradeArrowTowerLv2);
    registry.emplace<TargetMask>(entity, 0b110);
    registry.emplace<TargetPriority>(entity, 2, FirstEnemyTargeter);
    registry.emplace<Damage>(entity, 1);
    registry.emplace<AttackRange>(entity, 100.0);
}

void UpgradeArrowTowerLv2(entt::registry& registry, entt::entity entity)
{
    registry.replace<Color>(entity, TOWER_LEVEL2_COLOR);
    registry.replace<Name>(entity, "Arrow Tower Lv 2");
    registry.remove<Upgradable>(entity);
}

std::optional<entt::entity> FirstEnemyTargeter(
    entt::registry& registry, std::vector<entt::entity> attackable)
{
    if (attackable.empty())
    {
        return std::nullopt;
    }

    entt::entity target = attackable[0];
    for (int i = 1; i < static_cast<int>(attackable.size()); ++i)
    {
        double pre = registry.get<Distance>(target).distance;
        double cur = registry.get<Distance>(attackable[i]).distance;

        if (pre < cur)
        {
            target = attackable[i];
        }
    }

    return target;
}

}  // namespace CubbyTower::Tower

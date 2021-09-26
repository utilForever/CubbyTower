// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Components/TextRenderer.hpp>
#include <CubbyTower/Helpers/UIHelpers.hpp>

namespace CubbyTower::UI
{
void CreateTowerButton(
    entt::registry& registry, const char* caption, const Position& position,
    int price, std::function<void(entt::registry&, entt::entity)> onClick)
{
    auto entity = registry.create();
    registry.emplace<Position>(entity, position);
    registry.emplace<Size>(entity, Size{ 2.5f, 0.4f });
    registry.emplace<Color>(entity, Color{ 0.6f, 0.7f, 0.5f, 1.0f });
    registry.emplace<TextRenderer>(entity, caption,
                                   Color{ 0.0f, 0.0f, 0.0f, 0.0f }, 0.5f);
    registry.emplace<Name>(entity, std::to_string(price) + " Gold");
    //registry.emplace<ShapeRenderer>(entity, Shape::DrawBox);
    //registry.emplace<CashThresholdButtonToggler>(entity, price);
    //registry.emplace<Button>(entity, Color{ 0.3f, 0.7f, 0.5f, 1.0f }, onClick);
    //registry.emplace<Hoverable>(entity, Color{ 0.6f, 0.7f, 0.5f, 1.0f },
    //                            Color{ 1.0f, 1.0f, 0.8f, 1.0f });
}
}  // namespace CubbyTower::UI

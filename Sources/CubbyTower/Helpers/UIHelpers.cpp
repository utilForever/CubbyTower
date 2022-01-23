// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Button.hpp>
#include <CubbyTower/Components/CashButtonToggler.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Hoverable.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/ShapeRenderer.hpp>
#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Components/TextRenderer.hpp>
#include <CubbyTower/Helpers/ShapeHelpers.hpp>
#include <CubbyTower/Helpers/UIHelpers.hpp>

namespace CubbyTower::UI
{
entt::entity CreateLabel(entt::registry& registry, const char* text,
                         const Position& position, const Color& color,
                         float align)
{
    auto entity = registry.create();
    registry.emplace<Position>(entity, position);
    registry.emplace<Color>(entity, color);
    registry.emplace<TextRenderer>(entity, text,
                                   Color{ 0.0f, 0.0f, 0.0f, 0.0f }, align);

    return entity;
}

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
    registry.emplace<ShapeRenderer>(entity, Shape::DrawBox);
    registry.emplace<CashButtonToggler>(entity, price);
    registry.emplace<Button>(entity, Color{ 0.3f, 0.7f, 0.5f, 1.0f }, onClick);
    registry.emplace<Hoverable>(entity, Color{ 0.6f, 0.7f, 0.5f, 1.0f },
                                Color{ 1.0f, 1.0f, 0.8f, 1.0f });
}
}  // namespace CubbyTower::UI

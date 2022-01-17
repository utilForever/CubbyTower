// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_UI_HELPERS_HPP
#define CUBBYTOWER_UI_HELPERS_HPP

#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Position.hpp>

#include <entt/entt.hpp>

namespace CubbyTower::UI
{
//! Creates label to show text.
//! \param registry A registry that handles entities.
//! \param text The text to describe the label.
//! \param position The relative position of the label.
//! \param color The color of the label.
//! \param align The align of the label.
//! \return The created label entity.
entt::entity CreateLabel(entt::registry& registry, const char* text,
                         const Position& position, const Color& color,
                         float align);

//! Creates tower button to buy or upgrade.
//! \param registry A registry that handles entities.
//! \param caption The caption to describe the button.
//! \param position The relative position of the button.
//! \param price The price to buy or upgrade the tower.
//! \param onClick The callback when the user clicks the button.
void CreateTowerButton(
    entt::registry& registry, const char* caption, const Position& position,
    int price, std::function<void(entt::registry&, entt::entity)> onClick);
}  // namespace CubbyTower::UI

#endif  // CUBBYTOWER_UI_HELPERS_HPP
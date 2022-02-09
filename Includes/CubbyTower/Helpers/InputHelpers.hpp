// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_INPUT_HELPERS_HPP
#define CUBBYTOWER_INPUT_HELPERS_HPP

#include <SFML/Window/Mouse.hpp>
#include <entt/entt.hpp>

namespace CubbyTower::Input
{
//! Handles mouse button pressed event.
//! \param registry A registry that handles entities.
//! \param button The state of the mouse.
void OnMouseButtonPressed(entt::registry& registry, sf::Mouse::Button button);

//! Handles mouse button released event.
//! \param registry A registry that handles entities.
//! \param button The state of the mouse.
void OnMouseButtonReleased(entt::registry& registry, sf::Mouse::Button button);

//! Handles mouse moved event.
//! \param registry A registry that handles entities.
//! \param x The x position of the mouse.
//! \param y The y position of the mouse.
void OnMouseMoved(entt::registry& registry, int x, int y);
}  // namespace CubbyTower::Input

#endif  // CUBBYTOWER_INPUT_HELPERS_HPP
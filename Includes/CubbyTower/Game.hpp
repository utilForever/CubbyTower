// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_GAME_HPP
#define CUBBYTOWER_GAME_HPP

#include <entt/entt.hpp>

namespace CubbyTower::Game
{
//! Initializes entities that are needed to the game.
//! \param registry A registry that handles entities.
void Initialize(entt::registry& registry);

//! Simulates game system according to delta time.
//! \param registry A registry that handles entities.
//! \param deltaTime The delta time relation to hardware responsiveness.
void Simulate(entt::registry& registry, float deltaTime);

//! Updates game system according to delta time.
//! \param registry A registry that handles entities.
//! \param deltaTime The delta time relation to hardware responsiveness.
void Update(entt::registry& registry, float deltaTime);

//! Renders game system.
//! \param registry A registry that handles entities.
void Render(entt::registry& registry);
}  // namespace CubbyTower::Game

#endif  // CUBBYTOWER_GAME_HPP
// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_SPAWN_SYSTEM_HPP
#define CUBBYTOWER_SPAWN_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Update spawners that spawn wave entities.
//! \param registry A registry that handles entities.
//! \param deltaTime The delta time relation to hardware responsiveness.
void UpdateSpawnSystem(entt::registry& registry, float deltaTime);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_SPAWN_SYSTEM_HPP
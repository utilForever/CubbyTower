// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_COLLISION_SYSTEM_HPP
#define CUBBYTOWER_COLLISION_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Updates collision system.
//! \param registry A registry that handles entities.
void UpdateCollisionSystem(entt::registry& registry);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_COLLISION_SYSTEM_HPP
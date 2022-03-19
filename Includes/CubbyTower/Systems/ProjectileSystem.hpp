// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_PROJECTILE_SYSTEM_HPP
#define CUBBYTOWER_PROJECTILE_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Updates projectile system.
//! \param registry A registry that handles entities.
//! \param deltaTime The time passed from last projectile is updated.
void UpdateProjectileSystem(entt::registry& registry, float deltaTime);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_PROJECTILE_SYSTEM_HPP
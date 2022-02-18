// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_PROJECTILE_HELPERS_HPP
#define CUBBYTOWER_PROJECTILE_HELPERS_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Makes Projectile Heading from \p tower to \enemy that follows tower's aspects
//! \param registry A registry that handles entities.
//! \param tower The tower entity.
//! \param enemy A enemy entity which is being attacked
void CreateProjetile(entt::registry& registry, entt::entity tower, entt:entity enemy);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_PROJECTILE_HELPERS_HPP
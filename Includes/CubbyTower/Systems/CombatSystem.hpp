// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_COMBAT_SYSTEM_HPP
#define CUBBYTOWER_COMBAT_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! \p tower attacks the monsters from \p registry
//! \p tower chooses a monster(from \p registry) to attack, and adds the bullet to the \p registry.
//! \param registry A registry that handles entities.
//! \param from The tower entity.
bool Attack(entt::registry& registry, entt::entity tower);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_COMBAT_SYSTEM_HPP
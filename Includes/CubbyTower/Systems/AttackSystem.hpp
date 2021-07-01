// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_ATTACK_SYSTEM_HPP
#define CUBBYTOWER_ATTACK_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! \p tower attacks the \p enemy if enemy is attakable
//! return true if attackable, otherwise return false
//! \param registry A registry that handles entities.
//! \param tower The tower entity.
//! \param enemy The enemy entity.
bool Attack(entt::registry& registry, entt::entity tower, entt::entity enemy);
    
}  // namespace CubbyTower

#endif  // CUBBYTOWER_ATTACK_SYSTEM_HPP
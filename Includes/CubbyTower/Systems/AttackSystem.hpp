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
//! This function called every frame and handles all attacks in game.
//! \param registry A registry that handles entities.
void Attack(entt::registry& registry);
    
}  // namespace CubbyTower

#endif  // CUBBYTOWER_ATTACK_SYSTEM_HPP
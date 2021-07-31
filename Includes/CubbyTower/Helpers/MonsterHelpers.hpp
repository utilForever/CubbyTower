// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_MONSTER_HELPERS_HPP
#define CUBBYTOWER_MONSTER_HELPERS_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Creates a Monster
//! \param registry A registry that handles entities.
//! \param health The health of a monster that will be created
//! \param targetmask A mask that contains the type of a monster
void CreateMonster(entt::registry& registry, int health, int targetmask);

}  // namespace CubbyTower

#endif  // CUBBYTOWER_MONSTER_HELPERS_HPP
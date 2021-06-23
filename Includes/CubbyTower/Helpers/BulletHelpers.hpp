// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_BULLET_HELPERS_HPP
#define CUBBYTOWER_BULLET_HELPERS_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Create a bullet that 
//! Bullets are fired from the \p tower and arrive at the \p monster.
//! Attributes such as bullet shape, damage, freeze, and area of ​​damage vary depending on the \p tower.
//! Attributes such as bullet position, speed, direction vary depending on the \p tower's position and \p monster's position.
//! \param registry A registry that handles entities.
//! \param tower A tower that fired bullets
//! \param monster A monsters targeted by the tower
void CreateBullet(entt::registry& registry, entt::entity tower, entt::entity monster);

}  // namespace CubbyTower

#endif  // CUBBYTOWER_BULLET_HELPERS_HPP
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
struct Position;

namespace Monster
{
//! Creates a normal balloon.
//! \param registry A registry that handles entities.
//! \param position The position to place a normal balloon.
void CreateNormalBalloon(entt::registry& registry, const Position& position);
}  // namespace Monster
}  // namespace CubbyTower

#endif  // CUBBYTOWER_MONSTER_HELPERS_HPP

// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_SHOOTING_HELPERS_HPP
#define CUBBYTOWER_SHOOTING_HELPERS_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
struct Position;
struct Color;

namespace Shooting
{
//! Creates an arrow entity to shoot a target.
//! \param registry A registry that handles entities.
//! \param from The start position of the arrow for the arrow tower.
//! \param to The end position of the arrow for target.
void CreateArrow(entt::registry& registry, const Position& from,
                 const Position& to);

//! Gives a damage to a target.
//! \param registry A registry that handles entities.
//! \param target A target that takes a damage.
//! \param damage The amount of damage to take.
void GiveDamage(entt::registry& registry, entt::entity& target, int damage);
}  // namespace Shooting
}  // namespace CubbyTower

#endif  // CUBBYTOWER_SHOOTING_HELPERS_HPP
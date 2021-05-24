// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_GOLD_HELPERS_HPP
#define CUBBYTOWER_GOLD_HELPERS_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Withdraws \p amount from \p from's Gold component if enough gold in it, then
//! return true. Returns false otherwise and leave \p from's Gold untouched.
//! \param registry A registry that handles entities.
//! \param from The player entity.
//! \param amount The price to buy something.
bool Withdraw(entt::registry& registry, entt::entity from, int amount);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_GOLD_HELPERS_HPP
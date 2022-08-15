// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_BANK_HELPERS_HPP
#define CUBBYTOWER_BANK_HELPERS_HPP

#include <entt/entt.hpp>

namespace CubbyTower::Bank
{
//! Withdraws \p amount from \p from's Gold component if enough gold in it, then
//! return true. Returns false otherwise and leave \p from's Gold untouched.
//! \param registry A registry that handles entities.
//! \param from The player entity.
//! \param amount The price to buy something.
bool Withdraw(entt::registry& registry, entt::entity from, int amount);

//! Transfer all the money from \p from to \p to.
//! \param registry A registry that handles entities.
//! \param from The monster entity.
//! \param to The player entity.
void Transfer(entt::registry& registry, entt::entity from, entt::entity to);
}  // namespace CubbyTower::Bank

#endif  // CUBBYTOWER_BANK_HELPERS_HPP
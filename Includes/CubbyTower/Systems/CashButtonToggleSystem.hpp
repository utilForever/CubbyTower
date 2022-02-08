// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_CASH_BUTTON_TOGGLER_SYSTEM_HPP
#define CUBBYTOWER_CASH_BUTTON_TOGGLER_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Toggles buttons from enable/disable state depending on
//! the amount in the player's gold.
//! \param registry A registry that handles entities.
void UpdateCashButtonTogglerSystem(entt::registry& registry);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_CASH_BUTTON_TOGGLER_SYSTEM_HPP
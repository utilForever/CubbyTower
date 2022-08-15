// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_DEATH_TIMER_SYSTEM_HPP
#define CUBBYTOWER_DEATH_TIMER_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Update death timers then kill finished entities.
//! \param registry A registry that handles entities.
//! \param deltaTime The delta time relation to hardware responsiveness.
void UpdateDeathTimerSystem(entt::registry& registry, float deltaTime);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_DEATH_TIMER_SYSTEM_HPP
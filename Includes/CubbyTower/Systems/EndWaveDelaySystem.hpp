// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_END_WAVE_DELAY_SYSTEM_HPP
#define CUBBYTOWER_END_WAVE_DELAY_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Adds a little delay at the end of a wave before starting next wave.
//! \param registry A registry that handles entities.
//! \param deltaTime The delta time relation to hardware responsiveness.
void UpdateEndWaveDelaySystem(entt::registry& registry, float deltaTime);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_END_WAVE_DELAY_SYSTEM_HPP
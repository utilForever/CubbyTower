// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_END_WAVE_CHECK_SYSTEM_HPP
#define CUBBYTOWER_END_WAVE_CHECK_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Checks if the end wave condition is met.
//! \param registry A registry that handles entities.
void UpdateEndWaveCheckSystem(entt::registry& registry);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_END_WAVE_CHECK_SYSTEM_HPP
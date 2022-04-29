// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_WAVE_HELPERS_HPP
#define CUBBYTOWER_WAVE_HELPERS_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
namespace Wave
{
//! Create the main wave manager. There can only be one.
//! \param registry A registry that handles entities.
//! \return The created wave manager entity.
entt::entity CreateWaveManager(entt::registry& registry);
}  // namespace Wave
}  // namespace CubbyTower

#endif  // CUBBYTOWER_WAVE_HELPERS_HPP
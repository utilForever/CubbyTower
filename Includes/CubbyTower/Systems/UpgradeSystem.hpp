// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_UPGRADE_SYSTEM_HPP
#define CUBBYTOWER_UPGRADE_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Updates upgrade system.
//! \param registry A registry that handles entities.
//! \param from The tower entity to upgrade.
void UpdateUpgradeSystem(entt::registry& registry, entt::entity from);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_UPGRADE_SYSTEM_HPP
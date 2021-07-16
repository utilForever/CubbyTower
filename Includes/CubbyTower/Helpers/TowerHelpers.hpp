// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TOWER_HELPERS_HPP
#define CUBBYTOWER_TOWER_HELPERS_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Buys a arrow tower.
//! \param registry A registry that handles entities.
void BuyArrowTower(entt::registry& registry, double x, double y);

//! Upgrades a arrow tower to level 2.
//! \param registry A registry that handles entities.
//! \param entity A arrow tower entity to upgrade.
void UpgradeArrowTowerLv2(entt::registry& registry, entt::entity entity);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TOWER_HELPERS_HPP
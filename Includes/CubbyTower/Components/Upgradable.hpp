// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_UPGRADABLE_HPP
#define CUBBYTOWER_UPGRADABLE_HPP

#include <entt/entt.hpp>

#include <functional>

namespace CubbyTower
{
//!
//! \brief Upgradable struct.
//!
//! This struct stores the cost and the function to upgrade something.
//!
struct Upgradable
{
    int cost;
    std::function<void(entt::registry&, entt::entity)> Upgrade;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_UPGRADABLE_HPP
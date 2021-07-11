// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TARGET_PRIORITY_HPP
#define CUBBYTOWER_TARGET_PRIORITY_HPP

#include <entt/entt.hpp>

#include <functional>

namespace CubbyTower
{
//!
//! \brief TargetPriority struct.
//!
//! This struct stores the type of priority and finding target function.
//! priority : 1 => minimum distance, 2 => maximum distance, 3 => maximum healthPoint
//!
struct TargetPriority
{
    string priority = 2;
    std::function<void(entt::registry&, entt::entity)> Upgrade;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TARGET_PRIORITY_HPP
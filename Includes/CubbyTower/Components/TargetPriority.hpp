// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TARGET_PRIORITY_HPP
#define CUBBYTOWER_TARGET_PRIORITY_HPP

#include <entt/entt.hpp>
#include <functional>
#include <optional>
#include <vector>


namespace CubbyTower
{
//!
//! \brief TargetPriority struct.
//!
//! This struct stores the type of priority and finding target function
//! priority : 1 => first enemy, 2 => last enemy, 3 => maximum health
//!
struct TargetPriority
{
    int priority;
    std::function<std::optional<entt::entity>(entt::registry&,
                                              std::vector<entt::entity>)>
        Targeter;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TARGET_PRIORITY_HPP
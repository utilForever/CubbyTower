// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TARGETER_HPP
#define CUBBYTOWER_TARGETER_HPP

#include <CubbyTower/Commons/Enums.hpp>

#include <entt/entt.hpp>

#include <functional>

namespace CubbyTower
{
//!
//! \brief Targeter struct.
//!
//! This struct stores the information for seeking a target.
//!
struct Targeter
{
    TargetMask targetMask;
    float range;
    float cooldown;
    std::function<void(entt::registry&, entt::entity, entt::entity)> Shoot;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TARGETER_HPP
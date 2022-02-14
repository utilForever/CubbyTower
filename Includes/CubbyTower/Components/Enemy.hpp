// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_ENEMY_HPP
#define CUBBYTOWER_ENEMY_HPP

#include <entt/entt.hpp>

#include <functional>

namespace CubbyTower
{
//!
//! \brief Enemy struct.
//!
//! This struct defines basic properties of a enemy. It stores destroy event
//! OnDestroy callback.
//!
struct Enemy
{
    std::function<void(entt::registry&, entt::entity)> OnDestroy;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_ENEMY_HPP
// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_DESTROYABLE_HPP
#define CUBBYTOWER_DESTROYABLE_HPP

#include <entt/entt.hpp>

#include <functional>

namespace CubbyTower
{
//!
//! \brief Destroyable struct.
//!
//! This struct defines basic properties of a Destroyable. It stores destroy
//! event OnDestroy callback.
//!
struct Destroyable
{
    std::function<void(entt::registry&, entt::entity)> OnDestroy;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_DESTROYABLE_HPP
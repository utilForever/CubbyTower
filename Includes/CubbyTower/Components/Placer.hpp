// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_PLACER_HPP
#define CUBBYTOWER_PLACER_HPP

#include <functional>

namespace CubbyTower
{
struct Position;

//!
//! \brief Placer struct.
//!
//! This struct listens to inputs to place something on the map and
//! Place() is then called.
//!
struct Placer
{
    std::function<void(entt::registry&, const Position&)> Place;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_PLACER_HPP
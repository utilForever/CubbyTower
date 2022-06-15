// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_SPEED_HPP
#define CUBBYTOWER_SPEED_HPP

namespace CubbyTower
{
//!
//! \brief Speed struct.
//!
//! This struct stores the base and current speed for a unit. The systems will
//! first reset the entity's current speed to this before applying changes.
//!
struct Speed
{
    float baseSpeed;
    float curSpeed;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_SPEED_HPP
// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_COOLDOWN_HPP
#define CUBBYTOWER_COOLDOWN_HPP

namespace CubbyTower
{
//!
//! \brief Cooldown struct.
//!
//! This struct stores the data for cooldowns for attack cooldowns or ability
//! cooldowns. This is used by the tower, or abilities (might be added later).
//!
struct Cooldown
{
    float delay;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_COOLDOWN_HPP
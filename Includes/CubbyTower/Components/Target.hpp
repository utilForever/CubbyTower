// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TARGET_HPP
#define CUBBYTOWER_TARGET_HPP

#include <CubbyTower/Commons/Enums.hpp>

namespace CubbyTower
{
//!
//! \brief Target struct.
//!
//! This struct defines the entity as a target.
//!
struct Target
{
    TargetMask mask;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TARGET_HPP
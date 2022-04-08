// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_ENUMS_HPP
#define CUBBYTOWER_ENUMS_HPP

#include <cstdint>

namespace CubbyTower
{
//! \brief An enumerator for identifying target's type.
enum TargetMask : uint8_t
{
    GROUND = 1 << 0,
    AIR = 1 << 1,
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_ENUMS_HPP
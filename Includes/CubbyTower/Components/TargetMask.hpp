// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TARGETMASK_HPP
#define CUBBYTOWER_TARGETMASK_HPP

namespace CubbyTower
{
//!
//! \brief TargetMask struct.
//!
//! This struct stores whether the tower/bullet can attack the target.
//! 1 bit means attakable
//! 1<<2 : Air, 1<<1 : ground, 1 : stealth
//!
struct TargetMask
{
    int targetMask;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TARGETMASK_HPP
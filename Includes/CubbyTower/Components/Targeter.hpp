// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TARGETER_HPP
#define CUBBYTOWER_TARGETER_HPP

namespace CubbyTower
{
//!
//! \brief Targeter struct.
//!
//! This struct stores whether the tower/bullet can attack the target.
//! 1 bit means attakable
//! 100 : Air, 010 : ground, 001 : stealth
//!
struct Targeter
{
    int targeter;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TARGETER_HPP
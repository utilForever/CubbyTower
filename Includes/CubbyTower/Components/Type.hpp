// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TYPE_HPP
#define CUBBYTOWER_TYPE_HPP

namespace CubbyTower
{
//!
//! \brief STATE struct.
//!
//! This struct stores whether the enemy's type is air/ground/stealth.
//! 100 : Air, 010 : ground, 001 : stealth
//!
struct Type
{
    int type;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TYPE_HPP
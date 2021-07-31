// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TYPE_MASK_HPP
#define CUBBYTOWER_TYPE_MASK_HPP

namespace CubbyTower
{
//!
//! \brief TypeMask struct.
//!
//! This struct stores whether the entity's type is air/ground/stealth.
//! 1<<2 : Air, 1<<1 : ground, 1 : stealth
//!
struct TypeMask
{
    int typeMask;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TYPE_MASK_HPP
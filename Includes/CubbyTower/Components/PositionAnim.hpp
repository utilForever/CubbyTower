// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_POSITION_ANIM_HPP
#define CUBBYTOWER_POSITION_ANIM_HPP

#include <CubbyTower/Components/Position.hpp>

namespace CubbyTower
{
//!
//! \brief PositionAnim struct.
//!
//! This struct stores information for the position animation.
//!
struct PositionAnim
{
    Position from;
    Position to;

    float anim;
    float duration;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_POSITION_ANIM_HPP
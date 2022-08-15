// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TARGET_SCORE_HPP
#define CUBBYTOWER_TARGET_SCORE_HPP

namespace CubbyTower
{
//!
//! \brief TargetScore struct.
//!
//! This struct stores the score of the target.
//! Targeter will target entities with an higher target score first.
//!
struct TargetScore
{
    float score;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TARGET_SCORE_HPP
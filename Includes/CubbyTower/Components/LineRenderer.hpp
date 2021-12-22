// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_LINE_RENDERER_HPP
#define CUBBYTOWER_LINE_RENDERER_HPP

#include <CubbyTower/Components/Position.hpp>

namespace CubbyTower
{
//!
//! \brief LineRenderer struct.
//!
//! This struct stores the functor for rendering line.
//!
struct LineRenderer
{
    Position target;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_LINE_RENDERER_HPP
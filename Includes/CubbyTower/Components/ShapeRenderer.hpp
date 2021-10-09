// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_SHAPE_RENDERER_HPP
#define CUBBYTOWER_SHAPE_RENDERER_HPP

#include <functional>

namespace CubbyTower
{
struct Color;
struct Position;
struct VertexPC;

//!
//! \brief ShapeRenderer struct.
//!
//! This struct stores the functor for rendering shape.
//!
struct ShapeRenderer
{
    std::function<int(VertexPC*, const Position&, float, float, const Color&)>
        DrawShape;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_SHAPE_RENDERER_HPP
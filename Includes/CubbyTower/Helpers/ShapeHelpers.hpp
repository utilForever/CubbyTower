// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_SHAPE_HELPERS_HPP
#define CUBBYTOWER_SHAPE_HELPERS_HPP

#include <CubbyTower/Components/Position.hpp>

namespace CubbyTower
{
struct Color;
struct Position;
struct VertexPC;

namespace Shape
{
//! Draws an box shape. Note that this function doesn't render on the screen,
//! but generates vertices in vertices and returns the number of vertices added.
//! \param vertices A pointer indicates a list of vertices.
//! \param position The relative position of the shape.
//! \param width The width of the shape.
//! \param height The height of the shape.
//! \param color The color of the shape.
//! \return The number of vertices.
int DrawBox(VertexPC* vertices, const Position& position, float width,
            float height, const Color& color);

//! Draws an circle shape. Note that this function doesn't render on the screen,
//! but generates vertices in vertices and returns the number of vertices added.
//! \param vertices A pointer indicates a list of vertices.
//! \param position The relative position of the shape.
//! \param width The width of the shape.
//! \param height The height of the shape.
//! \param color The color of the shape.
//! \return The number of vertices.
int DrawCircle(VertexPC* vertices, const Position& position, float width,
               float height, const Color& color);
}  // namespace Shape
}  // namespace CubbyTower

#endif  // CUBBYTOWER_SHAPE_HELPERS_HPP
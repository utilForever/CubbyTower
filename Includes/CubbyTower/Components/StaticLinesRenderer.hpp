// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_STATIC_LINES_RENDERER_HPP
#define CUBBYTOWER_STATIC_LINES_RENDERER_HPP

#include <GL/gl3w.h>

namespace CubbyTower
{
//!
//! \brief StaticLinesRenderer struct.
//!
//! This struct stores the data for drawing static lines.
//! This is used by the map entity.
//!
struct StaticLinesRenderer
{
    GLuint vertexBuffer;
    GLsizei vertCount;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_STATIC_LINES_RENDERER_HPP
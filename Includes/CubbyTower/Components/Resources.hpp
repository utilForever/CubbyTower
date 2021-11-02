// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_RESOURCES_HPP
#define CUBBYTOWER_RESOURCES_HPP

#include <GL/gl3w.h>

namespace CubbyTower
{
struct VertexPC;

//!
//! \brief Resources struct.
//!
//! This struct stores resource handles.
//!
struct Resources
{
    GLuint programPC;
    GLuint vertexBuffer;
    VertexPC* pcVertices;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_RESOURCES_HPP
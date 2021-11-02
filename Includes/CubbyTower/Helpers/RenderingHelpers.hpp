// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_RENDERING_HELPERS_HPP
#define CUBBYTOWER_RENDERING_HELPERS_HPP

#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Position.hpp>

#include <entt/entt.hpp>
#include <GL/gl3w.h>

namespace CubbyTower
{
struct VertexPC
{
    Position position;
    Color color;
};

namespace Rendering
{
//! Prepare the rendering pipeline for Position + Color rendering.
//! \param registry A registry that handles entities.
void PrepareForPC(entt::registry& registry);

// Draw lines for Position + Color rendering.
//! \param registry A registry that handles entities.
//! \param vertices A pointer indicates a list of vertices.
//! \param count The number of vertices.
void DrawLines(entt::registry& registry, const VertexPC* vertices, int count);
}
}  // namespace CubbyTower

#endif  // CUBBYTOWER_RENDERING_HELPERS_HPP
// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_POINT_RENDER_SYSTEM_HPP
#define CUBBYTOWER_POINT_RENDER_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Draws entities that contains the component 'PointRenderers'.
//! \param registry A registry that handles entities.
void UpdatePointRenderSystem(entt::registry& registry);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_POINT_RENDER_SYSTEM_HPP
// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/LineRenderer.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>
#include <CubbyTower/Systems/LineRenderSystem.hpp>

namespace CubbyTower
{
void UpdateLineRenderSystem(entt::registry& registry)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);
    VertexPC* vertices = resources.pcVertices;

    registry.view<LineRenderer, Position, Color>().each(
        [&vertices]([[maybe_unused]] auto entity,
                    const LineRenderer& lineRenderer, const Position& position,
                    const Color& color) {
            vertices += Rendering::DrawLine(vertices, position,
                                            lineRenderer.target, color);
        });

    if (const auto count = vertices - resources.pcVertices; count)
    {
        Rendering::DrawLines(registry, resources.pcVertices,
                             static_cast<int>(count));
    }
}
}  // namespace CubbyTower

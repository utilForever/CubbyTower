// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/PointRenderer.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>
#include <CubbyTower/Systems/PointRenderSystem.hpp>

namespace CubbyTower
{
void UpdatePointRenderSystem(entt::registry& registry)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);
    VertexPC* vertices = resources.pcVertices;

    registry.view<PointRenderer, Position, Color>().each(
        [&vertices]([[maybe_unused]] auto entity,
                    [[maybe_unused]] const PointRenderer& pointRenderer,
                    const Position& position, const Color& color) {
            vertices->position = position;
            vertices->color = color;
            ++vertices;
        });

    if (const auto count = vertices - resources.pcVertices; count)
    {
        Rendering::DrawPoints(registry, resources.pcVertices,
                              static_cast<int>(count));
    }
}
}  // namespace CubbyTower

// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Components/ShapeRenderer.hpp>
#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>
#include <CubbyTower/Systems/ShapeRenderSystem.hpp>

namespace CubbyTower
{
void UpdateShapeRenderSystem(entt::registry& registry)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);
    VertexPC* vertices = resources.pcVertices;

    registry.view<ShapeRenderer, Position, Size, Color>().each(
        [&vertices](
            [[maybe_unused]] auto entity, const ShapeRenderer& shapeRenderer,
            const Position& position, const Size& size, const Color& color) {
            vertices += shapeRenderer.DrawShape(vertices, position, size.width,
                                                size.height, color);
        });
}
}  // namespace CubbyTower

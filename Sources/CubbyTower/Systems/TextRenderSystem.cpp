// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Components/TextRenderer.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>
#include <CubbyTower/Systems/TextRenderSystem.hpp>

namespace CubbyTower
{
void UpdateTextRenderSystem(entt::registry& registry)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);

    glBindTexture(GL_TEXTURE_2D, resources.fontTexture);

    VertexPTC* vertices = resources.ptcVertices;

    registry.view<TextRenderer, Position, Color>().each(
        [&vertices]([[maybe_unused]] auto entity,
                    const TextRenderer& textRenderer, const Position& position,
                    const Color& color) {
            vertices += Rendering::DrawSimpleText(
                vertices, textRenderer.text, position, textRenderer.bgColor,
                color, textRenderer.align);
        });

    if (const auto count = vertices - resources.ptcVertices; count)
    {
        Rendering::DrawQuads(registry, resources.ptcVertices,
                             static_cast<int>(count));
    }
}
}  // namespace CubbyTower

// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Health.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>
#include <CubbyTower/Systems/HealthBarRenderSystem.hpp>

namespace CubbyTower
{
void UpdateHealthBarRenderSystem(entt::registry& registry)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);
    VertexPC* vertices = resources.pcVertices;

    registry.view<Health, Position>().each(
        [&vertices]([[maybe_unused]] auto entity,
                    [[maybe_unused]] const Health& health,
                    const Position& position) {
            const auto ratio = static_cast<float>(health.curAmount) /
                               static_cast<float>(health.maxAmount);
            vertices += Rendering::DrawRect(vertices, position.x - 0.2f,
                                            position.y - 0.4f, 0.4f, 0.1f,
                                            Color{ 0.0f, 0.25f, 0.0f, 1.0f });
            vertices += Rendering::DrawRect(
                vertices, position.x - 0.2f, position.y - 0.4f, 0.4f * ratio,
                0.1f, Color{ 1.0f, 0.0f, 0.0f, 1.0f });
        });

    if (const auto count = vertices - resources.pcVertices; count)
    {
        Rendering::DrawQuads(registry, resources.pcVertices,
                             static_cast<int>(count));
    }
}
}  // namespace CubbyTower

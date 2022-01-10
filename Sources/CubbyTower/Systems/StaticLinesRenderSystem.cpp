// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/StaticLinesRenderer.hpp>
#include <CubbyTower/Systems/StaticLinesRenderSystem.hpp>

namespace CubbyTower
{
void UpdateStaticLinesRenderSystem(entt::registry& registry)
{
    registry.view<StaticLinesRenderer>().each(
        [&]([[maybe_unused]] auto entity,
            const StaticLinesRenderer& staticLinesRenderer) {
            glBindBuffer(GL_ARRAY_BUFFER, staticLinesRenderer.vertexBuffer);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 24,
                                  (float*)(uintptr_t)(0));
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 24,
                                  (float*)(uintptr_t)(8));
            glDrawArrays(GL_LINES, 0, staticLinesRenderer.vertCount);
        });
}
}  // namespace CubbyTower
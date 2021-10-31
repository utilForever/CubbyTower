// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>

namespace CubbyTower::Rendering
{
static void DrawPC(entt::registry& registry, const VertexPC* vertices,
                   int count, GLenum mode)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);

    glBindBuffer(GL_ARRAY_BUFFER, resources.vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexPC) * count, vertices,
                 GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(VertexPC),
                          (float*)(uintptr_t)(0));
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexPC),
                          (float*)(uintptr_t)(8));
    glDrawArrays(mode, 0, count);
}
}  // namespace CubbyTower::Rendering

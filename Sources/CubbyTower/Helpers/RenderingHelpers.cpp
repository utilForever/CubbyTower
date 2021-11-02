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
void SetTransform(entt::registry& registry, const float* matrix)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);

    {
        glUseProgram(resources.programPC);
        const auto uniform = glGetUniformLocation(resources.programPC, "ProjMtx");
        glUniformMatrix4fv(uniform, 1, GL_FALSE, matrix);
    }
}

void PrepareForPC(entt::registry& registry)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);

    glDisable(GL_TEXTURE_2D);
    glUseProgram(resources.programPC);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

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

void DrawLines(entt::registry& registry, const VertexPC* vertices, int count)
{
    DrawPC(registry, vertices, count, GL_LINES);
}
}  // namespace CubbyTower::Rendering

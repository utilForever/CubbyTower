// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
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

void BeginFrame(entt::registry& registry)
{
    constexpr float L = 0;
    constexpr float R = WIDTH;
    constexpr float T = 0;
    constexpr float B = HEIGHT;
    constexpr float S = 2.0f * ZOOM;
    constexpr float X = MAP_WIDTH / 2.0f * ZOOM / WIDTH;
    constexpr float Y = MAP_HEIGHT / 2.0f * ZOOM / HEIGHT / 4;

    constexpr GLfloat orthoProjection[4][4] = {
        { S / (R - L), 0.0f, 0.0f, 0.0f },
        { 0.0f, S / (T - B), 0.0f, 0.0f },
        { 0.0f, 0.0f, -1.0f, 0.0f },
        { (R + L) / (L - R) + X, (B + T) / (B - T) - Y, 0.0f, 1.0f },
    };

    SetTransform(registry, &orthoProjection[0][0]);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_CULL_FACE);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

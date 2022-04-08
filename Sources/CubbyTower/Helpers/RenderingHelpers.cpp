// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/MapData.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

static void CheckShader(GLuint handle)
{
    GLint result;
    glGetShaderiv(handle, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        GLchar infoLog[1024];
        glGetShaderInfoLog(handle, 1024, nullptr, infoLog);

        printf("Shader compile failed: %s\n", infoLog);
        assert(false);
    }
}

namespace CubbyTower::Rendering
{
GLuint CreateProgram(const GLchar* vertex, const GLchar* fragment,
                     const std::vector<const char*>& attributes)
{
    const GLchar* vertexShader[2] = { "#version 120\n", vertex };
    const GLchar* fragmentShader[2] = { "#version 120\n", fragment };

    const GLuint vertexHandle = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexHandle, 2, vertexShader, nullptr);
    glCompileShader(vertexHandle);
    CheckShader(vertexHandle);

    const GLuint fragmentHandle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentHandle, 2, fragmentShader, nullptr);
    glCompileShader(fragmentHandle);
    CheckShader(fragmentHandle);

    const GLuint program = glCreateProgram();
    glAttachShader(program, vertexHandle);
    glAttachShader(program, fragmentHandle);

    int idx = 0;

    for (const auto attr : attributes)
    {
        glBindAttribLocation(program, idx, attr);
        ++idx;
    }

    glLinkProgram(program);

    return program;
}

GLuint CreateTexture(const char* fileName)
{
    int x, y, n;
    unsigned char* data = stbi_load(fileName, &x, &y, &n, 4);

    GLuint handle;
    glGenTextures(1, &handle);
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, handle);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    stbi_image_free(data);

    return handle;
}

GLuint CreateVertexBuffer()
{
    GLuint handle;
    glGenBuffers(1, &handle);

    return handle;
}

GLuint CreateVertexBuffer(GLsizeiptr size, const void* data)
{
    GLuint handle;
    glGenBuffers(1, &handle);
    glBindBuffer(GL_ARRAY_BUFFER, handle);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    return handle;
}

void SetTransform(entt::registry& registry, const float* matrix)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);

    {
        glUseProgram(resources.programPC);
        const auto uniform =
            glGetUniformLocation(resources.programPC, "ProjMtx");
        glUniformMatrix4fv(uniform, 1, GL_FALSE, matrix);
    }

    {
        glUseProgram(resources.programPTC);
        const auto uniform =
            glGetUniformLocation(resources.programPTC, "ProjMtx");
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

void EndFrame()
{
    // Do nothing
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

void DrawPoints(entt::registry& registry, const VertexPC* vertices, int count)
{
    DrawPC(registry, vertices, count, GL_POINTS);
}

void DrawLines(entt::registry& registry, const VertexPC* vertices, int count)
{
    DrawPC(registry, vertices, count, GL_LINES);
}

void DrawQuads(entt::registry& registry, const VertexPC* vertices, int count)
{
    DrawPC(registry, vertices, count, GL_QUADS);
}

void PrepareForPTC(entt::registry& registry)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);

    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glUseProgram(resources.programPTC);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
}

static void DrawPTC(entt::registry& registry, const VertexPTC* vertices,
                    int count, GLenum mode)
{
    const Resources& resources =
        registry.get<Resources>(registry.view<Tag::Resources>()[0]);

    glBindBuffer(GL_ARRAY_BUFFER, resources.vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexPTC) * count, vertices,
                 GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(VertexPTC),
                          (float*)(uintptr_t)(0));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexPTC),
                          (float*)(uintptr_t)(8));
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(VertexPTC),
                          (float*)(uintptr_t)(16));
    glDrawArrays(mode, 0, count);
}

void DrawQuads(entt::registry& registry, const VertexPTC* vertices, int count)
{
    DrawPTC(registry, vertices, count, GL_QUADS);
}

int DrawLine(VertexPC* vertices, const Position& from, const Position& to,
             const Color& color)
{
    vertices[0].position.x = from.x;
    vertices[0].position.y = from.y;
    vertices[0].color = color;

    vertices[1].position.x = to.x;
    vertices[1].position.y = to.y;
    vertices[1].color = color;

    return 2;
}

int DrawRect(VertexPC* vertices, float x, float y, float w, float h,
             const Color& color)
{
    vertices[0].position.x = x;
    vertices[0].position.y = y;
    vertices[0].color = color;

    vertices[1].position.x = x;
    vertices[1].position.y = y + h;
    vertices[1].color = color;

    vertices[2].position.x = x + w;
    vertices[2].position.y = y + h;
    vertices[2].color = color;

    vertices[3].position.x = x + w;
    vertices[3].position.y = y;
    vertices[3].color = color;

    vertices += 4;

    return 4;
}

int DrawSimpleText(VertexPTC* vertices, const std::string& text,
                   const Position& position, const Color& bgColor,
                   const Color& color, float align)
{
    const float SIZE = 20.0f / ZOOM;

    Position pos = position;
    float w = static_cast<float>(text.size()) * TEXT_ADVANCE;
    pos.x -= w * align;
    pos.y -= SIZE / 2.0f;
    int vertCount = 0;

    // background
    vertices[0].position.x = pos.x;
    vertices[0].position.y = pos.y;
    vertices[0].texCoord = WHITE_UV;
    vertices[0].color = bgColor;

    vertices[1].position.x = pos.x;
    vertices[1].position.y = pos.y + SIZE;
    vertices[1].texCoord = WHITE_UV;
    vertices[1].color = bgColor;

    vertices[2].position.x = pos.x + w;
    vertices[2].position.y = pos.y + SIZE;
    vertices[2].texCoord = WHITE_UV;
    vertices[2].color = bgColor;

    vertices[3].position.x = pos.x + w;
    vertices[3].position.y = pos.y;
    vertices[3].texCoord = WHITE_UV;
    vertices[3].color = bgColor;
    vertices += 4;
    vertCount += 4;

    for (const auto c : text)
    {
        if (c < FIRST_CHAR || c > LAST_CHAR)
        {
            pos.x += TEXT_ADVANCE;
            continue;
        }

        auto index = c - FIRST_CHAR;
        const auto& uv1 = FONT[index][0];
        const auto& uv2 = FONT[index][1];

        vertices[0].position.x = pos.x;
        vertices[0].position.y = pos.y;
        vertices[0].texCoord.u = uv1.u;
        vertices[0].texCoord.v = uv1.v;
        vertices[0].color = color;

        vertices[1].position.x = pos.x;
        vertices[1].position.y = pos.y + SIZE;
        vertices[1].texCoord.u = uv1.u;
        vertices[1].texCoord.v = uv2.v;
        vertices[1].color = color;

        vertices[2].position.x = pos.x + SIZE;
        vertices[2].position.y = pos.y + SIZE;
        vertices[2].texCoord.u = uv2.u;
        vertices[2].texCoord.v = uv2.v;
        vertices[2].color = color;

        vertices[3].position.x = pos.x + SIZE;
        vertices[3].position.y = pos.y;
        vertices[3].texCoord.u = uv2.u;
        vertices[3].texCoord.v = uv1.v;
        vertices[3].color = color;

        vertices += 4;
        vertCount += 4;
        pos.x += TEXT_ADVANCE;
    }

    return vertCount;
}
}  // namespace CubbyTower::Rendering

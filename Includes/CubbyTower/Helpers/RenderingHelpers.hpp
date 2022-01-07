// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_RENDERING_HELPERS_HPP
#define CUBBYTOWER_RENDERING_HELPERS_HPP

#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/TexCoord.hpp>

#include <GL/gl3w.h>
#include <entt/entt.hpp>

namespace CubbyTower
{
struct VertexPC
{
    Position position;
    Color color;
};

struct VertexPTC
{
    Position position;
    TexCoord texCoord;
    Color color;
};

namespace Rendering
{
//! Create a shader program from vertex/fragment shader source.
//! \param vertex A source of vertex shader.
//! \param fragment A source of fragment shader.
//! \param attributes A list of attributes.
//! \return The return value of glCreateProgram().
GLuint CreateProgram(const GLchar* vertex, const GLchar* fragment,
                     const std::vector<const char*>& attributes);

//! Load a texture from an image file.
//! \param fileName The name of image file.
//! \return The handle of generated texture.
GLuint CreateTexture(const char* fileName);

//! Create an empty vertex buffer.
//! \return The handle of generated vertex buffer.
GLuint CreateVertexBuffer();

//! Create an static vertex buffer.
//! \param size The size of vertices array.
//! \param data A pointer indicates a list of vertices.
//! \return The handle of generated vertex buffer.
GLuint CreateVertexBuffer(GLsizeiptr size, const void* data);

//! Start a rendering frame. This will clear background to black and
//! set defaults render states.
//! \param registry A registry that handles entities.
void BeginFrame(entt::registry& registry);

//! End a rendering frame. It does nothing, but might eventually.
void EndFrame();

//! Prepare the rendering pipeline for Position + Color rendering.
//! \param registry A registry that handles entities.
void PrepareForPC(entt::registry& registry);

//! Draw points for Position + Color rendering.
//! \param registry A registry that handles entities.
//! \param vertices A pointer indicates a list of vertices.
//! \param count The number of vertices.
void DrawPoints(entt::registry& registry, const VertexPC* vertices, int count);

//! Draw lines for Position + Color rendering.
//! \param registry A registry that handles entities.
//! \param vertices A pointer indicates a list of vertices.
//! \param count The number of vertices.
void DrawLines(entt::registry& registry, const VertexPC* vertices, int count);

//! Draw quads for Position + Color rendering.
//! \param registry A registry that handles entities.
//! \param vertices A pointer indicates a list of vertices.
//! \param count The number of vertices.
void DrawQuads(entt::registry& registry, const VertexPC* vertices, int count);

//! Prepare the rendering pipeline for Position + TexCoord + Color rendering.
//! \param registry A registry that handles entities.
void PrepareForPTC(entt::registry& registry);

//! Draw quads for Position + Texture + Color rendering.
//! \param registry A registry that handles entities.
//! \param vertices A pointer indicates a list of vertices.
//! \param count The number of vertices.
void DrawQuads(entt::registry& registry, const VertexPTC* vertices, int count);

//! Draw a line for Position + Color rendering.
//! Note that this function doesn't render on the screen,
//! but generates vertices and returns the number of vertices added.
//! \param vertices A pointer indicates a list of vertices.
//! \param from The position that draws a line from.
//! \param to The position that draws a line to.
//! \param color The color of a line.
//! \Return The number of vertices.
int DrawLine(VertexPC* vertices, const Position& from, const Position& to,
             const Color& color);

//! Draw a rect for Position + Color rendering.
//! Note that this function doesn't render on the screen,
//! but generates vertices and returns the number of vertices added.
//! \param vertices A pointer indicates a rect of vertices.
//! \param x The left position of a rect.
//! \param y The top position of a rect.
//! \param w The width of a rect.
//! \param h The height of a rect.
//! \param color The color of a line.
//! \Return The number of vertices.
int DrawRect(VertexPC* vertices, float x, float y, float w, float h,
             const Color& color);

//! Draw a text for Position + Texture + Color rendering.
//! Note that this function doesn't render on the screen,
//! but generates vertices and returns the number of vertices added.
//! \param vertices A pointer indicates a list of vertices.
//! \param text The text to draw.
//! \param position The position that draws a text.
//! \param bgColor The background color.
//! \param color The color of a text.
//! \param align The align of a text.
//! \Return The number of vertices.
int DrawSimpleText(VertexPTC* vertices, const std::string& text,
                   const Position& position, const Color& bgColor,
                   const Color& color, float align);
}  // namespace Rendering
}  // namespace CubbyTower

#endif  // CUBBYTOWER_RENDERING_HELPERS_HPP
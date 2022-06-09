// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>
#include <CubbyTower/Helpers/ShapeHelpers.hpp>

#include <cmath>

namespace CubbyTower::Shape
{
int DrawBox(VertexPC* vertices, const Position& position, float width,
            float height, const Color& color)
{
    vertices[0].position.x = position.x - width;
    vertices[0].position.y = position.y - height;
    vertices[0].color = color;
    vertices[1].position.x = position.x + width;
    vertices[1].position.y = position.y - height;
    vertices[1].color = color;

    vertices[2].position.x = position.x - width;
    vertices[2].position.y = position.y + height;
    vertices[2].color = color;
    vertices[3].position.x = position.x + width;
    vertices[3].position.y = position.y + height;
    vertices[3].color = color;

    vertices[4].position.x = position.x - width;
    vertices[4].position.y = position.y - height;
    vertices[4].color = color;
    vertices[5].position.x = position.x - width;
    vertices[5].position.y = position.y + height;
    vertices[5].color = color;

    vertices[6].position.x = position.x + width;
    vertices[6].position.y = position.y - height;
    vertices[6].color = color;
    vertices[7].position.x = position.x + width;
    vertices[7].position.y = position.y + height;
    vertices[7].color = color;

    return 8;
}

int DrawCircle(VertexPC* vertices, const Position& position, float width,
               float height, const Color& color)
{
    constexpr float perStep = PI * 2 / 12.0f;
    float curStep = 0.0f;
    int vertCount = 0;

    while (curStep < PI * 2)
    {
        vertices[vertCount].position.x =
            position.x + std::cosf(curStep) * width;
        vertices[vertCount].position.y =
            position.y + std::sinf(curStep) * height;
        vertices[vertCount].color = color;

        ++vertCount;
        vertices[vertCount].position.x =
            position.x + std::cosf(curStep + perStep) * width;
        vertices[vertCount].position.y =
            position.y + std::sinf(curStep + perStep) * height;
        vertices[vertCount].color = color;

        curStep += perStep;
        ++vertCount;
    }

    return vertCount;
}
}  // namespace CubbyTower::Shape

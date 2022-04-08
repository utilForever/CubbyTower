// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_CONSTANTS_HPP
#define CUBBYTOWER_CONSTANTS_HPP

#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/TexCoord.hpp>

#include <string>

namespace CubbyTower
{
constexpr static float PI = 3.14159265358979323846264338327950288f;

constexpr static int WIDTH = 800;
constexpr static int HEIGHT = 600;
constexpr static float ZOOM = 32;

constexpr static int MAX_VERTICES = 100000;
constexpr static float TEXT_ADVANCE = 12.0f / ZOOM;

constexpr static Color TOWER_LEVEL1_COLOR = { 0.15f, 1.0f, 0.15f, 1.0f };
constexpr static Color TOWER_LEVEL2_COLOR = { 1.0f, 1.0f, 0.0f, 1.0f };

constexpr static float TOWER_SIZE = 0.4f;

constexpr static int FIRST_CHAR = '!';
constexpr static int LAST_CHAR = '~';
constexpr static TexCoord WHITE_UV = { static_cast<float>(0.0048828125),
                                       static_cast<float>(0.8125) };

constexpr static TexCoord FONT[][2] = {
    { { static_cast<float>(0), 0.0f },
      { static_cast<float>(0.009765625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.009765625), 0.0f },
      { static_cast<float>(0.01953125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.01953125), 0.0f },
      { static_cast<float>(0.029296875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.029296875), 0.0f },
      { static_cast<float>(0.0390625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.0390625), 0.0f },
      { static_cast<float>(0.048828125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.048828125), 0.0f },
      { static_cast<float>(0.05859375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.05859375), 0.0f },
      { static_cast<float>(0.068359375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.068359375), 0.0f },
      { static_cast<float>(0.078125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.078125), 0.0f },
      { static_cast<float>(0.087890625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.087890625), 0.0f },
      { static_cast<float>(0.09765625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.09765625), 0.0f },
      { static_cast<float>(0.107421875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.107421875), 0.0f },
      { static_cast<float>(0.1171875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.1171875), 0.0f },
      { static_cast<float>(0.126953125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.126953125), 0.0f },
      { static_cast<float>(0.13671875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.13671875), 0.0f },
      { static_cast<float>(0.146484375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.146484375), 0.0f },
      { static_cast<float>(0.15625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.15625), 0.0f },
      { static_cast<float>(0.166015625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.166015625), 0.0f },
      { static_cast<float>(0.17578125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.17578125), 0.0f },
      { static_cast<float>(0.185546875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.185546875), 0.0f },
      { static_cast<float>(0.1953125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.1953125), 0.0f },
      { static_cast<float>(0.205078125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.205078125), 0.0f },
      { static_cast<float>(0.21484375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.21484375), 0.0f },
      { static_cast<float>(0.224609375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.224609375), 0.0f },
      { static_cast<float>(0.234375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.234375), 0.0f },
      { static_cast<float>(0.244140625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.244140625), 0.0f },
      { static_cast<float>(0.25390625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.25390625), 0.0f },
      { static_cast<float>(0.263671875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.263671875), 0.0f },
      { static_cast<float>(0.2734375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.2734375), 0.0f },
      { static_cast<float>(0.283203125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.283203125), 0.0f },
      { static_cast<float>(0.29296875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.29296875), 0.0f },
      { static_cast<float>(0.302734375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.302734375), 0.0f },
      { static_cast<float>(0.3125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.3125), 0.0f },
      { static_cast<float>(0.322265625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.322265625), 0.0f },
      { static_cast<float>(0.33203125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.33203125), 0.0f },
      { static_cast<float>(0.341796875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.341796875), 0.0f },
      { static_cast<float>(0.3515625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.3515625), 0.0f },
      { static_cast<float>(0.361328125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.361328125), 0.0f },
      { static_cast<float>(0.37109375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.37109375), 0.0f },
      { static_cast<float>(0.380859375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.380859375), 0.0f },
      { static_cast<float>(0.390625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.390625), 0.0f },
      { static_cast<float>(0.400390625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.400390625), 0.0f },
      { static_cast<float>(0.41015625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.41015625), 0.0f },
      { static_cast<float>(0.419921875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.419921875), 0.0f },
      { static_cast<float>(0.4296875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.4296875), 0.0f },
      { static_cast<float>(0.439453125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.439453125), 0.0f },
      { static_cast<float>(0.44921875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.44921875), 0.0f },
      { static_cast<float>(0.458984375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.458984375), 0.0f },
      { static_cast<float>(0.46875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.46875), 0.0f },
      { static_cast<float>(0.478515625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.478515625), 0.0f },
      { static_cast<float>(0.48828125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.48828125), 0.0f },
      { static_cast<float>(0.498046875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.498046875), 0.0f },
      { static_cast<float>(0.5078125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.5078125), 0.0f },
      { static_cast<float>(0.517578125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.517578125), 0.0f },
      { static_cast<float>(0.52734375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.52734375), 0.0f },
      { static_cast<float>(0.537109375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.537109375), 0.0f },
      { static_cast<float>(0.546875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.546875), 0.0f },
      { static_cast<float>(0.556640625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.556640625), 0.0f },
      { static_cast<float>(0.56640625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.56640625), 0.0f },
      { static_cast<float>(0.576171875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.576171875), 0.0f },
      { static_cast<float>(0.5859375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.5859375), 0.0f },
      { static_cast<float>(0.595703125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.595703125), 0.0f },
      { static_cast<float>(0.60546875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.60546875), 0.0f },
      { static_cast<float>(0.615234375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.615234375), 0.0f },
      { static_cast<float>(0.625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.625), 0.0f },
      { static_cast<float>(0.634765625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.634765625), 0.0f },
      { static_cast<float>(0.64453125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.64453125), 0.0f },
      { static_cast<float>(0.654296875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.654296875), 0.0f },
      { static_cast<float>(0.6640625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.6640625), 0.0f },
      { static_cast<float>(0.673828125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.673828125), 0.0f },
      { static_cast<float>(0.68359375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.68359375), 0.0f },
      { static_cast<float>(0.693359375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.693359375), 0.0f },
      { static_cast<float>(0.703125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.703125), 0.0f },
      { static_cast<float>(0.712890625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.712890625), 0.0f },
      { static_cast<float>(0.72265625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.72265625), 0.0f },
      { static_cast<float>(0.732421875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.732421875), 0.0f },
      { static_cast<float>(0.7421875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.7421875), 0.0f },
      { static_cast<float>(0.751953125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.751953125), 0.0f },
      { static_cast<float>(0.76171875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.76171875), 0.0f },
      { static_cast<float>(0.771484375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.771484375), 0.0f },
      { static_cast<float>(0.78125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.78125), 0.0f },
      { static_cast<float>(0.791015625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.791015625), 0.0f },
      { static_cast<float>(0.80078125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.80078125), 0.0f },
      { static_cast<float>(0.810546875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.810546875), 0.0f },
      { static_cast<float>(0.8203125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.8203125), 0.0f },
      { static_cast<float>(0.830078125), static_cast<float>(0.625) } },
    { { static_cast<float>(0.830078125), 0.0f },
      { static_cast<float>(0.83984375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.83984375), 0.0f },
      { static_cast<float>(0.849609375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.849609375), 0.0f },
      { static_cast<float>(0.859375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.859375), 0.0f },
      { static_cast<float>(0.869140625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.869140625), 0.0f },
      { static_cast<float>(0.87890625), static_cast<float>(0.625) } },
    { { static_cast<float>(0.87890625), 0.0f },
      { static_cast<float>(0.888671875), static_cast<float>(0.625) } },
    { { static_cast<float>(0.888671875), 0.0f },
      { static_cast<float>(0.8984375), static_cast<float>(0.625) } },
    { { static_cast<float>(0.8984375), 0.0f },
      { static_cast<float>(0.908203125), static_cast<float>(0.625) } },
};

const std::string PC_VERT =
    "uniform mat4 ProjMtx;                                  \
     attribute vec2 Position;                               \
     attribute vec4 Color;                                  \
     varying vec4 Frag_Color;                               \
     void main()                                            \
     {                                                      \
         Frag_Color = Color;                                \
         gl_Position = ProjMtx * vec4(Position.xy, 0, 1);   \
     }";
const std::string PC_FRAG =
    "varying vec4 Frag_Color;                               \
     void main()                                            \
     {                                                      \
         gl_FragColor = Frag_Color;                         \
     }";

const std::string PTC_VERT =
    "uniform mat4 ProjMtx;                                  \
     attribute vec2 Position;                               \
     attribute vec2 TexCoord;                               \
     attribute vec4 Color;                                  \
     varying vec2 Frag_TexCoord;                            \
     varying vec4 Frag_Color;                               \
     void main()                                            \
     {                                                      \
         Frag_TexCoord = TexCoord;                          \
         Frag_Color = Color;                                \
         gl_Position = ProjMtx * vec4(Position.xy, 0, 1);   \
     }";
const std::string PTC_FRAG =
    "varying vec2 Frag_TexCoord;                            \
     varying vec4 Frag_Color;                               \
     uniform sampler2D Texture;                             \
     void main()                                            \
     {                                                      \
         vec4 diffuse = texture2D(Texture, Frag_TexCoord);  \
         gl_FragColor = diffuse * Frag_Color;               \
     }";
}  // namespace CubbyTower

#endif  // CUBBYTOWER_CONSTANTS_HPP
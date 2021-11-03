// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_CONSTANTS_HPP
#define CUBBYTOWER_CONSTANTS_HPP

namespace CubbyTower
{
constexpr static int WIDTH = 800;
constexpr static int HEIGHT = 600;
constexpr static float ZOOM = 32;

constexpr static int MAP_WIDTH = 16;
constexpr static int MAP_HEIGHT = 16;

const static char* PC_VERT =
    "uniform mat4 ProjMtx;                                  \
     attribute vec2 Position;                               \
     attribute vec4 Color;                                  \
     varying vec4 Frag_Color;                               \
     void main()                                            \
     {                                                      \
         Frag_Color = Color;                                \
         gl_Position = ProjMtx * vec4(Position.xy, 0, 1);   \
     }";
const static char* PC_FRAG =
    "varying vec4 Frag_Color;                               \
     void main()                                            \
     {                                                      \
         gl_FragColor = Frag_Color;                         \
     }";

//! The price of arrow tower at level 1.
constexpr static int ARROW_TOWER_LV1_PRICE = 100;

//! The price of arrow tower at level 2.
constexpr static int ARROW_TOWER_LV2_PRICE = 200;
}  // namespace CubbyTower

#endif  // CUBBYTOWER_CONSTANTS_HPP
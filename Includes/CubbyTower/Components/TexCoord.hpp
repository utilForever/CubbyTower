// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TEX_COORD_HPP
#define CUBBYTOWER_TEX_COORD_HPP

namespace CubbyTower
{
//!
//! \brief TexCoord struct.
//!
//! This struct stores the coordinate of the texture.
//! Only used by vertex buffers and not directly as a component.
//!
struct TexCoord
{
    float u;
    float v;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TEX_COORD_HPP

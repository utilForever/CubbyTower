// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_RENDERING_HELPERS_HPP
#define CUBBYTOWER_RENDERING_HELPERS_HPP

#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Position.hpp>

namespace CubbyTower
{
struct VertexPC
{
    Position position;
    Color color;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_RENDERING_HELPERS_HPP
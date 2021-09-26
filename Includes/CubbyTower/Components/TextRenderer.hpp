// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TEXT_RENDERER_HPP
#define CUBBYTOWER_TEXT_RENDERER_HPP

#include <CubbyTower/Components/Color.hpp>

#include <string>

namespace CubbyTower
{
//!
//! \brief TextRenderer struct.
//!
//! This struct stores the data for rendering text at position with color.
//!
struct TextRenderer
{
    std::string text;
    Color bgColor;
    // NOTE: 0 = Left, 0.5 = Center, 1 = Right
    float align;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TEXT_RENDERER_HPP
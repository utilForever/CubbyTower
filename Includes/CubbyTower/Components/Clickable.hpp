// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_CLICKABLE_HPP
#define CUBBYTOWER_CLICKABLE_HPP

#include <CubbyTower/Components/Color.hpp>

#include <entt/entt.hpp>

#include <functional>

namespace CubbyTower
{
//!
//! \brief Clickable struct.
//!
//! This struct stores the value of click color and callback function.
//!
struct Clickable
{
    Color downColor;
    std::function<void(entt::registry&, entt::entity)> OnClick;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_CLICKABLE_HPP
// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_BUTTON_HPP
#define CUBBYTOWER_BUTTON_HPP

#include <CubbyTower/Components/Color.hpp>

#include <entt/entt.hpp>

#include <functional>

namespace CubbyTower
{
//!
//! \brief Button struct.
//!
//! This struct defines basic properties of a button. It stores disable state
//! color and OnClick callback.
//!
struct Button
{
    Color disabledColor;
    std::function<void(entt::registry&, entt::entity)> OnClick;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_BUTTON_HPP
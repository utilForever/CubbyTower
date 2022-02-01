// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_UI_CONTEXT_HPP
#define CUBBYTOWER_UI_CONTEXT_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//!
//! \brief UIContext struct.
//!
//! This struct stores UI states.
//!
struct UIContext
{
    // Entity for current mouse hover
    entt::entity hover;
    // Entity for when last mouse down
    entt::entity down;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_UI_CONTEXT_HPP

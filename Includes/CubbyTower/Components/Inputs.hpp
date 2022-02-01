// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_INPUTS_HPP
#define CUBBYTOWER_INPUTS_HPP

#include <CubbyTower/Components/Position.hpp>

namespace CubbyTower
{
//! \brief An enumerator for identifying input state.
enum class InputState
{
    UP,
    JUST_UP,
    DOWN,
    JUST_DOWN,
};

//!
//! \brief Inputs struct.
//!
//! This struct stores the position of mouse and the state of key/button.
//!
struct Inputs
{
    // Mouse position
    Position mouse;
    Position worldMouse;

    // Raw states
    bool leftButton;
    bool rightButton;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_INPUTS_HPP

// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_CASH_BUTTON_TOGGLER_HPP
#define CUBBYTOWER_CASH_BUTTON_TOGGLER_HPP

namespace CubbyTower
{
//!
//! \brief CashButtonToggler struct.
//!
//! This struct stores the value of threshold to toggle the owner button
//! depending on the cash threshold held by the player. It's used by tower
//! purchase buttons to grey out when the player doesn't have enough money.
//!
struct CashButtonToggler
{
    int threshold;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_CASH_BUTTON_TOGGLER_HPP
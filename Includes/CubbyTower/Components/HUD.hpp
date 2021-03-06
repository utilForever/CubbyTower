// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_HUD_HPP
#define CUBBYTOWER_HUD_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//!
//! \brief HUD struct.
//!
//! This struct stores the label for current wave and gold.
//!
struct HUD
{
    entt::entity currentWaveLabel;
    entt::entity goldLabel;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_HUD_HPP
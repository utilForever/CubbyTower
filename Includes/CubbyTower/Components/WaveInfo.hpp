// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_WAVE_INFO_HPP
#define CUBBYTOWER_WAVE_INFO_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
struct Position;

//!
//! \brief WaveInfo struct.
//!
//! This struct stores information about the current wave.
//! A wave is defined as a series of keyframes.
//!
//! NOTE: This is only used by the Spawner component, so it could be stored in
//! it directly, but it's also used by WaveData.hpp as generic struct to define
//! the waves.
//!
struct WaveInfo
{
    int keyFrameCount;
    const float* keyFrameTimes;
    const std::function<void(entt::registry&, const Position&)>* MonsterFactories;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_WAVE_INFO_HPP
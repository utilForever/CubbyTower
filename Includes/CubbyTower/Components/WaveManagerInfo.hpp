// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_WAVE_MANAGER_INFO_HPP
#define CUBBYTOWER_WAVE_MANAGER_INFO_HPP

namespace CubbyTower
{
struct WaveInfo;

//!
//! \brief WaveManager struct.
//!
//! This struct stores the state of waves. It's a singleton component.
//!
struct WaveManagerInfo
{
    int curWaveIndex;
    int waveCount;
    const WaveInfo* waves;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_WAVE_MANAGER_INFO_HPP
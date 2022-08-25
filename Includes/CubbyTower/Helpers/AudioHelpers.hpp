// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_AUDIO_HELPERS_HPP
#define CUBBYTOWER_AUDIO_HELPERS_HPP

#include <CubbyTower/Components/Sound.hpp>

namespace CubbyTower::Audio
{
//! Loads a sound from specific file.
//! \param fileName The name of file to load.
Sound LoadSound(const char* fileName);
}  // namespace CubbyTower::Audio

#endif  // CUBBYTOWER_AUDIO_HELPERS_HPP

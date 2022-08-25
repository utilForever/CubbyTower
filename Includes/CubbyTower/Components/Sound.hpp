// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_SOUND_HPP
#define CUBBYTOWER_SOUND_HPP

#include <SFML/Audio/SoundBuffer.hpp>

namespace CubbyTower
{
//!
//! \brief Sound struct.
//!
//! This struct stores the buffer of a sound.
//!
struct Sound
{
    sf::SoundBuffer buffer;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_SOUND_HPP

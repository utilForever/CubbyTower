// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_AUDIO_HELPERS_HPP
#define CUBBYTOWER_AUDIO_HELPERS_HPP

#include <CubbyTower/Components/Sound.hpp>

#include <entt/entt.hpp>

namespace CubbyTower::Audio
{
static std::map<std::string, Sound> sounds;

//! Loads a sound from specific file.
//! \param name The name of the sound.
//! \param path The path of file to load.
void LoadSound(const char* name, const char* path);

//! Plays a sound.
//! \param registry A registry that handles entities.
//! \param sound A sound component to play.
void PlaySound(const Sound& sound);
}  // namespace CubbyTower::Audio

#endif  // CUBBYTOWER_AUDIO_HELPERS_HPP

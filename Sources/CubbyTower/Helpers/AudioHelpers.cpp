// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Helpers/AudioHelpers.hpp>

#include <SFML/Audio/Sound.hpp>

#include <cassert>

namespace CubbyTower::Audio
{
void LoadSound(const char* name, const char* path)
{
    Sound sound;

    if (!sound.buffer.loadFromFile(path))
    {
        assert(false);
    }

    sounds.insert_or_assign(name, sound);
}

void PlaySound(const char* name)
{
    if (sounds.find(name) != sounds.end())
    {
        sounds[name].sound.setBuffer(sounds[name].buffer);
        sounds[name].sound.play();
    }
}
}  // namespace CubbyTower::Audio

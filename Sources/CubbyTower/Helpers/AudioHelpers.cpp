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
Sound LoadSound(const char* fileName)
{
    Sound sound;

    if (!sound.buffer.loadFromFile(fileName))
    {
        assert(false);
    }

    return sound;
}

void PlaySound(const Sound& sound)
{
    sf::Sound sfmlSound;

    sfmlSound.setBuffer(sound.buffer);
    sfmlSound.play();
}
}  // namespace CubbyTower::Audio

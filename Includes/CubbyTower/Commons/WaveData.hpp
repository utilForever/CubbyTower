// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_WAVE_DATA_HPP
#define CUBBYTOWER_WAVE_DATA_HPP

#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/WaveInfo.hpp>
#include <CubbyTower/Helpers/MonsterHelpers.hpp>

namespace CubbyTower
{
using WaveFactory = std::function<void(entt::registry&, const Position&)>;

//! The number of waves.
constexpr static int WAVE_COUNT = 5;
//! The start position of the wave.
constexpr static Position WAVE_START_POSITION = { 0.5f, 4.5f };
//! The start time of the wave.
constexpr static float WAVE_START_TIME = -0.1f;
//! The wait time between waves.
constexpr static float END_WAVE_WAIT_TIME = 1.0f;

constexpr static float WAVE_1_TIMES[] = { 0.00f,  2.00f,  4.00f,  6.00f,
                                          8.00f,  10.00f, 12.00f, 14.00f,
                                          16.00f, 17.00f, 18.00f, 19.00f,
                                          19.00f };

const static WaveFactory WAVE_1_FACTORIES[] = { Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                nullptr };

constexpr static float WAVE_2_TIMES[] = { 0.00f,  1.50f,  2.50f,  3.50f,
                                          5.00f,  6.50f,  7.50f,  8.50f,
                                          10.00f, 10.75f, 12.00f, 13.00f,
                                          14.00f, 15.00f, 16.00f, 17.00f,
                                          18.00f, 19.00f, 19.50f };

const static WaveFactory WAVE_2_FACTORIES[] = { Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                nullptr };

constexpr static float WAVE_3_TIMES[] = { 0.00f,  1.50f,  3.00f,  4.50f,
                                          6.00f,  7.50f,  8.50f,  10.00f,
                                          11.50f, 13.00f, 17.00f, 19.00f,
                                          20.50f, 22.00f, 23.50f, 25.00f,
                                          26.50f, 28.00f, 29.50f, 31.00f };

const static WaveFactory WAVE_3_FACTORIES[] = { Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                nullptr };

constexpr static float WAVE_4_TIMES[] = { 0.00f,  3.00f,  4.00f,  5.00f,
                                          6.00f,  7.00f,  8.00f,  9.00f,
                                          10.00f, 11.00f, 12.00f, 13.00f,
                                          14.00f, 18.00f, 19.50f, 21.00f,
                                          22.50f, 24.00f, 25.50f, 27.00f,
                                          28.50f, 30.00f, 31.50f, 33.00f,
                                          34.50f, 36.00f, 37.50f, 39.00f };

const static WaveFactory WAVE_4_FACTORIES[] = { Monster::CreatePigeonBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,

                                                Monster::CreatePigeonBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                nullptr };

constexpr static float WAVE_5_TIMES[] = { 0.00f,  1.00f,  2.00f,  3.00f,
                                          4.00f,  5.00f,  6.00f,  7.00f,
                                          8.00f, 8.50f, 9.00f, 10.00f,
                                          11.00f, 12.00f, 13.00f, 14.00f,
                                          15.50f, 16.00f, 17.00f, 18.00f,

                                          25.00f, 26.00f, 27.00f, 28.00f,
                                          29.00f, 30.00f, 30.50f, 31.00f,
                                          32.00f, 33.00f, 34.00f, 35.00f,
                                          35.50f, 36.00f, 37.00f, 38.00f,
                                          39.00f, 40.00f, 40.50f, 41.00f };

const static WaveFactory WAVE_5_FACTORIES[] = { Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreatePigeonBalloon,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv3,

                                                Monster::CreatePigeonBalloon,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreatePigeonBalloon,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreatePigeonBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreateNormalBalloonLv3,
                                                Monster::CreatePigeonBalloon,
                                                Monster::CreateNormalBalloonLv2,
                                                nullptr };


const static WaveInfo WAVES[] = {
    { 13, WAVE_1_TIMES, WAVE_1_FACTORIES },
    { 19, WAVE_2_TIMES, WAVE_2_FACTORIES },
    { 20, WAVE_3_TIMES, WAVE_3_FACTORIES },
    { 28, WAVE_4_TIMES, WAVE_4_FACTORIES },
    { 40, WAVE_5_TIMES, WAVE_5_FACTORIES },
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_WAVE_DATA_HPP
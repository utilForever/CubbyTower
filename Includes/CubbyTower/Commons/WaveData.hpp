// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_WAVE_DATA_HPP
#define CUBBYTOWER_WAVE_DATA_HPP

#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Helpers/MonsterHelpers.hpp>

namespace CubbyTower
{
using WaveFactory = std::function<void(entt::registry&, const Position&)>;

//! The number of waves.
constexpr static int WAVE_COUNT = 2;

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
                                          10.00f, 10.50f, 12.00f, 13.00f,
                                          14.00f, 15.00f, 15.50f, 17.00f,
                                          18.00f, 19.00f, 19.00f };

const static WaveFactory WAVE_2_FACTORIES[] = { Monster::CreateNormalBalloon,
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
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                Monster::CreateNormalBalloon,
                                                nullptr };
}  // namespace CubbyTower

#endif  // CUBBYTOWER_WAVE_DATA_HPP
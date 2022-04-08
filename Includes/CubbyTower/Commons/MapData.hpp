// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_MAP_DATA_HPP
#define CUBBYTOWER_MAP_DATA_HPP

#include <CubbyTower/Components/Position.hpp>

namespace CubbyTower
{
constexpr static int MAP_WIDTH = 16;
constexpr static int MAP_HEIGHT = 16;

constexpr static int GROUND_WAYPOINT_COUNT = 51;
constexpr static int AIR_WAYPOINT_COUNT = 2;

constexpr static Position GROUND_WAYPOINTS[] = {
    { 0.5f, 4.5f },   { 1.5f, 4.5f },   { 2.5f, 4.5f },   { 3.5f, 4.5f },
    { 3.5f, 5.5f },   { 3.5f, 6.5f },   { 3.5f, 7.5f },   { 4.5f, 7.5f },
    { 5.5f, 7.5f },   { 5.5f, 8.5f },   { 5.5f, 9.5f },   { 5.5f, 10.5f },
    { 5.5f, 11.5f },  { 5.5f, 12.5f },  { 5.5f, 13.5f },  { 6.5f, 13.5f },
    { 7.5f, 13.5f },  { 8.5f, 13.5f },  { 9.5f, 13.5f },  { 10.5f, 13.5f },
    { 11.5f, 13.5f }, { 11.5f, 12.5f }, { 11.5f, 11.5f }, { 11.5f, 10.5f },
    { 10.5f, 10.5f }, { 9.5f, 10.5f },  { 8.5f, 10.5f },  { 8.5f, 9.5f },
    { 8.5f, 8.5f },   { 8.5f, 7.5f },   { 8.5f, 6.5f },   { 8.5f, 5.5f },
    { 8.5f, 4.5f },   { 7.5f, 4.5f },   { 6.5f, 4.5f },   { 6.5f, 3.5f },
    { 6.5f, 2.5f },   { 7.5f, 2.5f },   { 8.5f, 2.5f },   { 9.5f, 2.5f },
    { 10.5f, 2.5f },  { 11.5f, 2.5f },  { 12.5f, 2.5f },  { 12.5f, 3.5f },
    { 12.5f, 4.5f },  { 12.5f, 5.5f },  { 12.5f, 6.5f },  { 13.5f, 6.5f },
    { 14.5f, 6.5f },  { 15.5f, 6.5f },  { 15.5f, 6.5f }
};

constexpr static Position AIR_WAYPOINTS[] = { { 0.5f, 4.5f }, { 15.5f, 6.5f } };
}  // namespace CubbyTower

#endif  // CUBBYTOWER_MAP_DATA_HPP
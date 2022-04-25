// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TRAVELER_HPP
#define CUBBYTOWER_TRAVELER_HPP

namespace CubbyTower
{
struct Position;

//!
//! \brief Traveler struct.
//!
//! This struct stores the next waypoint index and whole path
//! for traveling along a path.
//!
struct Traveler
{
    int nextWaypointIndex;
    int waypointCount;
    const Position* waypoints;
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TRAVELER_HPP
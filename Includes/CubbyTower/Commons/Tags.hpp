// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_TAGS_HPP
#define CUBBYTOWER_TAGS_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
namespace Tag
{
using namespace entt::literals;

using Player = entt::tag<"player"_hs>;
using Tower = entt::tag<"tower"_hs>;
using Bullet = entt::tag<"bullet"_hs>;
}  // namespace Tag
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TAGS_HPP
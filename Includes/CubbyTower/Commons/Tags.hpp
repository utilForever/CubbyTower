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

using Resources = entt::tag<"resources"_hs>;
using WaveManager = entt::tag<"wavemanager"_hs>;
using Player = entt::tag<"player"_hs>;
using Inputs = entt::tag<"inputs"_hs>;
using Tooltip = entt::tag<"tooltip"_hs>;
using UIContext = entt::tag<"uicontext"_hs>;
using HUD = entt::tag<"hud"_hs>;
using Tower = entt::tag<"tower"_hs>;
using Monster = entt::tag<"monster"_hs>;
using Projectile = entt::tag<"projectile"_hs>;
}  // namespace Tag
}  // namespace CubbyTower

#endif  // CUBBYTOWER_TAGS_HPP
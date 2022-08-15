// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_MONSTER_TARGET_SCORE_SYSTEM_HPP
#define CUBBYTOWER_MONSTER_TARGET_SCORE_SYSTEM_HPP

#include <entt/entt.hpp>

namespace CubbyTower
{
//! Calculate the score of monster targets based on various things
//! such as their travel distance.
//! \param registry A registry that handles entities.
void UpdateMonsterTargetScoreSystem(entt::registry& registry);
}  // namespace CubbyTower

#endif  // CUBBYTOWER_MONSTER_TARGET_SCORE_SYSTEM_HPP
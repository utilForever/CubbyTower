// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/TargetMask.hpp>
#include <CubbyTower/Components/TypeMask.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>
#include<iostream>

namespace CubbyTower
{
void Attack(entt::registry& registry)
{
    for (auto tower : registry.view<TargetMask>())
    {
        for (auto enemy : registry.view<TypeMask>())
        {
            const auto targetMask = registry.get<TargetMask>(tower).targetMask;
            const auto typeMask = registry.get<TypeMask>(enemy).typeMask;

            if ((targetMask & typeMask) == typeMask)
            {
                // Attack!!
                // Todo...
            }
        }
    }
}
}  // namespace CubbyTower
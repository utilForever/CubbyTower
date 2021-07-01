// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Targeter.hpp>
#include <CubbyTower/Components/Type.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>

namespace CubbyTower
{
bool Attack(entt::registry& registry, entt::entity tower, entt::entity enemy)
{
    if (registry.all_of<Targeter>(tower) && registry.all_of<Type>(enemy))
    {
        const auto targeter = registry.get<Targeter>(tower).targeter;
        const auto type = registry.get<Type>(enemy).type;

        if((targeter&type) == type)
        {
            // Attack!!
            // Todo...
            return true;
        }
        return false;
    }
    return false;
}
}  // namespace CubbyTower
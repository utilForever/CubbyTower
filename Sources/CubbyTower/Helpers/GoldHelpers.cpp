// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Helpers/GoldHelpers.hpp>

namespace CubbyTower
{
bool Withdraw(entt::registry& registry, entt::entity from, int amount)
{
    if (!registry.all_of<Gold>(from))
    {
        return false;
    }

    if (auto& gold = registry.get<Gold>(from); gold.amount >= amount)
    {
        gold.amount -= amount;
        return true;
    }

    return false;
}
}  // namespace CubbyTower
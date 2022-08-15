// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Helpers/BankHelpers.hpp>

namespace CubbyTower::Bank
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

void Transfer(entt::registry& registry, entt::entity from, entt::entity to)
{
    if (from == to)
    {
        return;
    }

    if (!registry.all_of<Gold>(from) || !registry.all_of<Gold>(to))
    {
        return;
    }

    auto& fromGold = registry.get<Gold>(from);
    auto& toGold = registry.get<Gold>(to);

    toGold.amount += fromGold.amount;
    fromGold.amount = 0;
}
}  // namespace CubbyTower::Bank
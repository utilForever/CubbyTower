// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Systems/Game.hpp>

#include <entt/entt.hpp>

using namespace CubbyTower;

int main()
{
    // Create registry and initialize the game
    entt::registry registry;
    Game::Initialize(registry);

    return 0;
}
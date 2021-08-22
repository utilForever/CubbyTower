// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Systems/Game.hpp>

namespace CubbyTower
{
namespace Game
{
void Initialize(entt::registry& registry)
{
    // Player
    {
        auto entity = registry.create();
        registry.emplace<Tag::Player>(entity);
        registry.emplace<Gold>(entity, 500);
    }

    // Inputs
    {
        auto entity = registry.create();
        registry.emplace<Tag::Inputs>(entity);

        Inputs inputs;
        registry.emplace<Inputs>(entity, inputs);
    }
}
}  // namespace Game
}  // namespace CubbyTower
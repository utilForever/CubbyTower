// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Helpers/UIHelpers.hpp>
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

    // HUDs
    {
        auto entity = registry.create();
        registry.emplace<Tag::HUDs>(entity);

        UI::CreateTowerButton(
            registry, "Arrow Tower", { -1, 16.5f }, ARROW_TOWER_LV1_PRICE,
            [](entt::registry& registry, entt::entity button) {
                BuyArrowTower(registry, 0, 0);
            });
    }
}
}  // namespace Game
}  // namespace CubbyTower
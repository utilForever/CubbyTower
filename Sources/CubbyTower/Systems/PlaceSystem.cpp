// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Components/Placer.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Systems/PlaceSystem.hpp>

#include "CubbyTower/Commons/Constants.hpp"

namespace CubbyTower
{
void UpdatePlaceSystem(entt::registry& registry)
{
    auto& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);

    registry.view<Placer>().each(
        [&registry, &inputs](auto entity, const Placer& placer) {
            int mouseX = static_cast<int>(inputs.worldMouse.x);
            int mouseY = static_cast<int>(inputs.worldMouse.y);

            if (mouseX < 0 || mouseX >= MAP_WIDTH || mouseY < 0 ||
                mouseY >= MAP_HEIGHT)
            {
                // Invalid position
                registry.remove_if_exists<Position>(entity);
            }
            else
            {
                Position position{ static_cast<float>(mouseX) + 0.5f,
                                   static_cast<float>(mouseY) + 0.5f };

                if (inputs.leftButtonState == InputState::JUST_DOWN)
                {
                    // Place
                    placer.Place(registry, position);
                    registry.destroy(entity);
                }
                else
                {
                    // Update position component
                    registry.emplace_or_replace<Position>(entity, position);
                }
            }

            // Cancel placing with right-click
            if (inputs.rightButtonState == InputState::JUST_DOWN)
            {
                registry.destroy(entity);
            }
        });
}
}  // namespace CubbyTower
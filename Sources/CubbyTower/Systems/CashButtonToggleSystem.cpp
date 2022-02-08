// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Button.hpp>
#include <CubbyTower/Components/CashButtonToggler.hpp>
#include <CubbyTower/Components/Clickable.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/Hoverable.hpp>
#include <CubbyTower/Systems/CashButtonToggleSystem.hpp>

namespace CubbyTower
{
void UpdateCashButtonTogglerSystem(entt::registry& registry)
{
    const Gold& gold = registry.get<Gold>(registry.view<Tag::Player>()[0]);

    registry.view<CashButtonToggler, Button, Color>().each(
        [&registry, &gold](auto entity,
                           const CashButtonToggler& cashButtonToggler,
                           const Button& button, Color& color) {
            if (gold.amount >= cashButtonToggler.threshold)
            {
                registry.emplace_or_replace<Clickable>(
                    entity, Color{ 0.5f, 0.5f, 0.4f, 1.0f }, button.OnClick);
            }
            else
            {
                registry.remove_if_exists<Clickable>(entity);
                color = button.disabledColor;
            }
        });
}
}  // namespace CubbyTower

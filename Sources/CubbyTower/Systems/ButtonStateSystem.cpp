// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Button.hpp>
#include <CubbyTower/Components/Color.hpp>
#include <CubbyTower/Components/Hoverable.hpp>
#include <CubbyTower/Components/UIContext.hpp>
#include <CubbyTower/Systems/ButtonStateSystem.hpp>

namespace CubbyTower
{
void UpdateButtonStateSystem(entt::registry& registry)
{
    const UIContext& uiContext =
        registry.get<UIContext>(registry.view<Tag::UIContext>()[0]);

    registry.view<Button, Color>().each(
        [&registry, &uiContext](auto entity, const Button& button,
                                Color& color) {
            if (registry.all_of<Hoverable>(entity))
            {
                Hoverable& hoverable = registry.get<Hoverable>(entity);

                if (entity == uiContext.hover)
                {
                    color = hoverable.hoverColor;
                }
                else
                {
                    color = hoverable.normalColor;
                }
            }
            else
            {
                color = button.disabledColor;
            }
        });
}
}  // namespace CubbyTower
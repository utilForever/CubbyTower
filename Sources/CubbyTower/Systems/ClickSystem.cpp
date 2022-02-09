// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Clickable.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Components/UIContext.hpp>
#include <CubbyTower/Systems/ClickSystem.hpp>

namespace CubbyTower
{
void UpdateClickSystem(entt::registry& registry)
{
    Inputs& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);
    UIContext& uiContext =
        registry.get<UIContext>(registry.view<Tag::UIContext>()[0]);

    if (inputs.leftButtonState == InputState::JUST_DOWN)
    {
        uiContext.down = uiContext.hover;
    }
    else if (inputs.leftButtonState == InputState::JUST_UP)
    {
        if (uiContext.down != entt::null && uiContext.down == uiContext.hover &&
            registry.all_of<Clickable>(uiContext.down))
        {
            Clickable& clickable = registry.get<Clickable>(uiContext.down);

            if (clickable.OnClick)
            {
                clickable.OnClick(registry, uiContext.down);
            }

            inputs.leftButtonState = InputState::UP;
        }

        uiContext.down = entt::null;
    }
}
}  // namespace CubbyTower
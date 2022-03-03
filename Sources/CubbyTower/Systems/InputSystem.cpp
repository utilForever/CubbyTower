// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Systems/InputSystem.hpp>

namespace CubbyTower
{
static InputState UpdateInputState(bool isRawInput, InputState prevState)
{
    if (isRawInput)
    {
        if (prevState != InputState::DOWN)
        {
            return InputState::JUST_DOWN;
        }
        else
        {
            return prevState;
        }
    }
    else
    {
        if (prevState != InputState::UP)
        {
            return InputState::JUST_UP;
        }
        else
        {
            return prevState;
        }
    }
}

void UpdateInputSystem(entt::registry& registry)
{
    Inputs& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);

    // Generate mouse world position from mouse position
    auto realWidth = static_cast<float>(WIDTH) - MAP_WIDTH * ZOOM;
    auto realHeight = static_cast<float>(HEIGHT) - MAP_HEIGHT * ZOOM;
    inputs.worldMouse.x = (inputs.mouse.x - realWidth / 2.0f) / ZOOM + 0.5f;
    inputs.worldMouse.y = (inputs.mouse.y - realHeight / 2.0f) / ZOOM + 0.4f;

    inputs.leftButtonState =
        UpdateInputState(inputs.leftButton, inputs.leftButtonState);
    inputs.rightButtonState =
        UpdateInputState(inputs.rightButton, inputs.rightButtonState);
    inputs.upgradeKeyState =
        UpdateInputState(inputs.upgradeKey, inputs.upgradeKeyState);
}
}  // namespace CubbyTower

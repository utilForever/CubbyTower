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
void UpdateInputSystem(entt::registry& registry)
{
    Inputs& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);

    // Generate mouse world position from mouse position
    auto realWidth = static_cast<float>(WIDTH) - MAP_WIDTH * ZOOM;
    auto realHeight = static_cast<float>(HEIGHT) - MAP_HEIGHT * ZOOM;
    inputs.worldMouse.x = (inputs.mouse.x - realWidth / 2.0f) / ZOOM + 0.5f;
    inputs.worldMouse.y = (inputs.mouse.y - realHeight / 2.0f) / ZOOM + 0.4f;
}
}  // namespace CubbyTower

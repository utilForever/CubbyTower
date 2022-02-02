// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Hoverable.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Components/UIContext.hpp>
#include <CubbyTower/Systems/HoverSystem.hpp>

namespace CubbyTower
{
void UpdateHoverSystem(entt::registry& registry)
{
    const Inputs& inputs =
        registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);
    UIContext& uiContext =
        registry.get<UIContext>(registry.view<Tag::UIContext>()[0]);

    uiContext.hover = entt::null;

    registry.view<Hoverable, Position, Size>().each(
        [&inputs, &uiContext]([[maybe_unused]] auto entity,
                              const Hoverable& hoverable,
                              const Position& position, const Size& size) {
            if (inputs.worldMouse.x >= position.x - size.width &&
                inputs.worldMouse.x <= position.x + size.width &&
                inputs.worldMouse.y >= position.y - size.height &&
                inputs.worldMouse.y <= position.y + size.height)
            {
                uiContext.hover = entity;
            }
        });
}
}  // namespace CubbyTower

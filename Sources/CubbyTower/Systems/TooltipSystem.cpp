// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Components/Name.hpp>
#include <CubbyTower/Components/TextRenderer.hpp>
#include <CubbyTower/Components/UIContext.hpp>
#include <CubbyTower/Systems/TooltipSystem.hpp>

namespace CubbyTower
{
void UpdateTooltipSystem(entt::registry& registry)
{
    Inputs& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);
    const UIContext& uiContext =
        registry.get<UIContext>(registry.view<Tag::UIContext>()[0]);
    auto tooltipEntity = registry.view<Tag::Tooltip>()[0];

    if (uiContext.hover != entt::null)
    {
        const auto& text = registry.get<Name>(uiContext.hover).name;
        const float width = static_cast<float>(text.size()) * TEXT_ADVANCE;
        const float align =
            std::max(inputs.worldMouse.x + 0.5f + width - 21.0f, 0.0f) / width;

        registry.emplace_or_replace<Position>(
            tooltipEntity,
            Position{ inputs.worldMouse.x + 0.5f, inputs.worldMouse.y + 0.5f });
        registry.emplace_or_replace<Color>(tooltipEntity,
                                           Color{ 0.75f, 0.75f, 0.85f, 1.0f });
        registry.emplace_or_replace<TextRenderer>(
            tooltipEntity, text, Color{ 0.0f, 0.125f, 0.25f, 0.75f }, align);
    }
    else
    {
        registry.remove_if_exists<TextRenderer>(tooltipEntity);
    }
}
}  // namespace CubbyTower
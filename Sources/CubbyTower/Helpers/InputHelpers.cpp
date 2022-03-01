// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Helpers/InputHelpers.hpp>

namespace CubbyTower::Input
{
void OnMouseButtonPressed(entt::registry& registry, sf::Mouse::Button button)
{
    auto& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);

    if (button == sf::Mouse::Button::Left)
    {
        inputs.leftButton = true;
    }
    else if (button == sf::Mouse::Button::Right)
    {
        inputs.rightButton = true;
    }
}

void OnMouseButtonReleased(entt::registry& registry, sf::Mouse::Button button)
{
    auto& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);

    if (button == sf::Mouse::Button::Left)
    {
        inputs.leftButton = false;
    }
    else if (button == sf::Mouse::Button::Right)
    {
        inputs.rightButton = false;
    }
}

void OnMouseMoved(entt::registry& registry, int x, int y)
{
    auto& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);

    inputs.mouse.x = static_cast<float>(x);
    inputs.mouse.y = static_cast<float>(y);
}

void OnKeyPressed(entt::registry& registry, sf::Keyboard::Key key)
{
    auto& inputs = registry.get<Inputs>(registry.view<Tag::Inputs>()[0]);

    if (key == sf::Keyboard::U)
    {
        inputs.upgradeKey = true;
    }
}
}  // namespace CubbyTower::Input
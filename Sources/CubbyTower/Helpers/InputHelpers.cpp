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
}  // namespace CubbyTower::Input
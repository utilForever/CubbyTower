// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Systems/Game.hpp>

#include <entt/entt.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

using namespace CubbyTower;

int main()
{
    // Create SFML window
    sf::Window window;
    window.create(sf::VideoMode(800, 600), "Cubby Tower",
                  sf::Style::Titlebar | sf::Style::Close);

    // Create registry and initialize the game
    entt::registry registry;
    Game::Initialize(registry);

    sf::Event newEvent;
    while (window.isOpen())
    {
        while (window.pollEvent(newEvent))
        {
            // Close windows
            if (newEvent.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.display();
    }

    return 0;
}
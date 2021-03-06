// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Game.hpp>
#include <CubbyTower/Helpers/InputHelpers.hpp>

#include <GL/gl3w.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <entt/entt.hpp>

#include <chrono>

using namespace CubbyTower;

int main()
{
    using namespace std::chrono;

    // Create SFML window
    sf::Window window;
    window.create(sf::VideoMode(800, 600), "Cubby Tower",
                  sf::Style::Titlebar | sf::Style::Close);

    // Init OpenGL
    gl3wInit();

    // Create registry and initialize the game
    entt::registry registry;
    Game::Initialize(registry);

    sf::Event newEvent{};
    auto lastTime = high_resolution_clock::now();

    bool running = true;

    while (running)
    {
        // Calculate delta time
        auto now = high_resolution_clock::now();
        auto diffTime = now - lastTime;
        lastTime = now;

        const auto durationCount =
            static_cast<double>(duration_cast<microseconds>(diffTime).count());
        auto deltaTime = static_cast<float>(durationCount / 1000000.0);

        while (window.pollEvent(newEvent))
        {
            // Close windows
            if (newEvent.type == sf::Event::Closed)
            {
                running = false;
            }
            else if (newEvent.type == sf::Event::MouseButtonPressed)
            {
                Input::OnMouseButtonPressed(registry,
                                            newEvent.mouseButton.button);
            }
            else if (newEvent.type == sf::Event::MouseButtonReleased)
            {
                Input::OnMouseButtonReleased(registry,
                                             newEvent.mouseButton.button);
            }
            else if (newEvent.type == sf::Event::MouseMoved)
            {
                Input::OnMouseMoved(registry, newEvent.mouseMove.x,
                                    newEvent.mouseMove.y);
            }
            else if (newEvent.type == sf::Event::KeyPressed)
            {
                Input::OnKeyPressed(registry, newEvent.key.code);
            }
            else if (newEvent.type == sf::Event::KeyReleased)
            {
                Input::OnKeyReleased(registry, newEvent.key.code);
            }
        }

        Game::Simulate(registry, deltaTime);
        Game::Update(registry, deltaTime);
        Game::Render(registry);

        window.display();
    }

    return 0;
}
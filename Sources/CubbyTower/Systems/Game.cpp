// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Helpers/UIHelpers.hpp>
#include <CubbyTower/Systems/Game.hpp>
#include <CubbyTower/Systems/ShapeRenderSystem.hpp>

namespace CubbyTower::Game
{
void Initialize(entt::registry& registry)
{
    // Load resources
    {
        auto entity = registry.create();
        registry.emplace<Tag::Resources>(entity);

        Resources resources;
        resources.programPC = Rendering::CreateProgram(
            PC_VERT.c_str(), PC_FRAG.c_str(), { "Position", "Color" });
        resources.vertexBuffer = Rendering::CreateVertexBuffer();
        resources.pcVertices = new VertexPC[MAX_VERTICES];
        registry.emplace<Resources>(entity, resources);
    }

    // Player
    {
        auto entity = registry.create();
        registry.emplace<Tag::Player>(entity);
        registry.emplace<Gold>(entity, 500);
    }

    // Inputs
    {
        auto entity = registry.create();
        registry.emplace<Tag::Inputs>(entity);

        Inputs inputs;
        registry.emplace<Inputs>(entity, inputs);
    }

    // HUDs
    {
        auto entity = registry.create();
        registry.emplace<Tag::HUDs>(entity);

        UI::CreateTowerButton(
            registry, "Arrow Tower", { -1, 16.5f }, ARROW_TOWER_LV1_PRICE,
            [](entt::registry& registry, entt::entity button) {
                BuyArrowTower(registry, 0, 0);
            });
    }
}

void Update(entt::registry& registry, float deltaTime)
{
    (void)registry;
    (void)deltaTime;
}

void Render(entt::registry& registry)
{
    Rendering::BeginFrame(registry);

    Rendering::PrepareForPC(registry);
    UpdateShapeRenderSystem(registry);
}
}  // namespace CubbyTower::Game
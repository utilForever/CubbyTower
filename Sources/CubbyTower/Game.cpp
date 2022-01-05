// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/Data.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Components/StaticLinesRenderer.hpp>
#include <CubbyTower/Game.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Helpers/UIHelpers.hpp>
#include <CubbyTower/Systems/HealthBarRenderSystem.hpp>
#include <CubbyTower/Systems/LineRenderSystem.hpp>
#include <CubbyTower/Systems/PointRenderSystem.hpp>
#include <CubbyTower/Systems/ShapeRenderSystem.hpp>
#include <CubbyTower/Systems/StaticLinesRenderSystem.hpp>

namespace CubbyTower::Game
{
void Initialize(entt::registry& registry)
{
    // Load resources
    {
        auto entity = registry.create();
        registry.emplace<Tag::Resources>(entity);

        Resources resources{};
        resources.programPC = Rendering::CreateProgram(
            PC_VERT.c_str(), PC_FRAG.c_str(), { "Position", "Color" });
        resources.programPTC =
            Rendering::CreateProgram(PTC_VERT.c_str(), PTC_FRAG.c_str(),
                                     { "Position", "TexCoord", "Color" });
        resources.vertexBuffer = Rendering::CreateVertexBuffer();
        resources.pcVertices = new VertexPC[MAX_VERTICES];
        registry.emplace<Resources>(entity, resources);
    }

    // Create map entity
    {
        auto entity = registry.create();
        StaticLinesRenderer staticLinesRenderer{};
        staticLinesRenderer.vertexBuffer =
            Rendering::CreateVertexBuffer(sizeof(MAP_VERTS), MAP_VERTS);
        staticLinesRenderer.vertCount =
            (GLsizei)(sizeof(MAP_VERTS) / (sizeof(float) * 6));
        registry.emplace<StaticLinesRenderer>(entity, staticLinesRenderer);
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

        Inputs inputs{};
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
    UpdateStaticLinesRenderSystem(registry);
    UpdateShapeRenderSystem(registry);
    UpdateLineRenderSystem(registry);
    UpdatePointRenderSystem(registry);
    UpdateHealthBarRenderSystem(registry);

    Rendering::PrepareForPTC(registry);

    Rendering::EndFrame();
}
}  // namespace CubbyTower::Game
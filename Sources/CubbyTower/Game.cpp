// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Constants.hpp>
#include <CubbyTower/Commons/MapData.hpp>
#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Commons/TowerData.hpp>
#include <CubbyTower/Components/Gold.hpp>
#include <CubbyTower/Components/HUD.hpp>
#include <CubbyTower/Components/Inputs.hpp>
#include <CubbyTower/Components/Resources.hpp>
#include <CubbyTower/Components/StaticLinesRenderer.hpp>
#include <CubbyTower/Components/UIContext.hpp>
#include <CubbyTower/Game.hpp>
#include <CubbyTower/Helpers/RenderingHelpers.hpp>
#include <CubbyTower/Helpers/TowerHelpers.hpp>
#include <CubbyTower/Helpers/UIHelpers.hpp>
#include <CubbyTower/Helpers/WaveHelpers.hpp>
#include <CubbyTower/Systems/AttackSystem.hpp>
#include <CubbyTower/Systems/ButtonStateSystem.hpp>
#include <CubbyTower/Systems/CashButtonToggleSystem.hpp>
#include <CubbyTower/Systems/ClickSystem.hpp>
#include <CubbyTower/Systems/CollisionSystem.hpp>
#include <CubbyTower/Systems/HUDSystem.hpp>
#include <CubbyTower/Systems/HealthBarRenderSystem.hpp>
#include <CubbyTower/Systems/HoverSystem.hpp>
#include <CubbyTower/Systems/InputSystem.hpp>
#include <CubbyTower/Systems/LineRenderSystem.hpp>
#include <CubbyTower/Systems/PlaceSystem.hpp>
#include <CubbyTower/Systems/PointRenderSystem.hpp>
#include <CubbyTower/Systems/ProjectileSystem.hpp>
#include <CubbyTower/Systems/ShapeRenderSystem.hpp>
#include <CubbyTower/Systems/SizePulseAnimSystem.hpp>
#include <CubbyTower/Systems/StaticLinesRenderSystem.hpp>
#include <CubbyTower/Systems/TextRenderSystem.hpp>
#include <CubbyTower/Systems/TooltipSystem.hpp>
#include <CubbyTower/Systems/UpgradeSystem.hpp>

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
        resources.fontTexture =
            Rendering::CreateTexture(RESOURCES_DIR "/font.png");
        resources.vertexBuffer = Rendering::CreateVertexBuffer();
        resources.pcVertices = new VertexPC[MAX_VERTICES];
        resources.ptcVertices = new VertexPTC[MAX_VERTICES];
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

    // Wave
    {
        Wave::CreateWaveManager(registry);
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

    // Tooltip
    {
        auto entity = registry.create();
        registry.emplace<Tag::Tooltip>(entity);
    }

    // UI Context
    {
        auto entity = registry.create();
        registry.emplace<Tag::UIContext>(entity);
        registry.emplace<UIContext>(entity, entt::null, entt::null);
    }

    // HUDs
    {
        auto entity = registry.create();
        registry.emplace<Tag::HUD>(entity);

        auto& hud = registry.emplace<HUD>(entity);
        hud.currentWaveLabel = UI::CreateLabel(
            registry, "", { 0, 0 }, Color{ 0.75f, 0.75f, 0.75f, 1.0f }, 0.0f);
        hud.goldLabel = UI::CreateLabel(registry, "", { 16, 0 },
                                        Color{ 1.0f, 1.0f, 0.0f, 1.0f }, 1.0f);

        UI::CreateTowerButton(
            registry, "Arrow Tower", { -1, 16.5f }, ARROW_TOWER_LV1_PRICE,
            [](entt::registry& registry, entt::entity button) {
                Tower::CreatePlacer(registry, Tower::BuyArrowTower);
            });
    }
}

void Simulate(entt::registry& registry, float deltaTime)
{
    UpdateSizePulseAnimSystem(registry, deltaTime);
    UpdateAttackSystem(registry, deltaTime);
    UpdateProjectileSystem(registry, deltaTime);
    UpdateCollisionSystem(registry);
}

void Update(entt::registry& registry, float deltaTime)
{
    (void)deltaTime;
    UpdateInputSystem(registry);
    UpdateHUDSystem(registry);
    UpdateCashButtonTogglerSystem(registry);
    UpdateHoverSystem(registry);
    UpdateClickSystem(registry);
    UpdateUpgradeSystem(registry);
    UpdateTooltipSystem(registry);
    UpdateButtonStateSystem(registry);
    UpdatePlaceSystem(registry);
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
    UpdateTextRenderSystem(registry);

    Rendering::EndFrame();
}
}  // namespace CubbyTower::Game
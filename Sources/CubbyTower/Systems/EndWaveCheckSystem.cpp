// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Commons/WaveData.hpp>
#include <CubbyTower/Components/EndWaveChecker.hpp>
#include <CubbyTower/Components/EndWaveDelay.hpp>
#include <CubbyTower/Components/Spawner.hpp>
#include <CubbyTower/Systems/EndWaveCheckSystem.hpp>

namespace CubbyTower
{
void UpdateEndWaveCheckSystem(entt::registry& registry)
{
    // Nothing to check if there are still critters alive or spawners
    if (!registry.empty<Tag::Monster>() || !registry.empty<Spawner>())
    {
        return;
    }

    registry.view<EndWaveChecker>().each(
        [&](auto entity, const EndWaveChecker& endWaveChecker) {
            registry.remove<EndWaveChecker>(entity);
            registry.emplace<EndWaveDelay>(entity, END_WAVE_WAIT_TIME);
        });
}
}  // namespace CubbyTower
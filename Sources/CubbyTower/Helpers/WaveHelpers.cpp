// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Commons/WaveData.hpp>
#include <CubbyTower/Components/EndWaveChecker.hpp>
#include <CubbyTower/Components/Spawner.hpp>
#include <CubbyTower/Components/WaveManagerInfo.hpp>
#include <CubbyTower/Helpers/WaveHelpers.hpp>

namespace CubbyTower::Wave
{
entt::entity CreateWaveManager(entt::registry& registry)
{
    auto entity = registry.create();
    registry.emplace<Tag::WaveManager>(entity);
    registry.emplace<WaveManagerInfo>(entity, 0, WAVE_COUNT,
                                      static_cast<const WaveInfo*>(WAVES));

    return entity;
}

void StartWave(entt::registry& registry)
{
    auto waveManager = registry.view<Tag::WaveManager>()[0];
    const auto& waveManagerInfo = registry.get<WaveManagerInfo>(waveManager);

    registry.emplace<EndWaveChecker>(waveManager, false);

    // Spawner
    {
        auto entity = registry.create();
        registry.emplace<WaveInfo>(
            entity,
            WaveInfo{ waveManagerInfo.waves[waveManagerInfo.curWaveIndex] });
        registry.emplace<Position>(entity, WAVE_START_POSITION);
        registry.emplace<Spawner>(entity, WAVE_START_TIME);
    }
}
}  // namespace CubbyTower::Wave

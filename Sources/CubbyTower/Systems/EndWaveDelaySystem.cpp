// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Commons/WaveData.hpp>
#include <CubbyTower/Components/EndWaveDelay.hpp>
#include <CubbyTower/Components/WaveManagerInfo.hpp>
#include <CubbyTower/Helpers/WaveHelpers.hpp>
#include <CubbyTower/Systems/EndWaveDelaySystem.hpp>

namespace CubbyTower
{
void UpdateEndWaveDelaySystem(entt::registry& registry, float deltaTime)
{
    registry.view<EndWaveDelay>().each(
        [&](auto entity, EndWaveDelay& endWaveDelay) {
            float delay = endWaveDelay.delay;
            delay -= deltaTime;

            if (delay <= 0.0f)
            {
                registry.remove<EndWaveDelay>(entity);

                auto waveManagerEntity = registry.view<Tag::WaveManager>()[0];
                WaveManagerInfo& waveManager =
                    registry.get<WaveManagerInfo>(waveManagerEntity);
                const int nextWaveIndex = waveManager.curWaveIndex + 1;

                // No more waves
                if (nextWaveIndex >= WAVE_COUNT)
                {
                    registry.destroy(entity);
                }
                else
                {
                    waveManager.curWaveIndex = nextWaveIndex;
                    Wave::StartWave(registry);
                }

                return;
            }

            endWaveDelay.delay = delay;
        });
}
}  // namespace CubbyTower
// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Spawner.hpp>
#include <CubbyTower/Components/WaveInfo.hpp>
#include <CubbyTower/Systems/SpawnSystem.hpp>

namespace CubbyTower
{
void UpdateSpawnSystem(entt::registry& registry, float deltaTime)
{
    registry.view<WaveInfo, Spawner, Position>().each(
        [&registry, &deltaTime]([[maybe_unused]] auto entity,
                                const WaveInfo& waveInfo, Spawner& spawner,
                                const Position& position) {
            // If no more waves, return
            float waveTime = spawner.waveTime;
            const float lastTime = waveTime;
            waveTime += deltaTime;

            // Check all time keys to see if we should spawn monsters
            for (int i = 0, len = waveInfo.keyFrameCount; i < len; ++i)
            {
                const float time = waveInfo.keyFrameTimes[i];

                if (lastTime < time && waveTime >= time)
                {
                    if (auto spawnFunc = waveInfo.MonsterFactories[i])
                    {
                        // Spawn
                        spawnFunc(registry, position);
                    }
                    else
                    {
                        registry.destroy(entity);
                        return;
                    }
                }
            }

            spawner.waveTime = waveTime;
        });
}
}  // namespace CubbyTower

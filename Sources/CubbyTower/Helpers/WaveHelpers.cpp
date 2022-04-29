// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Commons/WaveData.hpp>
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
}  // namespace CubbyTower::Wave

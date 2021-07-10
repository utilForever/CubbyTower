// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Commons/Tags.hpp>
#include <CubbyTower/Components/Position.hpp>
#include <CubbyTower/Components/Distance.hpp>
#include <CubbyTower/Systems/Path.hpp>

namespace CubbyTower
{
void Path(entt::registry& registry)
{
    auto view = registry.view<Distance,Position>(); 
    for (auto enemy : view)
    {
        auto &pos = view.get<Position>(enemy);
        auto &dis = view.get<Distance>(enemy);
        pos.x = dist.distance;
        pos.y = 300.0; //Simple line in the middle
    }
}
}  // namespace CubbyTower

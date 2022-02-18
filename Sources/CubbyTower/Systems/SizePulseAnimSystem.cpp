// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <CubbyTower/Components/Size.hpp>
#include <CubbyTower/Components/SizePulseAnim.hpp>
#include <CubbyTower/Systems/SizePulseAnimSystem.hpp>

namespace CubbyTower
{
void UpdateSizePulseAnimSystem(entt::registry& registry, float deltaTime)
{
    registry.view<SizePulseAnim, Size>().each(
        [&deltaTime]([[maybe_unused]] auto entity, SizePulseAnim& sizePulseAnim,
                     Size& size) {
            const auto anim =
                sizePulseAnim.anim + sizePulseAnim.speed * deltaTime;
            const auto t = std::sinf(anim);
            const auto r = (sizePulseAnim.to - sizePulseAnim.from) / 2.0f;
            const auto sizeA = sizePulseAnim.from + r + t * r;

            sizePulseAnim.anim = anim;
            size.width = sizeA;
            size.height = sizeA;
        });
}
}  // namespace CubbyTower

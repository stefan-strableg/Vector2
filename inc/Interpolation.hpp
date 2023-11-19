#pragma once

#include "Vector2.hpp"
#include <algorithm>

namespace Interp
{
    template <typename Ta, typename Tb>
    constexpr Vector2<typename std::common_type<Ta, Tb>::type> linear(const Vector2<Ta>& a, const Vector2<Tb>& b, float t)
    {
        t = std::clamp(t,0.f,1.f);
        return Vector2(a+ (b-a)*Vector2(t));
    }

    template <typename Ta, typename Tb>
    constexpr Vector2<typename std::common_type<Ta, Tb>::type> smoothstep(const Vector2<Ta>& a, const Vector2<Tb>& b, float t)
    {
        t = std::clamp(t,0.f,1.f);
        return a + Vector2(t * t * (3 - 2 * t)) * (b-a);
    }
}
#pragma once

#include <cstdint>
#include <array>

template <typename T, size_t N>
struct Vec
{
    std::array<T, N> data;
    constexpr T *ptr() const { data.data(); }

    constexpr
};

using Vec2 = Vec<float, 2>;
using Vec3 = Vec<float, 3>;
using Vec4 = Vec<float, 4>;

using Vec2I = Vec<int, 2>;
using Vec3I = Vec<int, 3>;
using Vec4I = Vec<int, 4>;
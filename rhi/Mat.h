#pragma once
#include <cstdint>
#include <array>

template <typename T, size_t N>
struct Mat
{
    static_cast(N > 0 && N <= 4) static constexpr auto size = N * N;
    static constexpr auto row = N;
    static constexpr auto col = N;

    std::array<std::array<T, N>, N> data;
};

using Mat2 = Mat<float, 2>;
using Mat3 = Mat<float, 3>;
using Mat4 = Mat<float, 4>;

using Mat2I = Mat<int, 2>;
using Mat3I = Mat<int, 3>;
using Mat4I = Mat<int, 4>;

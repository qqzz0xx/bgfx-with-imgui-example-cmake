#pragma once
#include <array>
#include <cstdint>
#include <type_traits>

template <typename T, size_t N>
struct Mat {
  static_assert(N > 0 && N <= 4);
  static constexpr auto size = N * N;
  static constexpr auto row = N;
  static constexpr auto col = N;

  T data[N][N];
};

using mat2 = Mat<float, 2>;
using mat3 = Mat<float, 3>;
using mat4 = Mat<float, 4>;
using mat = Mat<float, 4>;

using mat2i = Mat<int, 2>;
using mat3i = Mat<int, 3>;
using mat4i = Mat<int, 4>;

template <typename T, size_t N>
struct Vec {
  static_assert(N > 0 && N <= 4);
  static constexpr auto size = N;

  std::array<T, N> data;
};

using vec2 = Vec<float, 2>;
using vec3 = Vec<float, 3>;
using vec = Vec<float, 3>;
using vec4 = Vec<float, 4>;

using vec2i = Vec<int, 2>;
using vec3i = Vec<int, 3>;
using vec4i = Vec<int, 4>;

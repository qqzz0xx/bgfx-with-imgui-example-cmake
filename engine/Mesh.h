#pragma once
#include <vector>
#include <cstdint>
#include "Math.h"

namespace sse {

struct Vertex {
  vec3 pos;
  vec3 normal;
  vec2 texcoord;
};

struct Mesh {
  std::vector<Vertex> vertexs;
  std::vector<uint16_t> indexs;
};
}  // namespace sse

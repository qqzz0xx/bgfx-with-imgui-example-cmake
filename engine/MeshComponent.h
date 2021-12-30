#pragma once
#include "pch.h"
//
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "Math.h"

using UniformVar =
    std::variant<uint8_t, uint16_t, uint32_t, int8_t, int16_t, int32_t, float,
                 vec2, vec3, vec4, mat2, mat3, mat4>;

struct Material {
  ResourceId vsShaderId;
  ResourceId fsShaderId;
  std::unordered_map<std::string, UniformVar> props;
};

struct MeshFilter {
  ResourceId meshId;
};

struct MeshRender {
  std::vector<std::shared_ptr<Material>> materials;
};

#pragma once
#include "entt/entt.hpp"
#include <cstdint>

namespace sse {

struct Context {
  int width = 0;
  int height = 0;
  uint16_t pciId = 0;
  entt::registry* registry = nullptr;
};

void ContextInit();
void ContextDestroy();
Context& ContextGlobal();

}  // namespace sse

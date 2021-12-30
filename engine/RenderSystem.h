#pragma once

#include <memory>

#include "entt/entt.hpp"

namespace sse {

struct RenderSystemD;
struct RenderSystem {
  RenderSystem();
  void init();
  int shutdown();
  void start();
  bool update();

 private:
  std::shared_ptr<RenderSystemD> d;
};
}  // namespace sse

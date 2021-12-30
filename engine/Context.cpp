#include "Context.h"

#include <mutex>

static sse::Context s_context;
static std::mutex s_ctxMutex;

sse::Context& sse::ContextGlobal() {
  std::lock_guard<std::mutex> lock(s_ctxMutex);
  return s_context;
}

void sse::ContextInit() {
  std::lock_guard<std::mutex> lock(s_ctxMutex);
  s_context.registry = new entt::registry;
}

void sse::ContextDestroy() {
  std::lock_guard<std::mutex> lock(s_ctxMutex);

  delete s_context.registry;
}

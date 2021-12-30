#include "RenderSystem.h"

#include "Context.h"
#include "MeshComponent.h"
#include "AssetManager.h"
#include "bgfx/bgfx.h"

namespace sse {
struct Model {
  bgfx::VertexBufferHandle vbh;
  bgfx::IndexBufferHandle ibh;
  bgfx::ProgramHandle pgh;
};

struct RenderSystemD {
  std::vector<Model> models;
};

}  // namespace sse

sse::RenderSystem::RenderSystem() { d = std::make_shared<RenderSystemD>(); }

void sse::RenderSystem::init() {
  const auto& ctx = ContextGlobal();

  bgfx::Init init;
#if _WIN32
  init.type = bgfx::RendererType::Direct3D11;
#endif
  init.vendorId = ctx.pciId;
  init.resolution.width = ctx.width;
  init.resolution.height = ctx.height;
  init.resolution.reset = BGFX_RESET_VSYNC;
  bgfx::init(init);

#if _DEBUG
  // Enable debug text.
  bgfx::setDebug(BGFX_DEBUG_TEXT);
#endif
  // Set view 0 clear state.
  bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f,
                     0);
}

int sse::RenderSystem::shutdown() { return 0; }

void sse::RenderSystem::start() {
  d->models.clear();

  const auto& ctx = ContextGlobal();
  const auto& registry = ctx.registry;
  auto view = registry->view<MeshFilter, MeshRender>();
  view.each([](const MeshFilter& meshFilter, const MeshRender& render) {
    auto mesh = AssetManager::FindMesh(meshFilter.meshId);

    bgfx::VertexLayout layout;
    layout.begin()
        .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
        .add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float)
        .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
        .end();

    auto vbh = bgfx::createVertexBuffer(
        bgfx::makeRef(mesh->vertexs.data(), mesh->vertexs.size()), layout);

    auto ibh = bgfx::createIndexBuffer(
        bgfx::makeRef(mesh->indexs.data(), mesh->vertexs.size()));

    auto pgh = bgfx::createShader(
        bgfx::makeRef(mesh->indexs.data(), mesh->vertexs.size()));

    for (auto&& material : render.materials) {
      auto vsBuf = AssetManager::FindShader(material->vsShaderId);
      auto psBuf = AssetManager::FindShader(material->fsShaderId);

      auto vsh =
          bgfx::createShader(bgfx::makeRef(vsBuf->data(), vsBuf->size()));
      auto psh =
          bgfx::createShader(bgfx::makeRef(psBuf->data(), psBuf->size()));

      auto pgh = bgfx::createProgram(vsh, psh, true);

      Model model;
      model.pgh = pgh;
      model.vbh = vbh;
      model.ibh = ibh;
    }
  });
}

bool sse::RenderSystem::update() {

  for (auto&& model : d->models) {

    bgfx::setVertexBuffer(0, model.vbh);
    bgfx::setIndexBuffer(model.ibh);
    bgfx::submit(0, model.pgh);
  }

  return true;
}

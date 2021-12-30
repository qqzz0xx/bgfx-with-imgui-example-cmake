/*
 * Copyright 2011-2021 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */

#define ENTRY_CONFIG_IMPLEMENT_MAIN 1

#include "Context.h"
#include "MeshComponent.h"
#include "AssetManager.h"
#include "RenderSystem.h"
#include "bgfx/common/bgfx_utils.h"
#include "bgfx/common/common.h"
#include "bgfx/common/imgui/imgui.h"  // <--- Here we are using bgfx renderer for imgui
#include "bgfx/platform.h"
#include "bx/uint32_t.h"
#include "entt/entt.hpp"
//

#include <iostream>

namespace sse {

class App : public entry::AppI {
 public:
  App(const char *_name, const char *_description, const char *_url)
      : entry::AppI(_name, _description, _url) {}

  void init(int32_t _argc, const char *const *_argv, uint32_t _width,
            uint32_t _height) override {
    Args args(_argc, _argv);

    ContextInit();
    auto &ctx = ContextGlobal();
    ctx.width = _width;
    ctx.height = _height;
    ctx.pciId = args.m_pciId;

    AssetManager::LoadDefault();

    auto en = ctx.registry->create();
    ctx.registry->emplace<MeshFilter>(en, "@plane");

    auto material = std::make_shared<Material>();
    material->fsShaderId = "fs_cube";
    material->vsShaderId = "vs_cube";
    
    ctx.registry->emplace<MeshRender>(en, std::vector{material});


    m_renderSystem.init();
    m_renderSystem.start();

    imguiCreate();
    ImGui::GetIO().ConfigFlags |=
        ImGuiConfigFlags_DockingEnable;  // <-- Here we are testing a feature of
                                         // imgui docking branch
  }

  virtual int shutdown() override {
    imguiDestroy();

    // Shutdown bgfx.
    bgfx::shutdown();

    return 0;
  }

  void updateUi() {}

  void updateScene() {}

  bool update() override {
    if (!entry::processEvents(m_width, m_height, m_debug, m_reset,
                              &m_mouseState)) {
      auto &ctx = ContextGlobal();
      ctx.width = m_width;
      ctx.height = m_height;

      uint8_t buttons = 0;
      buttons |= m_mouseState.m_buttons[entry::MouseButton::Left]
                     ? IMGUI_MBUT_LEFT
                     : 0;
      buttons |= m_mouseState.m_buttons[entry::MouseButton::Middle]
                     ? IMGUI_MBUT_MIDDLE
                     : 0;
      buttons |= m_mouseState.m_buttons[entry::MouseButton::Right]
                     ? IMGUI_MBUT_RIGHT
                     : 0;

      imguiBeginFrame(m_mouseState.m_mx, m_mouseState.m_my, buttons,
                      m_mouseState.m_mz, uint16_t(m_width), uint16_t(m_height));

      updateUi();

      imguiEndFrame();

      updateScene();

      bgfx::setViewRect(0, 0, 0, uint16_t(m_width), uint16_t(m_height));
      bgfx::touch(0);
      bgfx::frame();

      return true;
    }

    return false;
  }

  entry::MouseState m_mouseState;

  uint32_t m_width = 0;
  uint32_t m_height = 0;
  uint32_t m_debug = 0;
  uint32_t m_reset = 0;
  RenderSystem m_renderSystem;
};

}  // namespace sse

ENTRY_IMPLEMENT_MAIN(
    sse::App, "App", "App desc",
    "https://bkaradzic.github.io/bgfx/examples.html#helloworld");

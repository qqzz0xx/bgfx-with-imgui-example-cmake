/*
 * Copyright 2011-2021 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */

#define ENTRY_CONFIG_IMPLEMENT_MAIN 1

#include "bx/uint32_t.h"
#include "bgfx/common/common.h"
#include "bgfx/common/bgfx_utils.h"
#include "bgfx/common/imgui/imgui.h" // <--- Here we are using bgfx renderer for imgui

#include "bgfx/platform.h"
#include "DShowCore.h"
#include "HRI.h"

#include <iostream>
#include <objbase.h>

using namespace DShow;

namespace
{

	struct PosColorVertex
	{
		float x;
		float y;
		float z;
		int16_t m_u;
		int16_t m_v;

		static void Init()
		{
			ss_layout.begin()
				.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
				.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Int16)
				.end();
		}
		static bgfx::VertexLayout ss_layout;
	};

	bgfx::VertexLayout PosColorVertex::ss_layout;

	static PosColorVertex planeVertices[] =
		{
			{1.0f, 0.0f, 0.0f, 1.0f, 0.0f},
			{1.0f, 1.0f, 0.0f, 1.0f, 1.0f},
			{0.0f, 0.0f, 0.0f, 0.0f, 0.0f},

			{0.0f, 1.0f, 0.0f, 0.0f, 1.0f},
	};

	static const uint16_t planeTriList[] =
		{
			0,
			1,
			2,
			2,
			1,
			3,

	};

	void yuv422ToRgba(uint8_t *data, int w, int h, uint8_t *rgba_data)
	{

		size_t half = w * h / 2;
		size_t k = 0;
		for (size_t i = 0; i < half; i++)
		{
			uint8_t y0 = data[i];
			uint8_t u0 = data[i + 1];
			uint8_t y1 = data[i + 2];
			uint8_t v1 = data[i + 3];

			rgba_data[k] = y0 + 1.14 * v1;
			rgba_data[k + 1] = y0 - 0.39 * u0 - 0.58 * v1;
			rgba_data[k + 2] = y0 + 2.03 * u0;
			rgba_data[k + 3] = 255;

			rgba_data[k + 4] = y1 + 1.14 * v1;
			rgba_data[k + 5] = y1 - 0.39 * u0 - 0.58 * v1;
			rgba_data[k + 6] = y1 + 2.03 * u0;
			rgba_data[k + 7] = 255;
		}
	}

	class ExampleHelloWorld : public entry::AppI
	{
	public:
		ExampleHelloWorld(const char *_name, const char *_description, const char *_url)
			: entry::AppI(_name, _description, _url)
		{
		}

		void init(int32_t _argc, const char *const *_argv, uint32_t _width, uint32_t _height) override
		{
			CoInitialize(nullptr);

			Args args(_argc, _argv);

			m_width = _width;
			m_height = _height;
			m_debug = BGFX_DEBUG_TEXT;
			m_reset = BGFX_RESET_VSYNC;

			bgfx::Init init;
			init.type = args.m_type;
			init.vendorId = args.m_pciId;
			init.resolution.width = m_width;
			init.resolution.height = m_height;
			init.resolution.reset = m_reset;
			bgfx::init(init);

			// Enable debug text.
			bgfx::setDebug(m_debug);

			// Set view 0 clear state.
			bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f, 0);

			PosColorVertex::Init();

			m_vbh = bgfx::createVertexBuffer(bgfx::makeRef(planeVertices, sizeof(planeVertices)), PosColorVertex::ss_layout);
			m_ibh = bgfx::createIndexBuffer(bgfx::makeRef(planeTriList, sizeof(planeTriList)));
			s_texColor = bgfx::createUniform("s_texColor", bgfx::UniformType::Sampler);
			u_width = bgfx::createUniform("width", bgfx::UniformType::Count);
			u_height = bgfx::createUniform("height", bgfx::UniformType::Count);

			m_program = loadProgram("vs_texture_01", "fs_texture_01");
			// m_computeProgram = bgfx::createProgram(loadShader("cs_yuv422ToRgb"), true);

			m_dshow.Init();
			m_dshow.Run();
			m_dshow.OnVideoCallback = [&](const VideoConfig &config, unsigned char *data,
										  size_t size, long long startTime, long long stopTime,
										  long rotation)
			{
				if (!bgfx::isValid(m_texture) || m_texHeight != config.cy_abs / 2 || m_texWidth != config.cx)
				{
					if (bgfx::isValid(m_texture))
					{
						bgfx::destroy(m_texture);
						// bgfx::destroy(m_textureRgba);
					}
					m_texHeight = config.cy_abs / 2;
					m_texWidth = config.cx;

					m_texture = bgfx::createTexture2D(m_texWidth, m_texHeight, false, 1, bgfx::TextureFormat::RGBA8U);
					//m_textureRgba = bgfx::createTexture2D(m_texWidth, m_texHeight, false, 1, bgfx::TextureFormat::RGBA8, BGFX_TEXTURE_COMPUTE_WRITE);
				}

				bgfx::updateTexture2D(m_texture, 0, 0, 0, 0, m_texWidth, m_texHeight, bgfx::makeRef(data, size));

				// uint8_t* rgba_data = new uint8_t[m_texWidth* m_texHeight * 4];
				// yuv422ToRgba(data, m_texWidth, m_texHeight, rgba_data);

				// bgfx::updateTexture2D(m_textureRgba, 0, 0, 0, 0, m_texWidth, m_texHeight , bgfx::makeRef(rgba_data,size * 2, [](auto ptr, auto d ){
				// 	delete [] ptr;
				// }));
			};

			imguiCreate();
			ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable; // <-- Here we are testing a feature of imgui docking branch
		}

		virtual int shutdown() override
		{
			imguiDestroy();

			// Shutdown bgfx.
			bgfx::shutdown();

			CoUninitialize();

			return 0;
		}

		bool update() override
		{
			if (!entry::processEvents(m_width, m_height, m_debug, m_reset, &m_mouseState))
			{
				imguiBeginFrame(m_mouseState.m_mx, m_mouseState.m_my, (m_mouseState.m_buttons[entry::MouseButton::Left] ? IMGUI_MBUT_LEFT : 0) | (m_mouseState.m_buttons[entry::MouseButton::Right] ? IMGUI_MBUT_RIGHT : 0) | (m_mouseState.m_buttons[entry::MouseButton::Middle] ? IMGUI_MBUT_MIDDLE : 0), m_mouseState.m_mz, uint16_t(m_width), uint16_t(m_height));

				ImGui::Begin("Hello, world!"); // Create a window called "Hello,
											   // world!" and append into it.

				auto &props = m_dshow.GetProps();

				bool is_changed = false;
				static int item_current = -1;
				auto _ss = m_dshow.GetDeviceMgr()->GetVideoDeviceIdsCStr();

				if (ImGui::Combo("Camera Device", &item_current, _ss.data(),
								 _ss.size()))
				{
					std::string id = _ss[item_current];
					props.cameraId = id;

					is_changed = true;
				}

				static bool is_activate = false;

				if (ImGui::Checkbox("Activate", &is_activate))
				{
					m_dshow.RefreshProps();
					m_dshow.PushAction(is_activate ? DShowCore::Action::Activate
												   : DShowCore::Action::Deactivate);
				}

				ImGui::Checkbox("Use custom audio device",
								&props.useCustomAudioDevice);
				if (props.useCustomAudioDevice)
				{
					static int audio_id = -1;
					auto _ss = m_dshow.GetDeviceMgr()->GetAudioDeviceIdsCStr();
					if (ImGui::Combo("Audio Device", &audio_id, _ss.data(),
									 _ss.size()))
					{
						std::string id = _ss[audio_id];
						props.audioId = id;

						is_changed = true;
					}
				}

				if (is_changed && is_activate)
				{
					m_dshow.RefreshProps();
					m_dshow.PushAction(DShowCore::Action::Activate);
				}

				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
							1000.0f / ImGui::GetIO().Framerate,
							ImGui::GetIO().Framerate);
				ImGui::End();

				imguiEndFrame();

				bgfx::setViewRect(0, 0, 0, uint16_t(m_width), uint16_t(m_height));
				bgfx::touch(0);

				// bgfx::setTexture(0, s_texColor, m_texture);
				// bgfx::setImage(1, m_textureRgba, 0, bgfx::Access::ReadWrite);
				bgfx::setUniform(u_width, &m_texWidth);
				bgfx::setUniform(u_height, &m_texHeight);
				// bgfx::dispatch(0, m_computeProgram, m_texWidth, m_texHeight / 2);

				// Set view and projection matrix for view 0.
				//{

				//  const bx::Vec3 at = { 0.0f, 0.0f,   0.0f };
				//  const bx::Vec3 eye = { 0.0f, 0.0f, -35.0f };
				//  float view[16];
				//  bx::mtxLookAt(view, eye, at);

				//  float proj[16];
				//  bx::mtxProj(proj, 60.0f, float(m_width) / float(m_height), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
				//  bgfx::setViewTransform(0, view, proj);

				//  float mtx[16];
				//  bx::mtxTranslate(mtx, -15, -15, 0);
				//  bgfx::setTransform(mtx);
				//}

				if (bgfx::isValid(m_texture))
				{
					HRI::push_MVP();
					HRI::updateMVP(0);

					bgfx::setVertexBuffer(0, m_vbh);
					bgfx::setIndexBuffer(m_ibh);
					bgfx::setTexture(0, s_texColor, m_texture);
					bgfx::submit(0, m_program);

					HRI::pop_MVP();
				}

				bgfx::frame();

				return true;
			}

			return false;
		}

		entry::MouseState m_mouseState;

		DShowCore m_dshow;

		uint32_t m_width;
		uint32_t m_height;
		uint32_t m_debug;
		uint32_t m_reset;

		bgfx::VertexBufferHandle m_vbh;
		bgfx::IndexBufferHandle m_ibh;
		bgfx::UniformHandle s_texColor;
		bgfx::UniformHandle u_width;
		bgfx::UniformHandle u_height;

		bgfx::ProgramHandle m_program;
		// bgfx::ProgramHandle m_computeProgram;
		bgfx::TextureHandle m_texture = BGFX_INVALID_HANDLE;
		// bgfx::TextureHandle m_textureRgba = BGFX_INVALID_HANDLE;
		int m_texWidth = 0;
		int m_texHeight = 0;
	};

} // namespace

ENTRY_IMPLEMENT_MAIN(
	ExampleHelloWorld, "00-helloworld", "Initialization and debug text.", "https://bkaradzic.github.io/bgfx/examples.html#helloworld");
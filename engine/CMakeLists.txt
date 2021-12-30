file(GLOB_RECURSE E_SRC "*.h" "*.cpp")

add_executable(engine ${E_SRC})

target_link_libraries(engine
  PRIVATE
    bgfx-imgui
    libdshowcapture
    EnTT
)
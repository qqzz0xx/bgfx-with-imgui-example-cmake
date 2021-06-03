cmake_minimum_required(VERSION 3.19)

# --------------------------------------
# Project bgfx+imgui
# --------------------------------------
project(bgfx-imgui)


# --------------------------------------
# Patch Vanilla imgui with bgfx changes
# --------------------------------------

set(VANILLA_IMGUI_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imgui.h
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imgui.cpp
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imgui_internal.h
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imgui_widgets.cpp
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imstb_rectpack.h
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imstb_textedit.h
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/imstb_truetype.h
)

set(BGFX_IMGUI_PATCH
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx-cmake/bgfx/3rdparty/dear-imgui/imconfig.h
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx-cmake/bgfx/3rdparty/dear-imgui/imgui_user.h
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx-cmake/bgfx/3rdparty/dear-imgui/imgui_user.inl
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx-cmake/bgfx/3rdparty/dear-imgui/widgets
)

set(IMGUI_GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)
file(
    COPY 
        ${VANILLA_IMGUI_SOURCES} 
        ${BGFX_IMGUI_PATCH}
        ${CMAKE_CURRENT_LIST_DIR}/src/imgui_bgfx_extra.cpp
    DESTINATION 
        ${IMGUI_GENERATED_DIR}/dear-imgui
)

file(GLOB_RECURSE IMGUI_GENERATED_SOURCES
    ${IMGUI_GENERATED_DIR}/dear-imgui/*
)

# --------------------------------------
# Add bgfx examples/common copy because
# these files are required. It is better
# to maintain a local copy here because
# there is no guarantee that anything in
# examples actually work so this files
# may require modifications for your own
# environment.
# --------------------------------------

file(GLOB_RECURSE INTEGRATION_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/bgfx/*
)

# --------------------------------------
# Combine patched imgui with commons
# --------------------------------------

set(SOURCES
    ${IMGUI_GENERATED_SOURCES}
    ${INTEGRATION_SOURCES}
)

# --------------------------------------
# Define the library
# --------------------------------------
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# --------------------------------------
# Includes
# --------------------------------------
target_include_directories(${PROJECT_NAME} 
    PUBLIC
        ${IMGUI_GENERATED_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/src
)

# --------------------------------------
# Link libraries
# --------------------------------------
target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        bgfx
        bx
        bimg
        meshoptimizer
)

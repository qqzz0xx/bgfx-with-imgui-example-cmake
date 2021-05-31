cmake_minimum_required(VERSION 3.19)

# --------------------------------------
# Project
# --------------------------------------
project(bgfx-imgui)


# --------------------------------------
# Patch Vanilla imgui with bgfx changes
# --------------------------------------

file(GLOB VANILLA_IMGUI_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/im*.h
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/dear-imgui/im*.cpp
)

set(BGFX_IMGUI_PATCH
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx-cmake/bgfx/3rdparty/dear-imgui/imconfig.h
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx-cmake/bgfx/3rdparty/dear-imgui/imgui_user.h
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx-cmake/bgfx/3rdparty/dear-imgui/imgui_user.inl
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx-cmake/bgfx/3rdparty/dear-imgui/widgets
)

set(IMGUI_GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated/dear-imgui)
file(MAKE_DIRECTORY IMGUI_GENERATED_DIR)
file(
    COPY 
        ${VANILLA_IMGUI_SOURCES} 
        ${BGFX_IMGUI_PATCH}
        ${CMAKE_CURRENT_LIST_DIR}/src/imgui_bgfx_extra.cpp
    DESTINATION 
        ${IMGUI_GENERATED_DIR}
)


file(GLOB_RECURSE INTEGRATION_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/bgfx/*
)

file(GLOB_RECURSE IMGUI_GENERATED_SOURCES
    ${IMGUI_GENERATED_DIR}/*
)

set(SOURCES
    ${IMGUI_GENERATED_SOURCES}
    ${INTEGRATION_SOURCES}
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

# --------------------------------------
# Includes
# --------------------------------------
target_include_directories(${PROJECT_NAME} 
    PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}/generated
        ${CMAKE_CURRENT_LIST_DIR}/src
)

# --------------------------------------
# Link libraries
# --------------------------------------
target_link_libraries(${PROJECT_NAME} 
    PRIVATE
        bgfx
        bx
        bimg
        meshoptimizer
)

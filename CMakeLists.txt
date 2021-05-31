cmake_minimum_required(VERSION 3.19)

# --------------------------------------
# Project
# --------------------------------------
project(myapp)


# --------------------------------------
# bgfx
# --------------------------------------
set(BGFX_BUILD_TOOLS OFF CACHE BOOL "Build bgfx tools.")
set(BGFX_BUILD_EXAMPLES OFF CACHE BOOL "Build bgfx examples.")
set(BGFX_INSTALL OFF CACHE BOOL "Create installation target.")
set(BGFX_INSTALL_EXAMPLES OFF CACHE BOOL "Install examples and their runtimes.")
set(BGFX_CUSTOM_TARGETS OFF CACHE BOOL "Include convenience custom targets.")
set(BGFX_AMALGAMATED OFF CACHE BOOL "Amalgamated bgfx build for faster compilation")
set(BX_AMALGAMATED OFF CACHE BOOL "Amalgamated bx build for faster compilation")
set(BGFX_CONFIG_DEBUG OFF CACHE BOOL "Enables debug configuration on all builds")
set(BGFX_CONFIG_RENDERER_WEBGPU OFF CACHE BOOL "Enables the webgpu renderer")
add_subdirectory(3rdparty/bgfx-cmake)
add_subdirectory(3rdparty/bgfx-imgui)

# --------------------------------------
# Sources
# --------------------------------------
set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp 
)

# --------------------------------------
# Products
# --------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES})

# --------------------------------------
# Includes
# --------------------------------------
target_include_directories(${PROJECT_NAME} 
  PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}/src
)

# --------------------------------------
# Link libraries
# --------------------------------------
target_link_libraries(${PROJECT_NAME} 
  PRIVATE
    bgfx-imgui
    bgfx
    bx
    bimg
    meshoptimizer
)

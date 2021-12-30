cmake_minimum_required(VERSION 3.19)

# --------------------------------------
# Project
# Minimal bgfx+imgui project with cmake
# --------------------------------------
project(myapp)

# --------------------------------------
# bgfx options
# --------------------------------------
set(BGFX_BUILD_TOOLS            OFF CACHE BOOL "Build bgfx tools.")
set(BGFX_BUILD_EXAMPLES         OFF CACHE BOOL "Build bgfx examples.")
set(BGFX_INSTALL                OFF CACHE BOOL "Create installation target.")
set(BGFX_INSTALL_EXAMPLES       OFF CACHE BOOL "Install examples and their runtimes.")
set(BGFX_CUSTOM_TARGETS         OFF CACHE BOOL "Include convenience custom targets.")
set(BGFX_AMALGAMATED            OFF CACHE BOOL "Amalgamated bgfx build for faster compilation")
set(BX_AMALGAMATED              OFF CACHE BOOL "Amalgamated bx build for faster compilation")
set(BGFX_CONFIG_DEBUG           OFF CACHE BOOL "Enables debug configuration on all builds")
set(BGFX_CONFIG_RENDERER_WEBGPU OFF CACHE BOOL "Enables the webgpu renderer")

add_definitions(-DUNICODE -D_UNICODE)

include_directories(3rdparty)

include(cmake/libdshowcapture.cmake)
Add_DshowLib(${CMAKE_CURRENT_LIST_DIR}/3rdparty/libdshowcapture)

add_subdirectory(3rdparty/bgfx-cmake)
add_subdirectory(3rdparty/bgfx-imgui)
add_subdirectory(3rdparty/entt)

add_subdirectory(rhi)
add_subdirectory(engine)

# --------------------------------------
# Sources
# --------------------------------------
set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/src/DShowCore.h 
    ${CMAKE_CURRENT_LIST_DIR}/src/DShowCore.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/src/HRI.h
    ${CMAKE_CURRENT_LIST_DIR}/src/HRI.cpp 
)


file(GLOB SHADERS "${CMAKE_CURRENT_LIST_DIR}/src/*.sc")

# --------------------------------------
# Products
# --------------------------------------
add_executable(${PROJECT_NAME} ${SHADERS} ${SOURCES})

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
    libdshowcapture
    EnTT
)


foreach( SHADER ${SHADERS} )
add_bgfx_shader( ${SHADER} ${PROJECT_NAME} )
endforeach()
source_group( "Shader Files" FILES ${SHADERS})

configure_debugging(${PROJECT_NAME} WORKING_DIR ${BGFX_DIR}/examples/runtime )

add_custom_command( TARGET ${PROJECT_NAME} COMMAND ${CMAKE_COMMAND} -E copy_directory ${BGFX_DIR}/examples/runtime/ $<TARGET_FILE_DIR:${PROJECT_NAME}>)
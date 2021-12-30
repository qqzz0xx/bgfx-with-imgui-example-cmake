function(Add_Imgui DIR)

set(INC_DIR
${DIR}
${DIR}/backends
)

file(GLOB SRC
${DIR}/*.h
${DIR}/*.cpp
)

if(WIN32)
    file (GLOB PLATFORM_SRC
    ${DIR}/backends/imgui_impl_win32.*
    ${DIR}/backends/imgui_impl_dx12.*
    ${DIR}/backends/imgui_impl_dx11.*
    )
    list(APPEND SRC ${PLATFORM_SRC})
else()


endif()


add_library(imgui ${SRC})

target_include_directories(imgui PUBLIC ${INC_DIR})

if (WIN32)
    target_link_libraries(imgui PUBLIC
    d3d11.lib
    d3d12.lib
    d3dcompiler.lib
    dxgi.lib
    )
endif()

endfunction(Add_Imgui DIR)


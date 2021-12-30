function(Add_DshowLib DIR)
    
set(libdshowcapture_SOURCES
${DIR}/source/capture-filter.cpp
${DIR}/source/output-filter.cpp
${DIR}/source/dshowcapture.cpp
${DIR}/source/dshowencode.cpp
${DIR}/source/device.cpp
${DIR}/source/encoder.cpp
${DIR}/source/dshow-base.cpp
${DIR}/source/dshow-demux.cpp
${DIR}/source/dshow-enum.cpp
${DIR}/source/dshow-formats.cpp
${DIR}/source/dshow-media-type.cpp
${DIR}/source/dshow-encoded-device.cpp
${DIR}/source/log.cpp)

set(libdshowcapture_HEADERS
${DIR}/dshowcapture.hpp
${DIR}/source/external/IVideoCaptureFilter.h
${DIR}/source/capture-filter.hpp
${DIR}/source/output-filter.hpp
${DIR}/source/device.hpp
${DIR}/source/encoder.hpp
${DIR}/source/dshow-base.hpp
${DIR}/source/dshow-demux.hpp
${DIR}/source/dshow-device-defs.hpp
${DIR}/source/dshow-enum.hpp
${DIR}/source/dshow-formats.hpp
${DIR}/source/dshow-media-type.hpp
${DIR}/source/log.hpp)

add_library(libdshowcapture SHARED
${libdshowcapture_SOURCES}
${libdshowcapture_HEADERS})

target_link_libraries(libdshowcapture 
setupapi
strmiids
ksuser
winmm
wmcodecdspuuid
)

target_compile_definitions(libdshowcapture PRIVATE -DDSHOWCAPTURE_EXPORTS)
target_include_directories(libdshowcapture PUBLIC ${DIR})

endfunction()


# 设置CMake最小版本
cmake_minimum_required(VERSION 3.16)

# 设置工程名称、版本信息和使用地语言
project(wxAppTemplate
        VERSION 0.1
        LANGUAGES CXX)

# 设置C++标准，要求使用C++17标准，REQUIRED表示不允许降级为旧标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置wxWidgets安装的根目录
set(WX_ROOT "$ENV{CPP_LIBS}\\forCMake\\wxWidgets")

# 设置wxWidgets库目录
set(WX_LIB_DIR "${WX_ROOT}/lib/gcc730_x64_dll")

# 设置wxWidgets头文件目录
# mswud是平台特定的设置，msw表示Windows平台，u表示Unicode编码，d表示Debug版本
set(WX_INCLUDE_DIRS
    "${WX_ROOT}/include"
    "${WX_LIB_DIR}/mswud"
)

# 设置需要链接的库
set(WX_LIBS
    wxbase32ud
    wxmsw32ud_core
)

# 指定头文件目录
include_directories(${WX_INCLUDE_DIRS})
link_directories(${WX_LIB_DIR})

# 指定源文件目录
aux_source_directory(src SRC_LIST)

# 指定可执行文件名
add_executable(wxApp
    ${SRC_LIST}
)

# 链接wxWidgets库
target_link_libraries(wxApp ${WX_LIBS})

# 拷贝dll到输出目录
# add_custom_command(TARGET wxApp POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     "${WX_LIB_DIR}/wxbase32ud_gcc730_x64.dll"
#     "${WX_LIB_DIR}/wxmsw32ud_core_gcc730_x64.dll"
#     "${CMAKE_CURRENT_BINARY_DIR}"
# )

function(copy_dll target dll_path)
    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${dll_path}"
        "${CMAKE_CURRENT_BINARY_DIR}"
    )
endfunction()

copy_dll(wxApp "${WX_LIB_DIR}/wxbase32ud_gcc730_x64.dll")
copy_dll(wxApp "${WX_LIB_DIR}/wxmsw32ud_core_gcc730_x64.dll")

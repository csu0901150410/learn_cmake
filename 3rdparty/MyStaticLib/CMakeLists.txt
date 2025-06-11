cmake_minimum_required(VERSION 3.10)

project(MyStaticLib)

# 设置输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 添加静态库目标
add_library(MyStaticLib STATIC
    src/my_static_lib.cpp
)

# 包含头文件目录，PUBLIC将静态库头文件目录暴露给使用者
target_include_directories(MyStaticLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

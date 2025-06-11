cmake_minimum_required(VERSION 3.10)

project(learn_cmake)

# 添加子目录，将子库作为项目的一部分构建
add_subdirectory(3rdparty/MyStaticLib)


# 当前目录下所有源文件存储在变量SRC_LIST中
aux_source_directory(${PROJECT_BINARY_DIR}/../src SRC_LIST)

# 指定头文件目录
include_directories(${PROJECT_BINARY_DIR}/../inc)

# 指定多个头文件目录
# include_directories(./inc1 ./inc2)

add_executable(demo ${SRC_LIST})

# 链接静态库
target_link_libraries(demo PRIVATE MyStaticLib)

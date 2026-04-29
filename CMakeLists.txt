cmake_minimum_required(VERSION 3.23)

project(ProjectName)

add_executable(TargetName)

target_sources(TargetName
    PRIVATE
        src/main.cpp
)

add_library(LibraryName)

target_sources(LibraryName
    PRIVATE
        src/math/math.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            src/math
        FILES
            src/math/math.h
)

cmake_minimum_required(VERSION 3.23)

project(ProjectName)

add_executable(TargetName)

target_sources(TargetName
    PRIVATE
        src/main.cpp
)

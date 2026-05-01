cmake_minimum_required(VERSION 3.23)

project(ProjectName)

option(IS_BUILD_APP "Build the Application executable" OFF)

if (IS_BUILD_APP)
    add_subdirectory(app)
endif()

add_subdirectory(utils)

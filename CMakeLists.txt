cmake_minimum_required(VERSION 3.18)
project(
    vector3d
    VERSION 0.0.0
    DESCRIPTION "Vector3D"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

set(sources
    src/vector3d.h
    src/vector3d.cpp
    src/main.cpp
)

# Создаём исполняемый файл
add_executable(vector3d ${sources})

# Говорим компилятору, где искать заголовки (в данном случае — в src/)
target_include_directories(vector3d PRIVATE src)

include(GenerateExportHeader)
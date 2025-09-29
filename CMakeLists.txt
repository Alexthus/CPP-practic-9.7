cmake_minimum_required(VERSION 3.18)
project(
    lesson8
    VERSION 0.0.0
    DESCRIPTION "Sorting"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(LINK_FLAGS "-mconsole")
#-mwindows  -Wl, subsystem, console

set(sources 
    src/book.h
    src/book.cpp
    src/main.cpp)

add_executable(test WIN32 ${sources})

find_package(Qt5 COMPONENTS Core REQUIRED)

target_link_libraries(test PRIVATE Qt5::Core ${LINK_FLAGS})

set_property(TARGET test PROPERTY WIN32_EXECUTABLE true)
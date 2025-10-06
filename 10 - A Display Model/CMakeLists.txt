cmake_minimum_required(VERSION 3.16)
project(drill LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES
    drill.cpp
    Graph.cpp
    Window.cpp
    GUI.cpp
    Simple_window.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)

add_executable(drill ${SOURCES})
target_include_directories(drill PRIVATE Headers)
target_link_libraries(drill PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)

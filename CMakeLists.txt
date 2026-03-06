cmake_minimum_required(VERSION 3.10)

project(Program)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(program
    src/main.cpp
    src/Game.cpp
)

target_link_libraries(program
    sfml-graphics
    sfml-window
    sfml-system
)
cmake_minimum_required(VERSION 3.27)
project(space_invaders)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "/usr/share/SFML/cmake/Modules/")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE src "src/*")
include_directories(include)
add_library(myLibrary ${src})

add_executable(space_invaders main.cpp)
target_link_libraries(space_invaders myLibrary sfml-graphics sfml-window sfml-system)

add_executable(test test.cpp)
target_link_libraries(test sfml-graphics sfml-window sfml-system)


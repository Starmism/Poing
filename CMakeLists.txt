cmake_minimum_required(VERSION 3.13)
project(POING)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
add_executable(POING main.h main.cpp Bat.cpp Bat.h Ball.cpp Ball.h)
target_link_libraries(POING sfml-graphics)
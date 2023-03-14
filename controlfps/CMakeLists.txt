cmake_minimum_required(VERSION 3.24)
project(controlfps C)
link_libraries(SDL2)
set(CMAKE_C_STANDARD 11)

add_executable(controlfps main.c)

cmake_minimum_required(VERSION 3.24)
project(project1 C)

set(CMAKE_C_STANDARD 11)
link_libraries(SDL2 SDL2_mixer SDL2_image SDL2_ttf)
add_executable(project1 main.c resource.c resource.h)

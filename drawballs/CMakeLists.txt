cmake_minimum_required(VERSION 3.24)
project(drawballs C)
link_libraries(SDL2 SDL2_image)
set(CMAKE_C_STANDARD 11)

add_executable(drawballs main.c ball.c ball.h resource.c resource.h)

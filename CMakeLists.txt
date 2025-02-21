cmake_minimum_required(VERSION 3.27)
project(ConvaySim C)

set(SDL3_DIR "C:/Users/maxda/SDL3-devel-3.2.4-VC/SDL3-3.2.4/cmake")
find_package(SDL3 REQUIRED COMPONENTS SDL3)
set(CMAKE_C_STANDARD 23)

add_executable(ConvaySim main.c
        GAME_OF_LIFE.h
        Simulation.c
)
target_link_libraries(ConvaySim PRIVATE SDL3::SDL3)

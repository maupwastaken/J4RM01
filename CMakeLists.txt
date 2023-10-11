cmake_minimum_required(VERSION 3.26)
project(J4Rm01)

set(CMAKE_CXX_STANDARD 17)

add_executable(J4Rm01 src/Egypts/main.cpp
        src/Egypts/timer.h
        src/Egypts/items.h
        src/Amazons/main.cpp
        src/main.cpp)

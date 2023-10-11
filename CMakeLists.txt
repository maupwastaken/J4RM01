cmake_minimum_required(VERSION 3.26)
project(J4Rm01)

set(CMAKE_CXX_STANDARD 17)

add_executable(J4Rm01 src/main.cpp
        src/timer.h
        src/items.h
        Amazons/src/main.cpp)

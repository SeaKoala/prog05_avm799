cmake_minimum_required(VERSION 3.14)
project(prog05_avm799)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(prog05_avm799
        Song.cpp
        Song.h
        UtPod.cpp
        UtPod.h
        UtPodDriver.cpp)

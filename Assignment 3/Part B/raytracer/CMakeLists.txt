cmake_minimum_required(VERSION 3.10)
project(raytracer)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(raytracer
        bmp_io.cpp
        bmp_io.h
        light_source.cpp
        light_source.h
        main.cpp
        raytracer.cpp
        raytracer.h
        scene_object.cpp
        scene_object.h
        util.cpp
        util.h)

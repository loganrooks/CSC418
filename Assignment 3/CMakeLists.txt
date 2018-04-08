cmake_minimum_required(VERSION 3.10)
project(Assignment_3)

set(CMAKE_CXX_STANDARD 11)

include_directories("Part A/raytracer")
include_directories("Part B/raytracer")

add_executable(Assignment_3
        "Part A/raytracer/bmp_io.cpp"
        "Part A/raytracer/bmp_io.h"
        "Part A/raytracer/light_source.cpp"
        "Part A/raytracer/light_source.h"
        "Part A/raytracer/main.cpp"
        "Part A/raytracer/raytracer.cpp"
        "Part A/raytracer/raytracer.h"
        "Part A/raytracer/scene_object.cpp"
        "Part A/raytracer/scene_object.h"
        "Part A/raytracer/util.cpp"
        "Part A/raytracer/util.h"
        "Part B/raytracer/bmp_io.cpp"
        "Part B/raytracer/bmp_io.h"
        "Part B/raytracer/light_source.cpp"
        "Part B/raytracer/light_source.h"
        "Part B/raytracer/main.cpp"
        "Part B/raytracer/raytracer.cpp"
        "Part B/raytracer/raytracer.h"
        "Part B/raytracer/scene_object.cpp"
        "Part B/raytracer/scene_object.h"
        "Part B/raytracer/util.cpp"
        "Part B/raytracer/util.h")

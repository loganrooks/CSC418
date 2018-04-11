/***********************************************************
	
	Starter code for Assignment 3

***********************************************************/

#include <cstdlib>
#include "raytracer.h"
#include "scenes.h"
#include "experiments.h"

int main(int argc, char* argv[]) {
    // Build your scene and setup your camera here, by calling
    // functions from Raytracer.  The code here sets up an example
    // scene and renders it from two different view points, DO NOT
    // change this if you're just implementing part one of the
    // assignment.

    int width = 1920;
    int height = 1080;

    if (argc == 3) {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
    }

//    recursive_ray_tracing(width, height);
//    hard_shadows(width, height);
//    anti_aliasing(width, height);
//    soft_shadows(width, height, 200, 4, 0.8);
//    environment_mapping(width, height);
//    texture_mapping(width, height);
//    refraction(width, height);
//    portal_test(width,height);
    final(width, height, 40, 1, 0.8);

    return 0;
}





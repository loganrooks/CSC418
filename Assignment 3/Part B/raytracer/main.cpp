
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

    // We use a 16:9 ratio for the images, most of the images in the renderings folder used the dimensions 2560x1440
    int width = 480;
    int height = 270;

    if (argc == 3) {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
    }
// The tests, comment out any ones you don't want to run
    recursive_ray_tracing(width, height);
    hard_shadows(width, height);
    anti_aliasing(width, height);
    soft_shadows(width, height, 50, 2, 0.8); // For our rendering, we used 200 lights within a radius of 4
    environment_mapping(width, height);
    texture_mapping(width, height);
    refraction(width, height);
    portal_test(width,height);
    final(width, height);

    return 0;
}





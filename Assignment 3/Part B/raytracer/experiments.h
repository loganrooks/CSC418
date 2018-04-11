//
// Created by logan on 10/04/18.
//


#ifndef RAYTRACER_EXPERIMENTS_H
#define RAYTRACER_EXPERIMENTS_H
#include "light_source.h"
#include "scene_object.h"
#include "scenes.h"
#include "raytracer.h"

int refraction(int width, int height);
int recursive_ray_tracing(int width, int height);
int hard_shadows(int width, int height);
int anti_aliasing(int width, int height);
int soft_shadows(int width, int height, int numLights, int radius, double intensity);
int environment_mapping(int width, int height);
int texture_mapping(int width, int height);
int portal_test(int width, int height);
int final(int width, int height);


#endif //RAYTRACER_EXPERIMENTS_H


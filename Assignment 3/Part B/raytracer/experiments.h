//
// Created by logan on 10/04/18.
//


#ifndef RAYTRACER_EXPERIMENTS_H
#define RAYTRACER_EXPERIMENTS_H

#endif //RAYTRACER_EXPERIMENTS_H

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
int portal(int width, int height);

Material glass(Color(0, 0, 0), Color(0.1,0.2,0.6),
               Color(1,1,1),
               40, 0, 1.5);

Material water(Color(0, 0, 0), Color(0.1,0.2,0.6),
               Color(1,1,1),
               40, 0, 1.3);
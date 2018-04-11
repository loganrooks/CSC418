//
// Created by logan on 10/04/18.
//



#ifndef RAYTRACER_SCENES_H
#define RAYTRACER_SCENES_H

#include "scene_object.h"
#include "light_source.h"

int portal_scene(LightList& light_list, Scene& scene);
int simple_scene(LightList& light_list, Scene& scene);
int simple_portal_scene(LightList& light_list, Scene& scene);


#endif //RAYTRACER_SCENES_H
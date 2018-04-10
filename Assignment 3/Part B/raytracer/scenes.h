//
// Created by logan on 10/04/18.
//

#include "scene_object.h"
#include "light_source.h"

#ifndef RAYTRACER_SCENES_H
#define RAYTRACER_SCENES_H

#endif //RAYTRACER_SCENES_H
int portal_scene(LightList& light_list, Scene& scene);
int simple_scene(LightList& light_list, Scene& scene);
int simple_portal_scene(LightList& light_list, Scene& scene);

Material grey(Color(0, 0, 0), Color(0.5, 0.5, 0.5),
              Color(0.3, 0.3, 0.3), 5, 0, 0);
Material black(Color(0, 0, 0), Color(0, 0, 0),
               Color(0.3, 0.3, 0.3), 5, 0, 0);
Material orange_slime(Color(0.3, 0.2, 0), Color(0.7, 0.45, 0),
                      Color(0.3, 0.2, 0.1), 5, 0.05, 0);
Material red(Color(0, 0, 0), Color(0.6, 0.3, 0.3),
             Color(0.3, 0.3, 0.3), 5, 0, 0);
Material blue(Color(0, 0, 0), Color(0.3, 0.3, 0.6),
              Color(0.3, 0.3, 0.3), 5, 0, 0);
Material green(Color(0, 0, 0), Color(0.3, 0.6, 0.3),
               Color(0.3, 0.3, 0.3), 5, 0, 0);
Material wood(Color(0,0,0), Color(0.392,0.117,0.0),
              Color(0.45,0.14,0.0),
              12.8, 0, 0);
Material copper(Color(0.19125 , 0.0735, 0.0225), Color(0.7038,0.27048,0.0828),
                Color(0.256777, 0.137622, 0.086014),
                12.8);
Material obsidian(Color(0.05375, 0.05, 0.06625), Color(0.18275, 0.17, 0.22525),
                  Color(0.332741, 0.328634, 0.346435),
                  38.4, 0, 0);

Material wormhole(Color(0.05375, 0.05, 0.06625), Color(0.18275, 0.17, 0.22525),
                  Color(0.332741, 0.328634, 0.346435),
                  38.4, 0.97, 0);

Material mirror(Color(0, 0, 0), Color(0.5,0.5,0.5),
                Color(0.5,0.5,0.5),
                19, 0.95, 0);
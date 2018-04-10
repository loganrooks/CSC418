/***********************************************************
	
	Starter code for Assignment 3
	
	This file contains the interface and datastructures of the raytracer.  
	Simple traversal and addition code to the datastructures are given to you.

***********************************************************/
#pragma once

#include "util.h"
#include "scene_object.h"
#include "light_source.h"

#define NT 1.5

class Raytracer {
public:
	// Renders 3D scene to an image given camera and lights setup.

	bool shadows;
	bool antialias;
	int max_depth;
	bool use_envmap;
	bool wormhole_effect = false;

	void render(Camera& camera, Scene& scene, LightList& light_list, Image& image);

	Raytracer(bool shadows, int max_depth, bool antialias, bool use_envmap) :
			shadows(shadows), antialias(antialias), max_depth(max_depth), use_envmap(use_envmap) {}


private:

	// Return the color of the ray after intersection and shading, call 
	// this function recursively for reflection and refraction.  
	Color shadeRay(Ray3D& ray, Scene& scene, LightList& light_list, int depth);

	// Traversal code for the scene, the ray is transformed into 
	// the object space of each node where intersection is performed.
	void traverseScene(Scene& scene, Ray3D& ray);

	// After intersection, calculate the color of the ray by shading it
	// with all light sources in the scene.
	void computeShading(Ray3D &ray, Scene &scene, LightList &light_list, bool shadows);

	// Precompute the modelToWorld and worldToModel transformations for each
    // object in the scene.
	void computeTransforms(Scene& scene);

	std::vector<Ray3D> antiAlias(Matrix4x4 viewToWorld, Point3D imagePlane, Point3D origin, double factor);

	void addTextureInfo(SceneNode *node, Ray3D &ray);

    Vector3D computeRefraction(Vector3D normal, Vector3D incident, double n1, double n2);

    Vector3D computeReflection(Vector3D normal, Vector3D incident);

	CubeMap* envmap;
};


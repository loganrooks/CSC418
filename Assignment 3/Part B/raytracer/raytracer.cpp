/***********************************************************
	
	Starter code for Assignment 3

	Implementations of functions in raytracer.h, 
	and the main function which specifies the scene to be rendered.	

***********************************************************/


#include "raytracer.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

void Raytracer::traverseScene(Scene& scene, Ray3D& ray)  {
	for (size_t i = 0; i < scene.size(); ++i) {
		SceneNode* node = scene[i];

		if (node->obj->intersect(ray, node->worldToModel, node->modelToWorld)) {
			ray.intersection.mat = node->mat;
		}
	}
}

void Raytracer::computeTransforms(Scene& scene) {
	// right now this method might seem redundant. But if you decide to implement 
	// scene graph this is where you would propagate transformations to child nodes
		
	for (size_t i = 0; i < scene.size(); ++i) {
		SceneNode* node = scene[i];

		node->modelToWorld = node->trans;
		node->worldToModel = node->invtrans; 
	}
}

void Raytracer::computeShading(Ray3D& ray, LightList& light_list) {
	for (size_t  i = 0; i < light_list.size(); ++i) {
		LightSource* light = light_list[i];
		
		// Each lightSource provides its own shading function.
		// Implement shadows here if needed.
		light->shade(ray);        
	}
}

Color Raytracer::shadeRay(Ray3D& ray, Scene& scene, LightList& light_list, int depth = 0) {
	Color col(0.0, 0.0, 0.0); 
	traverseScene(scene, ray); 

	// Don't bother shading if the ray didn't hit 
	// anything.
	if (!ray.intersection.none) {
		computeShading(ray, light_list); 
		col = ray.col;  
		
	}

	// You'll want to call shadeRay recursively (with a different ray, 
	// of course) here to implement reflection/refraction effects.  

	//Chris's contribution begins
	//recursive call:
	float epsilon = 0.0001;
	int maxDepth = 3;
	float reflectIndex = ray.intersection.mat->reflectIndex;

	if (!ray.intersection.none){
		if(reflectIndex != 0 && depth < maxDepth){
			//get reflection vector
			Vector3D normal = ray.intersection.normal;
			Vector3D incidentVec = ray.dir;
			Vector3D reflectVec = incidentVec - 2 * incidentVec.dot(normal) * normal;
			reflectVec.normalize();
			Point3D point = ray.intersection.point;
			point = point + epsilon*reflectVec;
			Ray3D reflectRay = Ray3D(point, reflectVec);

			//get reflection color
			Color refCol = shadeRay(reflectRay, scene, light_list, depth + 1);

			//return final color
			Color finalCol = reflectIndex*refCol + (1-reflectIndex)*col;
			//finalCol.clamp();
			return finalCol;
		}
	}
	//Chris's contribution ends


	return col; 
}	

void Raytracer::render(Camera& camera, Scene& scene, LightList& light_list, Image& image) {
	computeTransforms(scene);

	Matrix4x4 viewToWorld;
	double factor = (double(image.height)/2)/tan(camera.fov*M_PI/360.0);

	viewToWorld = camera.initInvViewMatrix();

	// Construct a ray for each pixel.
	for (int i = 0; i < image.height; i++) {
		for (int j = 0; j < image.width; j++) {
			// Sets up ray origin and direction in view space, 
			// image plane is at z = -1.
			Point3D origin(0, 0, 0);
			Point3D imagePlane;
			imagePlane[0] = (-double(image.width)/2 + 0.5 + j)/factor;
			imagePlane[1] = (-double(image.height)/2 + 0.5 + i)/factor;
			imagePlane[2] = -1;
			
			Ray3D ray;
			// TODO: Convert ray to world space  
			//define ray using origin, direction vector.
			// Logan's contribution begins
			ray.origin = viewToWorld * origin;
			ray.dir = viewToWorld * (imagePlane - origin);
			ray.dir.normalize();
			// Logan's contribution ends
			
			//Chris's contribution begins
			//Add Epsilon to reduce noise
			float epsilon = 0.0001;
			ray.origin = ray.origin + epsilon*ray.dir;
			//Chris's contribution ends
			Color col = shadeRay(ray, scene, light_list); 
			image.setColorAtPixel(i, j, col);			
		}
	}
}

void Raytracer::antiAliasRender4x(Camera& camera, Scene& scene, LightList& light_list, Image& image) {
	computeTransforms(scene);

	Matrix4x4 viewToWorld;
	double factor1 = (double(image.height)/2)/tan(camera.fov*M_PI/360.0);
	double factor2 = (double(image.width)/2)/tan(camera.fov*M_PI/360);

	viewToWorld = camera.initInvViewMatrix();

	// Construct a ray for each pixel.
	for (int i = 0; i < image.height; i++) {
		for (int j = 0; j < image.width; j++) {
			// Sets up ray origin and direction in view space, 
			// image plane is at z = -1.
			Point3D origin(0, 0, 0);
			Point3D imagePlane;
			imagePlane[0] = (-double(image.width)/2 + 0.5 + j)/factor2;
			imagePlane[1] = (-double(image.height)/2 + 0.5 + i)/factor1;
			imagePlane[2] = -1;
			
			Ray3D ray;
			// TODO: Convert ray to world space  
			//define ray using origin, direction vector.
			// Logan's contribution begins
			ray.origin = viewToWorld * origin;
			ray.dir = viewToWorld * (imagePlane - origin);
			ray.dir.normalize();
			// Logan's contribution ends
			
			//Chris's contribution begins
			//Add Epsilon to reduce noise
			float epsilon = 0.0001;
			ray.origin = ray.origin + epsilon*ray.dir;
			//Chris's contribution ends
			Color col = shadeRay(ray, scene, light_list); 
			image.setColorAtPixel(i, j, col);			
		}
	}
}


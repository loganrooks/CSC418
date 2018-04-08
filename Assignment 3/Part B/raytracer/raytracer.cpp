/***********************************************************
	
	Starter code for Assignment 3

	Implementations of functions in raytracer.h, 
	and the main function which specifies the scene to be rendered.	

***********************************************************/


#include "raytracer.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include <curses.h>

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

void Raytracer::computeShading(Ray3D& ray, Scene& scene, LightList& light_list, bool shadows) {
	for (size_t  i = 0; i < light_list.size(); ++i) {
		LightSource* light = light_list[i];
		
		// Each lightSource provides its own shading function.
		// Implement shadows here if needed.
		// Shadows - Logan's Contribution
		if (shadows) {
			auto light_position = light->get_position();
			auto light_direction = light_position - ray.intersection.point;
			auto distance_to_light = light_direction.length();
			light_direction.normalize();
			// Shadow ray, begins at object of interest plus small EPSILON so it does not actually intersect
			Ray3D shadow_ray(ray.intersection.point + EPSILON * light_direction, light_direction);
			traverseScene(scene, shadow_ray);
			if (!shadow_ray.intersection.none && (shadow_ray.intersection.t_value <= distance_to_light)) {
				ray.col = ray.intersection.mat->ambient;
				ray.col.clamp();
			} else {
				light->shade(ray);
			}
		}
		else {
			light->shade(ray);
		}

	}
}

Color Raytracer::shadeRay(Ray3D& ray, Scene& scene, LightList& light_list, int depth=0, bool shadows=FALSE, int max_depth=2) {
	Color col(0.0, 0.0, 0.0); 
	traverseScene(scene, ray); 

	// Don't bother shading if the ray didn't hit 
	// anything.
	if (!ray.intersection.none) {
		computeShading(ray, scene, light_list, shadows);
		col = ray.col;  
		
	}

	// You'll want to call shadeRay recursively (with a different ray, 
	// of course) here to implement reflection/refraction effects.  

	//Chris's contribution begins
	//recursive call:
	float epsilon = 0.0001;

	float reflectIndex = ray.intersection.mat->reflectIndex;

	if (!ray.intersection.none){
		if(reflectIndex != 0 && depth < max_depth){
			//get reflection vector
			Vector3D normal = ray.intersection.normal;
			Vector3D incidentVec = ray.dir;
			Vector3D reflectVec = incidentVec - 2 * incidentVec.dot(normal) * normal;
			reflectVec.normalize();
			Point3D point = ray.intersection.point;
			point = point + epsilon*reflectVec;
			Ray3D reflectRay = Ray3D(point, reflectVec);

			//get reflection color
			Color refCol = shadeRay(reflectRay, scene, light_list, depth + 1, shadows, max_depth);

			//return final color
			Color finalCol = reflectIndex*refCol + (1-reflectIndex)*col;
			//finalCol.clamp();
			return finalCol;
		}
	}
	//Chris's contribution ends


	return col; 
}	

void Raytracer::render(Camera& camera, Scene& scene, LightList& light_list, Image& image, bool shadows=FALSE, int max_depth=2, bool antialias=FALSE) {
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
			Color col(0,0,0);
			if (antialias) {
				Ray3D* rays = antiAlias(viewToWorld, imagePlane, origin, factor);
				col = (1.0/8.0) * (shadeRay(rays[0], scene, light_list, 0, shadows, max_depth) +
										 shadeRay(rays[1], scene, light_list, 0, shadows, max_depth) +
										 shadeRay(rays[2], scene, light_list, 0, shadows, max_depth) +
										 shadeRay(rays[3], scene, light_list, 0, shadows, max_depth) +
										 shadeRay(rays[4], scene, light_list, 0, shadows, max_depth) +
										 shadeRay(rays[5], scene, light_list, 0, shadows, max_depth) +
										 shadeRay(rays[6], scene, light_list, 0, shadows, max_depth) +
										 shadeRay(rays[7], scene, light_list, 0, shadows, max_depth));
			}
			else {
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
				ray.origin = ray.origin + EPSILON * ray.dir;
				//Chris's contribution ends
				col = shadeRay(ray, scene, light_list, 0, shadows, max_depth);
			}
			image.setColorAtPixel(i, j, col);
		}
	}
}

Ray3D* Raytracer::antiAlias(Matrix4x4 viewToWorld, Point3D imagePlane, Point3D origin, double factor) {

	Point3D imagePlane1;
	Point3D imagePlane11;
	Point3D imagePlane2;
	Point3D imagePlane22;
	Point3D imagePlane3;
	Point3D imagePlane33;
	Point3D imagePlane4;
	Point3D imagePlane44;

	//top left quadrant: (double(rand()/RAND_MAX))*
	imagePlane1[0] = imagePlane[0] - (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane1[1] = imagePlane[1] + (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane1[2] = imagePlane[2];
	imagePlane11[0] = imagePlane[0] - (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane11[1] = imagePlane[1] + (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane11[2] = imagePlane[2];

	//top right quadrant:
	imagePlane2[0] = imagePlane[0] + (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane2[1] = imagePlane[1] + (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane2[2] = imagePlane[2];
	imagePlane22[0] = imagePlane[0] + (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane22[1] = imagePlane[1] + (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane22[2] = imagePlane[2];

	//bottom right quadrant:
	imagePlane3[0] = imagePlane[0] + (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane3[1] = imagePlane[1] - (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane3[2] = imagePlane[2];
	imagePlane33[0] = imagePlane[0] + (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane33[1] = imagePlane[1] - (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane33[2] = imagePlane[2];


	//bottom left quadrant:
	imagePlane4[0] = imagePlane[0] - (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane4[1] = imagePlane[1] - (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane4[2] = imagePlane[2];
	imagePlane44[0] = imagePlane[0] - (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane44[1] = imagePlane[1] - (double(rand())/double(RAND_MAX))/(factor*2.0);
	imagePlane44[2] = imagePlane[2];


	Ray3D ray1;
	Ray3D ray11;
	Ray3D ray2;
	Ray3D ray22;
	Ray3D ray3;
	Ray3D ray33;
	Ray3D ray4;
	Ray3D ray44;

	ray1.origin = viewToWorld * origin;
	ray1.dir = viewToWorld * (imagePlane1 - origin);
	ray1.dir.normalize();
	ray11.origin = viewToWorld * origin;
	ray11.dir = viewToWorld * (imagePlane1 - origin);
	ray11.dir.normalize();

	ray2.origin = viewToWorld * origin;
	ray2.dir = viewToWorld * (imagePlane2 - origin);
	ray2.dir.normalize();
	ray22.origin = viewToWorld * origin;
	ray22.dir = viewToWorld * (imagePlane2 - origin);
	ray22.dir.normalize();

	ray3.origin = viewToWorld * origin;
	ray3.dir = viewToWorld * (imagePlane3 - origin);
	ray3.dir.normalize();
	ray33.origin = viewToWorld * origin;
	ray33.dir = viewToWorld * (imagePlane3 - origin);
	ray33.dir.normalize();

	ray4.origin = viewToWorld * origin;
	ray4.dir = viewToWorld * (imagePlane4 - origin);
	ray4.dir.normalize();
	ray44.origin = viewToWorld * origin;
	ray44.dir = viewToWorld * (imagePlane4 - origin);
	ray44.dir.normalize();

	//Add Epsilon to reduce noise

	ray1.origin = ray1.origin + EPSILON*ray1.dir;
	ray11.origin = ray11.origin + EPSILON*ray11.dir;
	ray2.origin = ray2.origin + EPSILON*ray2.dir;
	ray22.origin = ray22.origin + EPSILON*ray22.dir;
	ray3.origin = ray3.origin + EPSILON*ray3.dir;
	ray33.origin = ray33.origin + EPSILON*ray33.dir;
	ray4.origin = ray4.origin + EPSILON*ray4.dir;
	ray44.origin = ray44.origin + EPSILON*ray44.dir;

	Ray3D rays[] = {ray1, ray11, ray2, ray22, ray3, ray33, ray4, ray44};
	return rays;
}


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

double EPSILON = 0.0001;

extern Material wormhole;

void Raytracer::addTextureInfo(SceneNode* node, Ray3D& ray)
{
	ray.intersection.has_texture = true;
	ray.intersection.texture_col = node->texture->get_colour_at_uv(ray.intersection.uv);
	//ray.intersection.normal = ray.intersection.normal
}

void Raytracer::traverseScene(Scene& scene, Ray3D& ray)  {
	for (size_t i = 0; i < scene.size(); ++i) {
		SceneNode* node = scene[i];

		if (node->obj->intersect(ray, node->worldToModel, node->modelToWorld)) {
			ray.intersection.mat = node->mat;
				if (node->has_texture) {
					addTextureInfo(node, ray);
				}
				else {
					ray.intersection.has_texture = false;
				}
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
	int n_lights = light_list.size();

	for (size_t  i = 0; i < n_lights; ++i) {
		LightSource *light = light_list[i];
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
//			std::cout << "\nLight Distance: " << distance_to_light << std::endl;
//			std::cout << "Shadow Ray Intercept Distance: " << shadow_ray.intersection.t_value << std::endl;
//			std::cout << "Is there shadow?: " << (!shadow_ray.intersection.none && (shadow_ray.intersection.t_value <= distance_to_light)) << std::endl;
			Intersection shadow_intersect = shadow_ray.intersection;
			ray.inShadow = !shadow_intersect.none && shadow_intersect.t_value <= distance_to_light && shadow_intersect.mat->refractIndex < EPSILON;
		}
//		if (shadows) std::cout << "inShadow: " << ray.inShadow << std::endl;
		light->shade(ray);
	}
}
Vector3D Raytracer::computeReflection(Vector3D normal, Vector3D incident) {
	Vector3D reflect = incident - 2 * incident.dot(normal) * normal;
	reflect.normalize();
	return reflect;
}

Vector3D Raytracer::computeRefraction(Vector3D normal, Vector3D incident, double n1, double n2)
{
	normal.normalize();
	incident.normalize();
	double cosAlpha = normal.dot(incident);
	if (cosAlpha < 0) { cosAlpha = -cosAlpha; } else {std::swap(n1, n2), normal = -normal;}
	double eta = n1/n2;
	double k = 1 - eta * eta * (1 - cosAlpha * cosAlpha);
	// Total internal reflection
	if (k < 0) {
		return computeReflection(normal, incident);
	}
	else {
		Vector3D refract = eta * incident + (eta * cosAlpha - sqrt(k)) * normal;
		refract.normalize();
		return refract;
	}

}

Color Raytracer::shadeRay(Ray3D& ray, Scene& scene, LightList& light_list, int depth) {
	Color col(0.0, 0.0, 0.0);
	traverseScene(scene, ray); 

	// You'll want to call shadeRay recursively (with a different ray, 
	// of course) here to implement reflection/refraction effects.  

	//Chris's contribution begins
	//recursive call:



	if (!ray.intersection.none && !ray.wormhole){
		computeShading(ray, scene, light_list, shadows);
		//std::cout << "After shading: " << ray.col << std::endl;
		auto refract_col = Color(0,0,0);

		float reflectIndex = ray.intersection.mat->reflectIndex;
		float refractIndex = ray.intersection.mat->refractIndex;

		Vector3D normal = ray.intersection.normal;
		normal.normalize();
		Vector3D incidentVec = ray.dir;
		incidentVec.normalize();
		double t_ray = ray.intersection.t_value;

		if(depth < max_depth){
			if (reflectIndex > 0) {
				//get reflection vector
				Vector3D reflectVec = computeReflection(normal, incidentVec);
				Point3D point = ray.intersection.point;
				point = point + EPSILON * reflectVec;
				Ray3D reflect_ray = Ray3D(point, reflectVec);
				reflect_ray.reflected = true;
				reflect_ray.intersection.has_texture = false;
				reflect_ray.wormhole = ray.intersection.mat == &wormhole;

				//get reflection color
				Color reflect_col = shadeRay(reflect_ray, scene, light_list, depth + 1);
				ray.col = reflectIndex * reflect_col + (1 - reflectIndex) * ray.col;
				ray.col.clamp();
			}
//
			if (refractIndex > 1) {

				double n1 = 1;
				double n2 = ray.intersection.mat->refractIndex;


				Vector3D refract_dir = computeRefraction(normal, incidentVec, n1, n2);

				// refract ray
				Ray3D refract_ray(ray.intersection.point + EPSILON * refract_dir, refract_dir);
				refract_ray.refracted = true;
				ray.col = shadeRay(refract_ray, scene, light_list, depth + 1);
				ray.col.clamp();
			}
		}
		col = ray.col;
	}
	else {
		// else it intersects nothing, get cube map value for the ray direction
		if (use_envmap && (ray.wormhole || !wormhole_effect)){
			col = envmap->query_bmp_cube_map(ray.dir);
		}
	}
	return col;
}	

void Raytracer::render(Camera& camera, Scene& scene, LightList& light_list, Image& image) {
	computeTransforms(scene);

	Matrix4x4 viewToWorld;
	double factor = (double(image.height)/2)/tan(camera.fov*M_PI/360.0);

	viewToWorld = camera.initInvViewMatrix();

	if(use_envmap) {
		envmap = new CubeMap;
		envmap->set_face_images();
	}

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
			Color col(0.0,0.0,0.0);
			if (antialias) {
				std::vector<Ray3D> rays = antiAlias(viewToWorld, imagePlane, origin, factor);
				col = (1.0/8.0) * (shadeRay(rays[0], scene, light_list, 0) +
										 shadeRay(rays[1], scene, light_list, 0) +
										 shadeRay(rays[2], scene, light_list, 0) +
										 shadeRay(rays[3], scene, light_list, 0) +
										 shadeRay(rays[4], scene, light_list, 0) +
										 shadeRay(rays[5], scene, light_list, 0) +
										 shadeRay(rays[6], scene, light_list, 0) +
										 shadeRay(rays[7], scene, light_list, 0));
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
				col = shadeRay(ray, scene, light_list, 0);
			}
			image.setColorAtPixel(i, j, col);
		}
	}
}

std::vector<Ray3D> Raytracer::antiAlias(Matrix4x4 viewToWorld, Point3D imagePlane, Point3D origin, double factor) {

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

	std::vector<Ray3D> rays({ray1, ray11, ray2, ray22, ray3, ray33, ray4, ray44});

	return rays;
}


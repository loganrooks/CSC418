/***********************************************************
	
	Starter code for Assignment 3

	Implements light_source.h

***********************************************************/

#include <cmath>
#include "light_source.h"
#include <algorithm>  

void PointLight::shade(Ray3D& ray) {
	// TODO: implement this function to fill in values for ray.col 
	// using phong shading.  Make sure your vectors are normalized, and
	// clamp colour values to 1.0.
	//
	// It is assumed at this point that the intersection information in ray 
	// is available.  So be sure that traverseScene() is called on the ray 
	// before this function.  
	
	//Chris's contribution begins
	Vector3D normal = ray.intersection.normal;
	Point3D point = ray.intersection.point;
	Vector3D viewVec = -1.0 * ray.dir;

	Color ambient = ray.intersection.mat->ambient;
	Color diffuse = ray.intersection.mat->diffuse;
	Color specular = ray.intersection.mat->specular;
	double specular_exp = ray.intersection.mat->specular_exp;

	Point3D lightPos = get_position();

	//Ambient 
	Color ambient_col = col_ambient * ambient;
	ambient_col.clamp();

	//Diffuse
	Vector3D lightVec = lightPos - point;
	lightVec.normalize();
	
	Color diffuse_light = std::max(0.0, normal.dot(viewVec)) * col_diffuse;
	Color diffuse_col = diffuse_light * diffuse;
	diffuse_col.clamp();
	
	//Specular
	Vector3D refVec = 2.0 * normal.dot(lightVec)*normal - lightVec;
	double cosTheta = std::max(0.0, viewVec.dot(refVec));
	Color specular_col = pow(cosTheta, specular_exp) * col_specular * specular;
	specular_col.clamp();
	
	ray.col = ambient_col + diffuse_col + specular_col;
	
	ray.col.clamp();
	//Chris's contribution ends
}


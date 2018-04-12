/***********************************************************
	
	Starter code for Assignment 3

	Implements light_source.h

***********************************************************/

#include <cmath>
#include "light_source.h"
#include <algorithm>
#include <assert.h>


void PointLight::shade(Ray3D& ray) {
	// TODO: implement this function to fill in values for ray.col 
	// using phong shading.  Make sure your vectors are normalized, and
	// clamp colour values to 1.0.
	//
	// It is assumed at this point that the intersection information in ray 
	// is available.  So be sure that traverseScene() is called on the ray 
	// before this function.

	Vector3D normal = ray.intersection.normal;
	Point3D point = ray.intersection.point;
	Vector3D viewVec = -ray.dir;

	Color ambient = ray.intersection.mat->ambient;
	Color diffuse = ray.intersection.mat->diffuse;
	Color specular = ray.intersection.mat->specular;
	double specular_exp = ray.intersection.mat->specular_exp;

	Point3D lightPos = get_position();
	//Ambient effect, multiply the ambient color of the light with the ambient color of the intersected material
	Color ambient_col = col_ambient * ambient;
	ambient_col.clamp();

	// If the ray is in shadow, only add the ambient color
	// and don't bother calculating other components, save some computation :)
	if (ray.inShadow) {
		ray.col = ray.col + ambient_col;
	}
	else {
		//Diffuse effect
		Vector3D lightVec = lightPos - point;
		lightVec.normalize();

		double n_dot_l = std::max(0.0, normal.dot(lightVec));

		Color diffuse_light = n_dot_l * col_diffuse;
		// If the intersected object has a texture, don't use the color of the underlying material but rather the
		// texture
		Color diffuse_col = ray.intersection.has_texture ? diffuse_light * ray.intersection.texture_col :
							diffuse_light * diffuse;
//		Color diffuse_col = diffuse_light * diffuse;
		diffuse_col.clamp();

		//Specular
		Vector3D refVec = 2.0 * n_dot_l * normal - lightVec;
		refVec.normalize();
		double cosTheta = std::max(0.0, viewVec.dot(refVec));
		Color specular_col = pow(cosTheta, specular_exp) * specular * col_specular;
		specular_col.clamp();

		ray.col = ray.col + ambient_col + diffuse_col + specular_col;
	}
	//std::cout << ray.col << std::endl;
	ray.col.clamp();
}


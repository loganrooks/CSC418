/***********************************************************
	
	Starter code for Assignment 3

***********************************************************/

#include <cstdlib>
#include "raytracer.h"

int main(int argc, char* argv[])
{
	// Build your scene and setup your camera here, by calling 
	// functions from Raytracer.  The code here sets up an example
	// scene and renders it from two different view points, DO NOT
	// change this if you're just implementing part one of the 
	// assignment.  
	Raytracer raytracer;
	LightList light_list;
	Scene scene;   

	int width = 320;
	int height = 240;

	if (argc == 3) {
		width = atoi(argv[1]);
		height = atoi(argv[2]);
	}
	//Chris's Contribution begins

	// Define materials for shading.
	Material red(Color(0.39 , 0.0, 0.0), Color(0.784,0.0,0.0),
		Color(0.7, 0.0, 0.0),
		51.2);
	Material mirror(Color(0, 0, 0), Color(0,0,0),
		Color(0,0,0),
		10, 1);
	Material grey(Color(0, 0, 0), Color(0.784,0.784,0.784),
		Color(0.7,0.7,0.7),
		12.8);
	Material brownred(Color(0,0,0), Color(0.392,0.117,0.0), 
		Color(0.45,0.14,0.0), 
		12.8);

	// Defines a point light source.
	PointLight* pLight = new PointLight(Point3D(18,18,18), Color(0.9,0.9,0.9));
	light_list.push_back(pLight);
	
	// Add a unit sphere into the scene with material mat.
	SceneNode* sphere = new SceneNode(new UnitSphere(), &red);
	scene.push_back(sphere);

	// add unit planes to make into room
	SceneNode* back = new SceneNode(new UnitSquare(), &mirror);
	scene.push_back(back);
	SceneNode* front = new SceneNode(new UnitSquare(), &grey);
	scene.push_back(front);
	SceneNode* left = new SceneNode(new UnitSquare(), &grey);
	scene.push_back(left);
	SceneNode* right = new SceneNode(new UnitSquare(), &grey);
	scene.push_back(right);
	SceneNode* top = new SceneNode(new UnitSquare(), &grey);
	scene.push_back(top);
	SceneNode* bottom = new SceneNode(new UnitSquare(), &brownred);
	scene.push_back(bottom);

	// Apply some transformations to the sphere
	double factor1[3] = { 1.0, 1.0, 1.0 };
	sphere->translate(Vector3D(5, 5, 5));
	sphere->scale(Point3D(0, 0, 0), factor1);

	// Apply transformations to make the room
	double factor2[3] = {20, 20, 20 };
	back->translate(Vector3D(0, 10, 10));
	back->rotate('y', 90);
	back->scale(Point3D(0, 0, 0), factor2);
	
	front ->translate(Vector3D(20,10,10));
	front->rotate('y', -90);
	front->scale(Point3D(0,0,0), factor2);

	left->translate(Vector3D(10, 10, 20));
	left->scale(Point3D(0, 0, 0), factor2);
	left->rotate('y', 180);

	right->translate(Vector3D(10, 10, 0));
	right->scale(Point3D(0, 0, 0), factor2);

	bottom->translate(Vector3D(10,0,10));
	bottom->rotate('x', -90);
	bottom->scale(Point3D(0,0,0), factor2);

	top->translate(Vector3D(10,20,10));
	top->rotate('x', 90);
	top->scale(Point3D(0,0,0), factor2);

	//Chris's contribution ends


	// Render the scene, feel free to make the image smaller for
	// testing purposes.	
	Camera camera1(Point3D(15, 10, 5), Vector3D(-3, -1, 1), Vector3D(0, 1, 0), 100.0);
	Image image1(width, height);
	raytracer.render(camera1, scene, light_list, image1); //render 3D scene to image
	image1.flushPixelBuffer("view1.bmp"); //save rendered image to file

	// Render it from a different point of view.
	Camera camera2(Point3D(10, 5, 10), Vector3D(-1, 0, -1), Vector3D(0, 1, 0), 100.0);
	Image image2(width, height);
	raytracer.render(camera2, scene, light_list, image2);
	image2.flushPixelBuffer("view2.bmp");

	// Free memory
	for (size_t i = 0; i < scene.size(); ++i) {
		delete scene[i];
	}

	for (size_t i = 0; i < light_list.size(); ++i) {
		delete light_list[i];
	}

	return 0;
}
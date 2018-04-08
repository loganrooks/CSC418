/***********************************************************
	
	Starter code for Assignment 3

***********************************************************/

#include <cstdlib>
#include <curses.h>
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

	int width = 480;
	int height = 360;

	if (argc == 3) {
		width = atoi(argv[1]);
		height = atoi(argv[2]);
	}
	//Chris's Contribution begins

	// Define materials for shading.
	Material copper(Color(0.19125 , 0.0735, 0.0225), Color(0.7038,0.27048,0.0828),
		Color(0.256777, 0.137622, 0.086014),
		12.8);
	Material obsidian(Color(0.05375, 0.05, 0.06625), Color(0.18275, 0.17, 0.22525),
		Color(0.332741, 0.328634, 0.346435),
		38.4);
	Material mirror(Color(0, 0, 0), Color(0,0,0),
		Color(0,0,0),
		12, 1);
	Material grey(Color(0.02, 0.02, 0.02), Color(0.82745,0.82745,0.82745),
		Color(0.2, 0.2, 0.2),
		50);
	Material wood(Color(0,0,0), Color(0.392,0.117,0.0), 
		Color(0.45,0.14,0.0), 
		12.8);

	// Defines a point light source. 
	PointLight* pLight = new PointLight(Point3D(14,18,15), Color(0.9,0.9,0.9));
	light_list.push_back(pLight);

	// Add unit spheres into the scene.
	SceneNode* sphere1 = new SceneNode(new UnitSphere(), &copper);
	scene.push_back(sphere1);

	SceneNode* sphere2 = new SceneNode(new UnitSphere(), &mirror);
	scene.push_back(sphere2);

	SceneNode* sphere3 = new SceneNode(new UnitSphere(), &obsidian);
	scene.push_back(sphere3);
	// add unit planes to make into room
	SceneNode* back = new SceneNode(new UnitSquare(), &grey);
	scene.push_back(back);
	SceneNode* front = new SceneNode(new UnitSquare(), &grey);
	scene.push_back(front);
	SceneNode* left = new SceneNode(new UnitSquare(), &grey);
	scene.push_back(left);
	SceneNode* right = new SceneNode(new UnitSquare(), &grey);
	scene.push_back(right);
	SceneNode* top = new SceneNode(new UnitSquare(), &grey);
	scene.push_back(top);
	SceneNode* bottom = new SceneNode(new UnitSquare(), &wood);
	scene.push_back(bottom);

	//Add unit planes to make mirror
	SceneNode* backMirror = new SceneNode(new UnitSquare(), &mirror);
	scene.push_back(backMirror);

	//Add unit planes to make frame
	SceneNode* leftFrontM = new SceneNode(new UnitSquare(), &wood);
	scene.push_back(leftFrontM);
	SceneNode* rightFrontM = new SceneNode(new UnitSquare(), &wood);
	scene.push_back(rightFrontM);
	SceneNode* topFrontM = new SceneNode(new UnitSquare(), &wood);
	scene.push_back(topFrontM);
	SceneNode* bottomFrontM = new SceneNode(new UnitSquare(), &wood);
	scene.push_back(bottomFrontM);

	//add unit planes to make light source box
	SceneNode* lightBack = new SceneNode(new UnitSquare(), &obsidian);
	scene.push_back(lightBack);
	SceneNode* lightFront= new SceneNode(new UnitSquare(), &obsidian);
	scene.push_back(lightFront);
	SceneNode* lightLeft = new SceneNode(new UnitSquare(), &obsidian);
	scene.push_back(lightLeft);
	SceneNode* lightRight = new SceneNode(new UnitSquare(), &obsidian);
	scene.push_back(lightRight);
	
	SceneNode* inBack = new SceneNode(new UnitSquare(), &obsidian);
	scene.push_back(inBack);
	SceneNode* inFront= new SceneNode(new UnitSquare(), &obsidian);
	scene.push_back(inFront);
	SceneNode* inLeft = new SceneNode(new UnitSquare(), &obsidian);
	scene.push_back(inLeft);
	SceneNode* inRight = new SceneNode(new UnitSquare(), &obsidian);
	scene.push_back(inRight);

	// Apply some transformations to the spheres
	double factorS1[3] = { 1.0, 1.0, 1.0 };
	double factorS2[3] = { 1.5, 1.5, 1.5 };
	sphere1->translate(Vector3D(5, 5, 10));
	sphere1->scale(Point3D(0, 0, 0), factorS1);

	sphere2->translate(Vector3D(10, 8, 12));
	sphere2->scale(Point3D(0,0,0), factorS2);

	sphere3->translate(Vector3D(3, 9, 8));
	sphere3->scale(Point3D(0, 0, 0), factorS1);
	
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

	// Apply transformations to make the mirror
	double factorM1[3] = {10,10,10};
  	backMirror->translate(Vector3D(0.25, 10, 10));
	backMirror->rotate('y', 90);
	backMirror->scale(Point3D(0, 0, 0), factorM1);

	// Apply transformations to make the frame
	double factorM2[3] = {0.5, 10.5, 1};
	leftFrontM->translate(Vector3D(0.5,10,15));
	leftFrontM->rotate('y', -90);
	leftFrontM->scale(Point3D(0,0,0), factorM2);
	
	rightFrontM->translate(Vector3D(0.5,10,5));
	rightFrontM->rotate('y', -90);
	rightFrontM->scale(Point3D(0,0,0), factorM2);
	
	topFrontM->translate(Vector3D(0.5, 15, 10));
	topFrontM->rotate('y', -90);
	topFrontM->rotate('z', 90);
	topFrontM->scale(Point3D(0,0,0), factorM2);
	
	bottomFrontM->translate(Vector3D(0.5, 5, 10));
	bottomFrontM->rotate('y', -90);
	bottomFrontM->rotate('z', 90);
	bottomFrontM->scale(Point3D(0,0,0), factorM2);
	
	
	//bottomSideM

	// Apply transformations to make the light box
	double factor3[3] = {2, 2, 1 };
	double factor4[3] = {3, 2, 1 };
	lightBack->translate(Vector3D(13, 20, 15));
	lightBack->rotate('y', 90);
	lightBack->scale(Point3D(0,0,0), factor4);
	inBack->translate(Vector3D(13.01, 20, 15));
	inBack->rotate('y', -90);
	inBack->scale(Point3D(0,0,0), factor4);

	lightFront->translate(Vector3D(15, 20, 15));
	lightFront->rotate('y', -90);
	lightFront->scale(Point3D(0,0,0), factor4);
	inFront->translate(Vector3D(14.99, 20, 15));
	inFront->rotate('y', 90);
	inFront->scale(Point3D(0,0,0), factor4);

	lightLeft->translate(Vector3D(14, 20, 16.5));
	lightLeft->rotate('y', 180);
	lightLeft->scale(Point3D(0,0,0), factor3);
	inLeft->translate(Vector3D(14, 20, 16.49));
	inLeft->scale(Point3D(0,0,0), factor3);

	lightRight->translate(Vector3D(14, 20, 13.5));
	lightRight->scale(Point3D(0,0,0), factor3);
	inRight->translate(Vector3D(14, 20, 13.49));
	inRight->rotate('y', 180);
	inRight->scale(Point3D(0,0,0), factor3);


	// Render the scene, remember to increase resolution for actual project
	Camera camera1(Point3D(18, 10, 15), Vector3D(-2, -1, -1), Vector3D(0, 1, 0), 60.0);
	Image image1(width, height);
	raytracer.render(camera1, scene, light_list, image1, FALSE, 5, FALSE); //render 3D scene to image
	image1.flushPixelBuffer("recursiveRT1.bmp"); //save rendered image to file
	std::cout << "Done: recursiveRT1" << std::endl;
	//Render it from a different point of view.
	Camera camera2(Point3D(18, 10, 2), Vector3D(-1, -0.5, 1), Vector3D(0, 1, 0), 60.0);
	Image image2(width, height);
	raytracer.render(camera2, scene, light_list, image2, FALSE, 5, FALSE);
	image2.flushPixelBuffer("recursiveRT2.bmp");
	std::cout << "Done: recursiveRT2" << std::endl;
	//Another point of view
	Camera camera3(Point3D(18, 8, 8), Vector3D(-1, 0.1, 0.1 ), Vector3D(0, 1, 0), 60.0);
	Image image3(width, height);
	raytracer.render(camera3, scene, light_list, image3, FALSE, 5, FALSE);
	image3.flushPixelBuffer("recursiveRT3.bmp");
	std::cout << "Done: recursiveRT3" << std::endl;
	// render all using 8x anti-aliasing
	/*
	raytracer.render(camera1, scene, light_list, image1, FALSE, 2, TRUE);
	image1.flushPixelBuffer("antiAlias1.bmp");
	std::cout << "Done: antiAlias1" << std::endl;
	raytracer.render(camera2, scene, light_list, image2, FALSE, 2, TRUE);
	image2.flushPixelBuffer("antiAlias2.bmp");
	std::cout << "Done: antiAlias2" << std::endl;
	raytracer.render(camera3, scene, light_list, image3, FALSE, 2, TRUE);
	image3.flushPixelBuffer("antiAlias3.bmp");
	std::cout << "Done: antiAlias3" << std::endl;
	*/

	// Hard shadows rendered
	raytracer.render(camera1, scene, light_list, image1, TRUE, 2, FALSE);
	image1.flushPixelBuffer("hardShadows1.bmp");
	std::cout << "Done: hardShadows1" << std::endl;

	raytracer.render(camera2, scene, light_list, image2, TRUE, 2, FALSE);
	image2.flushPixelBuffer("hardShadows2.bmp");
	std::cout << "Done: hardShadows2" << std::endl;

	raytracer.render(camera3, scene, light_list, image3, TRUE, 2, FALSE);
	image3.flushPixelBuffer("hardShadows3.bmp");
	std::cout << "Done: hardShadows3" << std::endl;

	// render all using extended lighting

	//Add extended light sources
	double x = 13.0;
	double y = 18.0;
	double z = 13.5;
	double density = 10.0; //Number of lights per unit length
	double xNum = 1.0 * density;
	double yNum = 1.0 * density;
	double dist = 1.0/density;

	for (int i = 0; i < xNum; i++) {
		for (int j = 0; j < yNum; j++) {
			light_list.push_back(new PointLight(Point3D(x,y,z), Color(0.9,0.9,0.9)));
			x += dist;
			y += dist;
		}	
		
	}
	raytracer.render(camera1, scene, light_list, image1, TRUE, 1, FALSE);
	image1.flushPixelBuffer("extendedLights1.bmp");
	std::cout << "Done: extendedLights1" << std::endl;

	raytracer.render(camera2, scene, light_list, image2, TRUE, 1, FALSE);
	image2.flushPixelBuffer("extendedLights2.bmp");
	std::cout << "Done: extendedLights2" << std::endl;

	raytracer.render(camera3, scene, light_list, image3, TRUE, 1, FALSE);
	image3.flushPixelBuffer("extendedLights3.bmp");
	std::cout << "Done: extendedLights3" << std::endl;

	//Chris's Contribution ends



	// Free memory
	for (size_t i = 0; i < scene.size(); ++i) {
		delete scene[i];
	}

	for (size_t i = 0; i < light_list.size(); ++i) {
		delete light_list[i];
	}

	return 0;
}
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

	// Defines a point light source. (NEED TO MOVE THIS LIGHT SOURCE TO THE LAMP. NEED TO FIND LAMP COORDINATES)
	PointLight* pLight = new PointLight(Point3D(18,18,18), Color(0.9,0.9,0.9));
	light_list.push_back(pLight);
	
	//TEMP TEST SPHERE
	//ceneNode* sphere1 = new SceneNode(new UnitSphere(), &copper);
	//scene.push_back(sphere1);
	//double factor6[3] = { 0.25, 0.25, 0.25 };
	//sphere1->translate(Vector3D(15,19,13));
	//sphere1->scale(Point3D(0,0,0), factor6);

	// Add a unit sphere into the scene with material mat.
	SceneNode* sphere = new SceneNode(new UnitSphere(), &copper);
	scene.push_back(sphere);

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

	// Apply some transformations to the sphereS
	double factor1[3] = { 1.0, 1.0, 1.0 };
	sphere->translate(Vector3D(5, 5, 10));
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
	raytracer.render(camera1, scene, light_list, image1); //render 3D scene to image
	image1.flushPixelBuffer("recursiveRT1.bmp"); //save rendered image to file

	//Render it from a different point of view.
	Camera camera2(Point3D(18, 10, 2), Vector3D(-1, -0.5, 1), Vector3D(0, 1, 0), 60.0);
	Image image2(width, height);
	raytracer.render(camera2, scene, light_list, image2);
	image2.flushPixelBuffer("recursiveRT2.bmp");

	Camera camera3(Point3D(18, 5, 9), Vector3D(-1, 0.2,0.05 ), Vector3D(0, 1, 0), 60.0);
	Image image3(width, height);
	raytracer.render(camera3, scene, light_list, image3);
	image3.flushPixelBuffer("recursiveRT3.bmp");
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
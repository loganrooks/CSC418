/***********************************************************

	 Starter code for Assignment 3


	Classes defining primitives in the scene

***********************************************************/
#ifndef __SCENE_OBJECT_H_INCLUDED__
#define __SCENE_OBJECT_H_INCLUDED__


#include "util.h"

#include <vector>
extern Material obsidian;
// All primitives should provide an intersection function.  
// To create more primitives, inherit from SceneObject.
// Namely, you can create, Sphere, Cylinder, etc... classes
// here.
class SceneObject {
public:
	// Returns true if an intersection occured, false otherwise.
	virtual bool intersect(Ray3D&, const Matrix4x4&, const Matrix4x4&) = 0;
	virtual ~SceneObject() {}
};


// Scene node containing information about an object: geometry, material, 
// tranformations.
struct SceneNode {
	SceneNode() 
	: 
	obj(NULL), mat(NULL), has_texture(false), is_portal(false) {}

	SceneNode(SceneObject* obj, Material* mat) 
	: 
	obj(obj), mat(mat), has_texture(false), is_portal(false) {}

	
	~SceneNode() {
		if (obj) delete obj;
	}

	// Apply rotation about axis 'x', 'y', 'z' angle degrees to node.
	void rotate(char axis, double angle);

	// Apply translation in the direction of trans to node.
	void translate(Vector3D trans);

	// Apply scaling about a fixed point origin.
	void scale(Point3D origin, double factor[3]);

	void transformPortal(Vector3D location, Vector3D normal, double scale);

	// Pointer to geometry primitive, used for intersection.
	SceneObject* obj;
	
	// Pointer to material of the object, used in shading.
	Material* mat;
	
	// Each node maintains a transformation matrix, which maps the 
	// geometry from object space to world space and the inverse.
	Point3D origin;
	Matrix4x4 trans;
	Matrix4x4 invtrans;
	Matrix4x4 modelToWorld;
	Matrix4x4 worldToModel;
	// Variables to store and check for textures
	Texture* texture;
	bool has_texture;
	// Variables to check if an object is a portal and the corresponding transformation to be applied to any
	// intersecting rays
	bool is_portal;
	Matrix4x4 portalTrans;
};

// Scene is simply implemented as a list of nodes. Doesnt support hierarchy(scene graph).
typedef std::vector<SceneNode*> Scene;


// Example primitive you can create, this is a unit square on 
// the xy-plane.
class UnitSquare : public SceneObject {
public:
	bool intersect(Ray3D& ray, const Matrix4x4& worldToModel, 
				const Matrix4x4& modelToWorld);
};

class UnitCircle : public SceneObject {
public:
    bool intersect(Ray3D& ray, const Matrix4x4& worldToModel,
                   const Matrix4x4& modelToWorld);
};

class UnitSphere : public SceneObject {
public:
	bool intersect(Ray3D& ray, const Matrix4x4& worldToModel, 
				const Matrix4x4& modelToWorld);
};

// Portal Structure -> Created by Logan Rooks
// Used to hold and initialize a connection between two scene nodes
struct Portal {

    SceneNode* portal1 = new SceneNode(new UnitCircle, &obsidian);
    SceneNode* portal2 = new SceneNode(new UnitCircle, &obsidian);

	Portal(const Vector3D &location1, const Vector3D &normal1, const Vector3D &location2, const Vector3D &normal2,
           double scale) {
		// The portal constructor takes 4 arguments, a desired normal and location for each of the portals and a
		// corresponding scaling factor to make them bigger or smaller
		portal1->is_portal = true;
		portal2->is_portal = true;
		// Using the desired normal and location for each, apply the correct sequence of transformations to obtain
		// the worldToModel and modelToWorld transformation matrices
		portal1->transformPortal(location1, normal1, scale);
		portal2->transformPortal(location2, normal2, scale);
//		std::cout << normal1 << normal2 << std::endl;
		portal1->portalTrans = portal1->invtrans*portal2->trans;
		portal2->portalTrans = portal2->invtrans*portal1->trans;
//		std::cout << portal1->portalTrans << std::endl;
//		std::cout << portal2->portalTrans << std::endl;
	}
};


#endif // __SCENE_OBJECT_H_INCLUDED__
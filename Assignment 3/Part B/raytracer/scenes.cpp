//
// Created by logan on 10/04/18.
//

#include "scenes.h"


extern double EPSILON;
Material grey(Color(0, 0, 0), Color(0.5, 0.5, 0.5),
              Color(0.3, 0.3, 0.3), 5, 0, 0);
Material black(Color(0, 0, 0), Color(0, 0, 0),
               Color(0.3, 0.3, 0.3), 5, 0, 0);
Material orange_slime(Color(0.3, 0.2, 0), Color(0.7, 0.45, 0),
                      Color(0.3, 0.2, 0.1), 5, 0.05, 0);
Material red(Color(0, 0, 0), Color(0.6, 0.3, 0.3),
             Color(0.3, 0.3, 0.3), 5, 0, 0);
Material blue(Color(0, 0, 0), Color(0.3, 0.3, 0.6),
              Color(0.3, 0.3, 0.3), 5, 0, 0);
Material green(Color(0, 0, 0), Color(0.3, 0.6, 0.3),
               Color(0.3, 0.3, 0.3), 5, 0, 0);
Material wood(Color(0,0,0), Color(0.392,0.117,0.0),
              Color(0.45,0.14,0.0),
              12.8, 0, 0);
Material copper(Color(0.19125 , 0.0735, 0.0225), Color(0.7038,0.27048,0.0828),
                Color(0.256777, 0.137622, 0.086014),
                12.8);
Material obsidian(Color(0.05375, 0.05, 0.06625), Color(0.18275, 0.17, 0.22525),
                  Color(0.332741, 0.328634, 0.346435),
                  38.4, 0, 0);

Material wormhole(Color(0.05375, 0.05, 0.06625), Color(0.18275, 0.17, 0.22525),
                  Color(0.332741, 0.328634, 0.346435),
                  38.4, 0.97, 0);

Material mirror(Color(0, 0, 0), Color(0.5,0.5,0.5),
                Color(0.5,0.5,0.5),
                19, 0.95, 0);





int portal_scene(LightList& light_list, Scene& scene) {
    // Two lights on either side of the complex
    PointLight* pLight2 = new PointLight(Point3D(37,15,20), Color(0.4, 0.4, 0.4));
    light_list.push_back(pLight2);
    PointLight* pLight3 = new PointLight(Point3D(22,18,30), Color(0.45, 0.45, 0.45));
    light_list.push_back(pLight3);

    // Orange goo
    SceneNode* slime1 = new SceneNode(new UnitCircle(), &orange_slime);
    scene.push_back(slime1);
    SceneNode* slime2 = new SceneNode(new UnitCircle(), &orange_slime);
    scene.push_back(slime2);
    SceneNode* slime3 = new SceneNode(new UnitCircle(), &orange_slime);
    scene.push_back(slime3);

    // Portals
    SceneNode* portal_orange = new SceneNode(new UnitSquare(), &grey);
    portal_orange->texture = new Texture(1, 1);
    portal_orange->has_texture = true;
    portal_orange->texture->loadBitmap("textures/portal_orange.bmp");
    scene.push_back(portal_orange);

    SceneNode* portal_blue = new SceneNode(new UnitSquare(), &grey);
    portal_blue->texture = new Texture(1, 1);
    portal_blue->has_texture = true;
    portal_blue->texture->loadBitmap("textures/portal_blue.bmp");
    scene.push_back(portal_blue);

    SceneNode* portal_orange_m = new SceneNode(new UnitCircle(), &mirror);
    scene.push_back(portal_orange_m);

    SceneNode* portal_blue_m = new SceneNode(new UnitCircle(), &mirror);
    scene.push_back(portal_blue_m);

    // Companion cube
    SceneNode* cube0 = new SceneNode(new UnitSquare(), &grey);
    cube0->texture = new Texture(1,1);
    cube0->has_texture = true;
    cube0->texture->loadBitmap("textures/c_cube_face.bmp");
    scene.push_back(cube0);

    SceneNode* cube1 = new SceneNode(new UnitSquare(), &grey);
    cube1->texture = new Texture(1,1);
    cube1->has_texture = true;
    cube1->texture->loadBitmap("textures/c_cube_face.bmp");
    scene.push_back(cube1);

    SceneNode* cube2 = new SceneNode(new UnitSquare(), &grey);
    cube2->texture = new Texture(1,1);
    cube2->has_texture = true;
    cube2->texture->loadBitmap("textures/c_cube_face.bmp");
    scene.push_back(cube2);

    SceneNode* cube3 = new SceneNode(new UnitSquare(), &grey);
    cube3->texture = new Texture(1,1);
    cube3->has_texture = true;
    cube3->texture->loadBitmap("textures/c_cube_face.bmp");
    scene.push_back(cube3);

    SceneNode* cube4 = new SceneNode(new UnitSquare(), &grey);
    cube4->texture = new Texture(1,1);
    cube4->has_texture = true;
    cube4->texture->loadBitmap("textures/c_cube_face.bmp");
    scene.push_back(cube4);

    // Extras
    SceneNode* piston = new SceneNode(new UnitSquare(), &grey);
    piston->texture = new Texture(1,1);
    piston->has_texture = true;
    piston->texture->loadBitmap("textures/piston_top.bmp");
    scene.push_back(piston);

    // Constructing the room
    // Front wall (pos x normal)
    SceneNode* front_top = new SceneNode(new UnitSquare(), &grey);
    front_top->texture = new Texture(1, 2);
    front_top->has_texture = true;
    front_top->texture->loadBitmap("textures/portal_wall2.bmp");
    scene.push_back(front_top);

    SceneNode* front_bottom = new SceneNode(new UnitSquare(), &grey);
    front_bottom->texture = new Texture(1, 2);
    front_bottom->has_texture = true;
    front_bottom->texture->loadBitmap("textures/portal_bg.bmp");
    scene.push_back(front_bottom);

    // Right side wall (pos z normal)
    SceneNode* right_front_top1 = new SceneNode(new UnitSquare(), &grey);
    right_front_top1->texture = new Texture(1,1);
    right_front_top1->has_texture = true;
    right_front_top1->texture->loadBitmap("textures/portal_wall2.bmp");
    scene.push_back(right_front_top1);

    SceneNode* right_front_top2 = new SceneNode(new UnitSquare(), &grey);
    right_front_top2->texture = new Texture(1,1);
    right_front_top2->has_texture = true;
    right_front_top2->texture->loadBitmap("textures/dirt2.bmp");
    scene.push_back(right_front_top2);

    SceneNode* right_front_bottom = new SceneNode(new UnitSquare(), &grey);
    right_front_bottom->texture = new Texture(1,2);
    right_front_bottom->has_texture = true;
    right_front_bottom->texture->loadBitmap("textures/portal_bg.bmp");
    scene.push_back(right_front_bottom);

    SceneNode* right_back_top1 = new SceneNode(new UnitSquare(), &grey);
    right_back_top1->texture = new Texture(1,1);
    right_back_top1->has_texture = true;
    right_back_top1->texture->loadBitmap("textures/dirt0.bmp");
    scene.push_back(right_back_top1);

    SceneNode* right_back_top2 = new SceneNode(new UnitSquare(), &grey);
    right_back_top2->texture = new Texture(1,1);
    right_back_top2->has_texture = true;
    right_back_top2->texture->loadBitmap("textures/rust0.bmp");
    scene.push_back(right_back_top2);

    SceneNode* right_back_bottom1 = new SceneNode(new UnitSquare(), &grey);
    right_back_bottom1->texture = new Texture(1,1);
    right_back_bottom1->has_texture = true;
    right_back_bottom1->texture->loadBitmap("textures/dirt1.bmp");
    scene.push_back(right_back_bottom1);

    SceneNode* right_back_bottom2 = new SceneNode(new UnitSquare(), &grey);
    right_back_bottom2->texture = new Texture(1,1);
    right_back_bottom2->has_texture = true;
    right_back_bottom2->texture->loadBitmap("textures/dark0.bmp");
    scene.push_back(right_back_bottom2);

    // Back wall (neg x normal)
    SceneNode* back_top1 = new SceneNode(new UnitSquare(), &grey);
    back_top1->texture = new Texture(1,1);
    back_top1->has_texture = true;
    back_top1->texture->loadBitmap("textures/rust1.bmp");
    scene.push_back(back_top1);

    SceneNode* back_top2 = new SceneNode(new UnitSquare(), &grey);
    back_top2->texture = new Texture(1,1);
    back_top2->has_texture = true;
    back_top2->texture->loadBitmap("textures/dark0.bmp");
    scene.push_back(back_top2);

    SceneNode* back_bottom1 = new SceneNode(new UnitSquare(), &grey);
    back_bottom1->texture = new Texture(1,1);
    back_bottom1->has_texture = true;
    back_bottom1->texture->loadBitmap("textures/dark0.bmp");
    scene.push_back(back_bottom1);

    SceneNode* back_bottom2 = new SceneNode(new UnitSquare(), &grey);
    back_bottom2->texture = new Texture(1,1);
    back_bottom2->has_texture = true;
    back_bottom2->texture->loadBitmap("textures/dark0.bmp");
    scene.push_back(back_bottom2);

    // Ceiling and floor
    SceneNode* ceiling = new SceneNode(new UnitSquare(), &grey);
    ceiling->texture = new Texture(4,2);
    ceiling->has_texture = true;
    ceiling->texture->loadBitmap("textures/portal_wall1.bmp");
    scene.push_back(ceiling);

    SceneNode* floor = new SceneNode(new UnitSquare(), &grey);
    floor->texture = new Texture(4,2);
    floor->has_texture = true;
    floor->texture->loadBitmap("textures/portal_wall1.bmp");
    scene.push_back(floor);

    // Transformations
    // Scaling factors
    double ratio = 0.65439672801;
    double factor1[3] = {7.5, 7.5, 7.5};
    double factor2[3] = {20, 10, 10};
    double factor4[3] = {10, 10, 10};
    double factor5[3] = {40, 20, 20};
    double factor6[3] = {10*ratio, 10, 1};
    double factor7[3] = {5,5,5};
    double factor8[3] = {4,4,4};
    double factor9[3] = {3,3,3};

    // Portals
    portal_orange->translate(Vector3D(EPSILON, 5, 14.65));
    portal_orange->rotate('y', 90);
    portal_orange->scale(Point3D(0, 0, 0), factor6);

    portal_blue->translate(Vector3D(15.55, 5, EPSILON));
    portal_blue->scale(Point3D(0, 0, 0), factor6);

    double factorP1[3] = {1.97,3.25,1};
    portal_orange_m->translate(Vector3D(2 * EPSILON, 5, 14.45));
    portal_orange_m->rotate('y', 90);
    portal_orange_m->scale(Point3D(0, 0, 0), factorP1);

    double factorP2[3] = {3.25,1.97,1};
    portal_blue_m->translate(Vector3D(15.55, 5, 2*EPSILON));
    portal_blue_m->rotate('z', 90);
    portal_blue_m->scale(Point3D(0, 0, 0), factorP2);

    // Slime
    slime1->translate(Vector3D(37,2*EPSILON,9));
    slime1->rotate('x', -90);
    slime1->scale(Point3D(0,0,0), factor7);

    slime2->translate(Vector3D(35.4,EPSILON,13));
    slime2->rotate('x', -90);
    slime2->scale(Point3D(0,0,0), factor9);

    slime3->translate(Vector3D(38,EPSILON,16.5));
    slime3->rotate('x', -90);

    // Companion Cube
    cube0->translate(Vector3D(22, 2, 15));
    cube0->scale(Point3D(0, 0, 0), factor8);

    cube1->translate(Vector3D(24, 2, 13));
    cube1->rotate('x', 90);
    cube1->rotate('y', 90);
    cube1->scale(Point3D(0, 0, 0), factor8);

    cube2->translate(Vector3D(20, 2, 13));
    cube2->rotate('x', 90);
    cube2->rotate('y', -90);
    cube2->rotate('z', 180);
    cube2->scale(Point3D(0, 0, 0), factor8);

    cube3->translate(Vector3D(22, 2, 11));
    cube3->rotate('y', -180);
    cube3->scale(Point3D(0, 0, 0), factor8);

    cube4->translate(Vector3D(22, 4, 13));
    cube4->rotate('x', -90);
    cube4->scale(Point3D(0, 0, 0), factor8);

    // Piston
    piston->translate(Vector3D(7.5,EPSILON,8));
    piston->rotate('x', -90);
    piston->scale(Point3D(0,0,0), factor1);

    // Walls
    front_top->translate(Vector3D(0, 15, 10));
    front_top->rotate('y', 90);
//    front_top->rotate('z', 90);
    front_top->scale(Point3D(0, 0, 0), factor2);

    front_bottom->translate(Vector3D(0, 5, 10));
    front_bottom->rotate('y', 90);
//    front_bottom->rotate('z', 90);
    front_bottom->scale(Point3D(0, 0, 0), factor2);

    back_bottom1->translate(Vector3D(40,5,5));
    back_bottom1->rotate('y', -90);
    back_bottom1->scale(Point3D(0,0,0), factor4);

    back_bottom2->translate(Vector3D(40,5,15));
    back_bottom2->rotate('y', -90);
    back_bottom2->scale(Point3D(0,0,0), factor4);

    back_top1->translate(Vector3D(40,15,5));
    back_top1->rotate('y', -90);
    back_top1->scale(Point3D(0,0,0), factor4);

    back_top2->translate(Vector3D(40,15,15));
    back_top2->rotate('y', -90);
    back_top2->scale(Point3D(0,0,0), factor4);

    right_front_bottom->translate(Vector3D(10, 5, 0));
    right_front_bottom->scale(Point3D(0, 0, 0), factor2);

    right_front_top1->translate(Vector3D(5, 15, 0));
    right_front_top1->scale(Point3D(0, 0, 0), factor4);

    right_front_top2->translate(Vector3D(15, 15, 0));
    right_front_top2->scale(Point3D(0, 0, 0), factor4);

    right_back_bottom1->translate(Vector3D(25, 5, 0));
    right_back_bottom1->scale(Point3D(0, 0, 0), factor4);

    right_back_bottom2->translate(Vector3D(35, 5, 0));
    right_back_bottom2->scale(Point3D(0, 0, 0), factor4);

    right_back_top1->translate(Vector3D(25, 15, 0));
    right_back_top1->scale(Point3D(0, 0, 0), factor4);

    right_back_top2->translate(Vector3D(35, 15, 0));
    right_back_top2->scale(Point3D(0, 0, 0), factor4);

    // Ceiling and Floor
    floor->translate(Vector3D(20,0,10));
    floor->rotate('x', -90);
    floor->scale(Point3D(0,0,0), factor5);

    ceiling->translate(Vector3D(20,20,10));
    ceiling->rotate('x', 90);
    ceiling->scale(Point3D(0,0,0), factor5);
    return 0;
}

int simple_scene(LightList& light_list, Scene& scene) {
    // Define materials for shading.


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
    leftFrontM->translate(Vector3D(0.01,10,15));
    leftFrontM->rotate('y', 90);
    leftFrontM->scale(Point3D(0,0,0), factorM2);

    rightFrontM->translate(Vector3D(0.01,10,5));
    rightFrontM->rotate('y', 90);
    rightFrontM->scale(Point3D(0,0,0), factorM2);

    topFrontM->translate(Vector3D(0.01, 15, 10));
    topFrontM->rotate('y', 90);
    topFrontM->rotate('z', 90);
    topFrontM->scale(Point3D(0,0,0), factorM2);

    bottomFrontM->translate(Vector3D(0.01, 5, 10));
    bottomFrontM->rotate('y', 90);
    bottomFrontM->rotate('z', 90);
    bottomFrontM->scale(Point3D(0,0,0), factorM2);

    return 0;
}

int simple_portal_scene(LightList& light_list, Scene& scene) {
    // Defines a point light source.
    double ratio = 0.65439672801;
    PointLight* pLight = new PointLight(Point3D(14,18,15), Color(0.9,0.9,0.9));
    light_list.push_back(pLight);

    Portal portals(Vector3D(14.98*ratio, 5, 30*ratio-2*EPSILON), Vector3D(0,0,-1), Vector3D(15.2*ratio, 5, 2*EPSILON),
                   Vector3D(0, 0,1), 2);
    scene.push_back(portals.portal1);
    scene.push_back(portals.portal2);

    SceneNode* portal_orange = new SceneNode(new UnitSquare(), &grey);
    portal_orange->texture = new Texture(1, 1);
    portal_orange->has_texture = true;
    portal_orange->texture->loadBitmap("textures/portal_orange.bmp");
    scene.push_back(portal_orange);

    SceneNode* portal_blue = new SceneNode(new UnitSquare(), &grey);
    portal_blue->texture = new Texture(1, 1);
    portal_blue->has_texture = true;
    portal_blue->texture->loadBitmap("textures/portal_blue.bmp");
    scene.push_back(portal_blue);

    // add unit planes to make into room
    SceneNode* back = new SceneNode(new UnitSquare(), &black);
    back->texture = new Texture(2, 3);
    back->has_texture = true;
    back->texture->loadBitmap("textures/portal_bgs.bmp");
    scene.push_back(back);
    SceneNode* front = new SceneNode(new UnitSquare(), &black);
    front->texture = new Texture(2, 3);
    front->has_texture = true;
    front->texture->loadBitmap("textures/portal_bgs.bmp");
    scene.push_back(front);
    SceneNode* left = new SceneNode(new UnitSquare(), &black);
    left->texture = new Texture(2, 3);
    left->has_texture = true;
    left->texture->loadBitmap("textures/portal_bgs.bmp");
    scene.push_back(left);
    SceneNode* right = new SceneNode(new UnitSquare(), &black);
    right->texture = new Texture(2, 3);
    right->has_texture = true;
    right->texture->loadBitmap("textures/portal_bgs.bmp");
    scene.push_back(right);
    SceneNode* top = new SceneNode(new UnitSquare(), &black);
    top->texture = new Texture(2, 2);
    top->has_texture = true;
    top->texture->loadBitmap("textures/portal_wall1.bmp");
    scene.push_back(top);
    SceneNode* bottom = new SceneNode(new UnitSquare(), &black);
    bottom->texture = new Texture(2, 2);
    bottom->has_texture = true;
    bottom->texture->loadBitmap("textures/portal_wall1.bmp");
    scene.push_back(bottom);

    SceneNode* sphere1 = new SceneNode(new UnitSphere(), &copper);
    scene.push_back(sphere1);
    SceneNode* sphere3 = new SceneNode(new UnitSphere(), &obsidian);
    scene.push_back(sphere3);
//
//    // Apply some transformations to the spheres
    double factorS2[3] = { 1.5, 1.5, 1.5 };
    sphere1->translate(Vector3D(12, 5, 8));


    sphere3->translate(Vector3D(10, 9, 8));
    sphere3->scale(Point3D(0, 0, 0), factorS2);
    // Apply transformations to make the room


    double factor1[3] = {30*ratio, 30*ratio, 20};
    double factor2[3] = {30*ratio, 20, 20 };

    back->translate(Vector3D(0, 10, 15*ratio));
    back->rotate('y', 90);
    back->scale(Point3D(0, 0, 0), factor2);

    front ->translate(Vector3D(30*ratio,10,10));
    front->rotate('y', -90);
    front->scale(Point3D(0,0,0), factor2);

    left->translate(Vector3D(15*ratio, 10, 30*ratio));
    left->scale(Point3D(0, 0, 0), factor2);
    left->rotate('y', 180);

    right->translate(Vector3D(15*ratio, 10, 0));
    right->scale(Point3D(0, 0, 0), factor2);

    bottom->translate(Vector3D(15*ratio,0,15*ratio));
    bottom->rotate('x', -90);
    bottom->scale(Point3D(0,0,0), factor1);

    top->translate(Vector3D(15*ratio,20,15*ratio));
    top->rotate('x', 90);
    top->scale(Point3D(0,0,0), factor1);

    // Portals

    double factorP1[3] = {10*ratio, 10, 1};
    double factorP2[3] = {10, 10*ratio, 1};
    portal_orange->translate(Vector3D(15*ratio, 5, EPSILON));
    portal_orange->scale(Point3D(0, 0, 0), factorP1);


    portal_blue->translate(Vector3D(15*ratio, 5, 30*ratio - EPSILON));
    portal_blue->scale(Point3D(0, 0, 0), factorP1);
    portal_blue->rotate('y', -180);
//    std::cout << scene[3]->invtrans<<std::endl;

    return 0;
}
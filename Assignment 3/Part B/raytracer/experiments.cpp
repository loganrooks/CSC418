//
// Created by logan on 10/04/18.
//

#include "experiments.h"
// Define global variables
extern double EPSILON;
double ratio = 0.65439672801;
Material glass(Color(0, 0, 0), Color(0.1,0.2,0.6),
               Color(1,1,1),
               40, 0, 1.5);

Material water(Color(0, 0, 0), Color(0.1,0.2,0.6),
               Color(1,1,1),
               40, 0, 1.3);
extern Material wormhole;
extern Material grey;
extern Material copper;
extern Material mirror;
extern Material black;

// Refraction -> Tasked to Logan Rooks
int refraction(int width, int height) {
    LightList light_list;
    Scene scene;

    // Start with the basic scene to clearly showcase the effects
    simple_scene(light_list, scene);

    // Make the spheres made of refractive materials
    scene[0]->mat = &water;
    scene[1]->mat = &glass;

    Raytracer refract(false, 10, false, false);

    // Render the scene
    Camera camera1(Point3D(18, 10, 15), Vector3D(-2, -1, -1), Vector3D(0, 1, 0), 60.0);
    //Render it from a different point of view.
    Camera camera2(Point3D(18, 10, 2), Vector3D(-1, -0.5, 1), Vector3D(0, 1, 0), 60.0);
    //Another point of view
    Camera camera3(Point3D(18, 8, 8), Vector3D(-1, 0.1, 0.1 ), Vector3D(0, 1, 0), 60.0);

    Image image(width, height);

    refract.render(camera1, scene, light_list, image); //render 3D scene to image
    image.flushPixelBuffer("refraction1.bmp"); //save rendered image to file
    std::cout << "Done: refraction1" << std::endl;

    refract.render(camera2, scene, light_list, image);
    image.flushPixelBuffer("refraction2.bmp");
    std::cout << "Done: refraction2" << std::endl;

    refract.render(camera3, scene, light_list, image);
    image.flushPixelBuffer("refraction3.bmp");
    std::cout << "Done: refraction3" << std::endl;

    // Free memory for next scene
    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];

    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    scene.clear();
    light_list.clear();

    // Portal scene, because I had too
    portal_scene(light_list, scene);

    // Add refractive objects into the scene
    SceneNode* sphere1 = new SceneNode(new UnitSphere(), &glass);
    scene.push_back(sphere1);

    SceneNode* sphere2 = new SceneNode(new UnitSphere(), &glass);
    scene.push_back(sphere2);

    SceneNode* sphere3 = new SceneNode(new UnitSphere(), &glass);
    scene.push_back(sphere3);

    SceneNode* sphere4 = new SceneNode(new UnitSphere(), &glass);
    scene.push_back(sphere4);

    SceneNode* plane1 = new SceneNode(new UnitSquare(), &water);
    scene.push_back(plane1);

    double factorS1[3] = {2.5, 2.5, 2.5};
    double factorS2[3] = {2, 2, 2};
    double factorS3[3] = {1.5, 1.5, 1.5};
    double factor1[3] = {3, 3, 3};
    sphere1->translate(Vector3D(34,2.5,7));
    sphere1->scale(Point3D(0,0,0), factorS1);

    sphere2->translate(Vector3D(34,2.1,15));
    sphere2->scale(Point3D(0,0,0), factorS2);

    sphere3->translate(Vector3D(16,4.5,6));
    sphere3->scale(Point3D(0,0,0), factorS2);

    sphere4->translate(Vector3D(25,7.5,6));
    sphere4->scale(Point3D(0,0,0), factorS2);

    plane1->translate(Vector3D(31, 5, 8));
    plane1->rotate('y', -25);
    plane1->scale(Point3D(0,0,0), factor1);

    // Pointing at the corner with the orange goo, looking at how the spheres refract the textures and the orange goo.
    Camera camera4(Point3D(25, 5, 17), Vector3D(0.8, -0.1, -0.7), Vector3D(0, 1, 0), 60.0);

    // Pointing from that corner to the rest of the scene
    Camera camera5(Point3D(36, 5, 17), Vector3D(-0.3, -0.1, -0.7), Vector3D(0, 1, 0), 60.0);

    refract.render(camera4, scene, light_list, image);
    image.flushPixelBuffer("refraction4.bmp");
    std::cout << "Done: refraction4" << std::endl;

    refract.render(camera5, scene, light_list, image);
    image.flushPixelBuffer("refraction5.bmp");
    std::cout << "Done: refraction5" << std::endl;
    simple_scene(light_list, scene);

    // Free memory
    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;


}

// Recursive Raytracing -> Tasked to Christopher Sheedy
int recursive_ray_tracing(int width, int height) {
    LightList light_list;
    Scene scene;

    simple_scene(light_list, scene);

    Raytracer recursive(false, 8, false, false);
    // Render the scene
    Camera camera1(Point3D(18, 10, 15), Vector3D(-2, -1, -1), Vector3D(0, 1, 0), 60.0);
    //Render it from a different point of view.
    Camera camera2(Point3D(18, 10, 2), Vector3D(-1, -0.5, 1), Vector3D(0, 1, 0), 60.0);
    //Another point of view
    Camera camera3(Point3D(18, 8, 8), Vector3D(-1, 0.1, 0.1 ), Vector3D(0, 1, 0), 60.0);

    Image image(width, height);

    recursive.render(camera1, scene, light_list, image); //render 3D scene to image
    image.flushPixelBuffer("recursiveRT1.bmp"); //save rendered image to file
    std::cout << "Done: recursiveRT1" << std::endl;

    recursive.render(camera2, scene, light_list, image);
    image.flushPixelBuffer("recursiveRT2.bmp");
    std::cout << "Done: recursiveRT2" << std::endl;

    recursive.render(camera3, scene, light_list, image);
    image.flushPixelBuffer("recursiveRT3.bmp");
    std::cout << "Done: recursiveRT3" << std::endl;

    // Free memory
    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;

}

// Hard Shadows -> Tasked to Logan Rooks
int hard_shadows(int width, int height) {
    LightList light_list;
    Scene scene;
    simple_scene(light_list, scene);

    Raytracer shadows(true, 0, false, false);

    Camera camera1(Point3D(18, 10, 15), Vector3D(-2, -1, -1), Vector3D(0, 1, 0), 60.0);
    Image image1(width, height);
    shadows.render(camera1, scene, light_list, image1);
    image1.flushPixelBuffer("hardShadows1.bmp");
    std::cout << "Done: hardShadows1" << std::endl;

    Camera camera2(Point3D(18, 10, 2), Vector3D(-1, -0.5, 1), Vector3D(0, 1, 0), 60.0);
    Image image2(width, height);
    shadows.render(camera2, scene, light_list, image2);
    image2.flushPixelBuffer("hardShadows2.bmp");
    std::cout << "Done: hardShadows2" << std::endl;

    Camera camera3(Point3D(18, 8, 8), Vector3D(-1, 0.1, 0.1 ), Vector3D(0, 1, 0), 60.0);
    Image image3(width, height);
    shadows.render(camera3, scene, light_list, image3);
    image3.flushPixelBuffer("hardShadows3.bmp");
    std::cout << "Done: hardShadows3" << std::endl;
    // Free memory
    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;
}

// Anti-Aliasing -> Tasked to Christopher Sheedy
int anti_aliasing(int width, int height) {
    LightList light_list;
    Scene scene;
    simple_scene(light_list, scene);

    Raytracer anti(false, 0, true, false);

    Camera camera1(Point3D(18, 10, 15), Vector3D(-2, -1, -1), Vector3D(0, 1, 0), 60.0);
    Image image1(width, height);
    anti.render(camera1, scene, light_list, image1);
    image1.flushPixelBuffer("antiAliasing1.bmp");
    std::cout << "Done: antiAliasing1" << std::endl;

    Camera camera2(Point3D(18, 10, 2), Vector3D(-1, -0.5, 1), Vector3D(0, 1, 0), 60.0);
    Image image2(width, height);
    anti.render(camera2, scene, light_list, image2);
    image2.flushPixelBuffer("antiAliasing2.bmp");
    std::cout << "Done: antiAliasing2" << std::endl;

    Camera camera3(Point3D(18, 8, 8), Vector3D(-1, 0.1, 0.1 ), Vector3D(0, 1, 0), 60.0);
    Image image3(width, height);
    anti.render(camera3, scene, light_list, image3);
    image3.flushPixelBuffer("antiAliasing3.bmp");
    std::cout << "Done: antiAliasing3" << std::endl;

    // Free memory
    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;
}
// Soft Shadows -> Tasked to Christopher Sheedy
int soft_shadows(int width, int height, int numLights, int radius, double intensity) {
    LightList light_list;
    Scene scene;
    simple_scene(light_list, scene);

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }

    Raytracer shadows(true, 0, false, false);

    //Generate randomnly sampled PointLights in a circle around a specified point
    double x = 14;
    double y = 18;
    double z = 15;
    double pointIntensity = intensity / numLights;
    for (int  i = 0; i < numLights; ++i) {
        double r = (double(rand())/double(RAND_MAX)) * radius;
        double theta = (double(rand())/double(RAND_MAX)) * 2.0 * M_PI;

        double xi = x + r * cos(theta);
        double yi = y + r * sin(theta);
        double zi = z;

        light_list.push_back(new PointLight(Point3D(xi,yi,zi), Color(pointIntensity,pointIntensity,pointIntensity)));
    }

    Camera camera1(Point3D(18, 10, 15), Vector3D(-2, -1, -1), Vector3D(0, 1, 0), 60.0);
    Image image1(width, height);
    shadows.render(camera1, scene, light_list, image1);
    image1.flushPixelBuffer("softShadows1.bmp");
    std::cout << "Done: softShadows1" << std::endl;

    Camera camera2(Point3D(18, 10, 2), Vector3D(-1, -0.5, 1), Vector3D(0, 1, 0), 60.0);
    Image image2(width, height);
    shadows.render(camera2, scene, light_list, image2);
    image2.flushPixelBuffer("softShadows2.bmp");
    std::cout << "Done: softShadows2" << std::endl;

    Camera camera3(Point3D(18, 8, 8), Vector3D(-1, 0.1, 0.1 ), Vector3D(0, 1, 0), 60.0);
    Image image3(width, height);
    shadows.render(camera3, scene, light_list, image3);
    image3.flushPixelBuffer("softShadows3.bmp");
    std::cout << "Done: softShadows3" << std::endl;

    // Free memory
    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;
}

// Environment Mapping -> Tasked to Logan Rooks
// Note: the way this is set up now, you will only get one set of images when run. Specifically you won't get the
// "wormhole" images. That is done by simply setting envmapping.wormhole_effect = true;. This just makes sure you can
// only see the environment mapping through the reflection of the sphere for an interesting effect. I personally
// think having the environment in the background is nicer.
int environment_mapping(int width, int height) {
    LightList light_list;
    Scene scene;

    portal_scene(light_list, scene);

    SceneNode* sphere = new SceneNode(new UnitSphere(), &wormhole);
    scene.push_back(sphere);

    double factorS1[3] = { 4.0, 4.0, 4.0 };
    sphere->translate(Vector3D(15, 12, 26));
    sphere->scale(Point3D(0,0,0), factorS1);

    // Looking into orange portal
    Camera camera1(Point3D(7, 3, 10), Vector3D(-1, 0.2, 0.05), Vector3D(0, 1, 0), 60.0);

    // Looking at blue portal
    Camera camera2(Point3D(15, 2.6, 9.5), Vector3D(0, 0.14, -1), Vector3D(0, 1, 0), 60.0);

    // Pointing at mirror ball in space
    Camera camera3(Point3D(21, 12, 19), Vector3D(-0.6, 0, 1), Vector3D(0, 1, 0), 60.0);

    Image image(width, height);

    Raytracer envmapping(false, 3, false, true);
    envmapping.render(camera1, scene, light_list, image);
    image.flushPixelBuffer("envmap1.bmp");
    std::cout << "Done: envmap1" << std::endl;

    envmapping.render(camera2, scene, light_list, image);
    image.flushPixelBuffer("envmap2.bmp");
    std::cout << "Done: envmap2" << std::endl;

    envmapping.render(camera3, scene, light_list, image);
    image.flushPixelBuffer("envmap3.bmp");
    std::cout << "Done: envmap3" << std::endl;

    // Free memory
    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;
}

// Texture Mapping Showcase -> Tasked to Logan Rooks
// Note: the portals in this scene are not actual portals and just mirrors, the effect is generated by the back wall
// missing and the planet being behind the camera. The actual portal effect comes later.
int texture_mapping(int width, int height) {
    LightList light_list;
    Scene scene;

    portal_scene(light_list, scene);

    // Mapping on sphere
    SceneNode* green_planet = new SceneNode(new UnitSphere(), &obsidian);
    green_planet->texture = new Texture(1, 1);
    green_planet->has_texture = true;
    green_planet->texture->loadBitmap("textures/green_gas.bmp");
    scene.push_back(green_planet);

    double factorS1[3] = { 4.0, 4.0, 4.0 };
    green_planet->translate(Vector3D(0, 8, 38));
    green_planet->scale(Point3D(0, 0, 0), factorS1);

    // Looking at the corner with the two portals and the companion cube in the center
    Camera camera1(Point3D(26, 5.5, 22), Vector3D(-1, -0.13, -1.8), Vector3D(0, 1, 0), 60.0);
    // Looking at the green gas planet
    Camera camera2(Point3D(3,5,28), Vector3D(-0.3, 0.3, 1.1), Vector3D(0,1,0), 60.0);

    Image image(width, height);

    Raytracer txtmapping(true, 4, false, false);
    txtmapping.render(camera1, scene, light_list, image);
    image.flushPixelBuffer("textureMapping1.bmp");
    std::cout << "Done: textureMapping1" << std::endl;

    txtmapping.render(camera2, scene, light_list, image);
    image.flushPixelBuffer("textureMapping2.bmp");
    std::cout << "Done: textureMapping2" << std::endl;

    // Free memory for next scene
    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];

    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    scene.clear();
    light_list.clear();

    // New scene, two texture mapped spheres, the earth at night and the moon
    // Two lights one is dim and close to the earth to mimic the reflection of the moon's light onto the surface, the
    // other is farther away on the opposite side of the earth and is bright to mimic the sun.
    PointLight* pLight1 = new PointLight(Point3D(20,20,20), Color(0.3,0.3,0.3));
    PointLight* pLight2 = new PointLight(Point3D(0,-40,-40), Color(0.6,0.6,0.6));
    light_list.push_back(pLight1);
    light_list.push_back(pLight2);

    // Texture mapped spheres, textures obtained from: https://www.solarsystemscope.com/textures/
    SceneNode* earth_night = new SceneNode(new UnitSphere(), &black);
    earth_night->texture = new Texture(1, 1);
    earth_night->has_texture = true;
    earth_night->texture->loadBitmap("textures/8k_earth_nightmap_square.bmp");
    scene.push_back(earth_night);

    SceneNode* moon = new SceneNode(new UnitSphere(), &black);
    moon->texture = new Texture(1, 1);
    moon->has_texture = true;
    moon->texture->loadBitmap("textures/8k_moon_square.bmp");
    scene.push_back(moon);

    double factorS2[3] = {10, 10, 10};
    // In this scene, I'd like to make the moon large compared to the earth for visual effect
    double factorS3[3] = {30,30,30};

    // Orienting the moon so we get the "nice side" in the view of the camera and in the light
    moon->translate(Point3D(60,60,60));
    moon->rotate('y', 140);
    moon->rotate('x', 0);
    moon->rotate('z', -40);
    moon->scale(Point3D(0,0,0), factorS3);

    earth_night->scale(Point3D(0, 0, 0), factorS2);

    // Looking directly down at earth
    Camera camera3(Point3D(0,20,20), Vector3D(0,-1,-1), Vector3D(0,1,0), 60.0);
    // Looking up at the moon from an angle beside the earth, can see both objects
    Camera camera4(Point3D(-13,6,9), Vector3D(1.5,0.5,0.5), Vector3D(0,1,0), 60.0);
    // Turn off shadows because they are unnecessary for the purpose of this scene
    txtmapping.shadows = false;
    txtmapping.render(camera3, scene, light_list, image);
    image.flushPixelBuffer("textureMapping3.bmp");
    std::cout << "Done: textureMapping3" << std::endl;

    txtmapping.render(camera4, scene, light_list, image);
    image.flushPixelBuffer("textureMapping4.bmp");
    std::cout << "Done: textureMapping4" << std::endl;

    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;
}

// Bonus: Portal Test -> Created by Logan Rooks
int portal_test(int width, int height) {
    LightList light_list;
    Scene scene;
    simple_portal_scene(light_list, scene);

    // Setting the max depth very high for an infinite tunnel effect with the portals
    Raytracer portal(false, 40, false, false);

    // Looking straight into the orange portal, an infinite tunnel
    Camera camera1(Point3D(15*ratio, 5, 10), Vector3D(0, 0, -1), Vector3D(0, 1, 0), 60.0);
    Image image1(width, height);
    portal.render(camera1, scene, light_list, image1);
    image1.flushPixelBuffer("portal1.bmp");
    std::cout << "Done: portal1" << std::endl;

    // Looking straight into the blue portal, an infinite tunnel
    Camera camera2(Point3D(15*ratio, 5, 10), Vector3D(0, 0, 1), Vector3D(0, 1, 0), 60.0);
    Image image2(width, height);
    portal.render(camera2, scene, light_list, image2);
    image2.flushPixelBuffer("portal2.bmp");
    std::cout << "Done: portal2" << std::endl;

    // Looking at orange portal from slightly above and at angle, can see curving effect
    Camera camera3(Point3D(12, 8, 16), Vector3D(-0.1, -0.1, -0.45 ), Vector3D(0, 1, 0), 60.0);
    Image image3(width, height);
    portal.render(camera3, scene, light_list, image3);
    image3.flushPixelBuffer("portal3.bmp");
    std::cout << "Done: portal3" << std::endl;

    // Free memory
    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;
}

// Bonus: Final Test -> Created by Logan Rooks
// Purpose of this is combine many of the features shown above into a few interesting images
int final(int width, int height) {
    LightList light_list;
    Scene scene;
    portal_scene(light_list, scene);
    // Want to add our own light sources so remove
    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    light_list.clear();
    PointLight* pLight1 = new PointLight(Point3D(10,30,40), Color(0.4,0.4,0.4));
    light_list.push_back(pLight1);
    PointLight* pLight2 = new PointLight(Point3D(30,30,40), Color(0.4,0.4,0.4));
    light_list.push_back(pLight2);

    // Adjusting existing parts of the scene
    scene[5]->translate(Vector3D(0,0,-1));
    scene[6]->translate(Vector3D(0,0,-1));
    scene[3]->translate(Vector3D(0,1,0));
    scene[26]->rotate('x', 180);

    // Create two sets of portals
    // First set is between the blue one on the ground in-front of the cube and the orange one that was previously
    // also on the ground level on the back wall but was translated up
    Portal portals(Vector3D(3*EPSILON, 20/ratio, 14.45), Vector3D(-1,0,0), Vector3D(15.55, 5, 3*EPSILON),
                   Vector3D(0,0,-1), 2);

    // Second set is between an orange one below the texture mapped writing on the sandstone wall and a position
    // outside the room, showing the environment mapping
    Portal portals_out(Vector3D(20,5, 20 - 2*EPSILON), Vector3D(0,0,-1), Vector3D(60,60,60), Vector3D(0,0,-1), 2);

    scene.push_back(portals_out.portal1);
    scene.push_back(portals_out.portal2);
    scene.push_back(portals.portal1);
    scene.push_back(portals.portal2);

    // Add the new components required for this scene, the sandstone wall and the orange portal texture for inside
    // the room
    SceneNode* left_smooth = new SceneNode(new UnitSquare, &grey);
    left_smooth->texture = new Texture(2,3);
    left_smooth->has_texture = true;
    left_smooth->texture->loadBitmap("textures/sandstone_smooth.bmp");
    scene.push_back(left_smooth);

    SceneNode* left_dark= new SceneNode(new UnitSquare, &grey);
    left_dark->texture = new Texture(2,1);
    left_dark->has_texture = true;
    left_dark->texture->loadBitmap("textures/dark0.bmp");
    scene.push_back(left_dark);

    SceneNode* new_portal = new SceneNode(new UnitSquare, &grey);
    new_portal->texture = new Texture(1,1);
    new_portal->has_texture = true;
    new_portal->texture->loadBitmap("textures/portal_orange.bmp");
    scene.push_back(new_portal);

    SceneNode* carving = new SceneNode(new UnitSquare, &grey);
    carving->texture = new Texture(1,1);
    carving->has_texture = true;
    carving->texture->loadBitmap("textures/sandstone_carved.bmp");
    scene.push_back(carving);

    // Two spheres to showcase refraction and reflection in this scene
    SceneNode* sphere2 = new SceneNode(new UnitSphere(), &mirror);
    scene.push_back(sphere2);

    SceneNode* sphere3 = new SceneNode(new UnitSphere(), &water);
    scene.push_back(sphere3);


    double factor1[3] = {30,20,20};
    double factor2[3] = {10,20,20};
    double factor3[3] = {10*ratio, 10, 1};
    double factor4[3] = {10,10,10};
    left_smooth->translate(Vector3D(25,10,20));
//    left_smooth->rotate('y', -180);
    left_smooth->scale(Point3D(0,0,0), factor1);

    left_dark->translate(Vector3D(5,10,20));
//    left_dark->rotate('y', -180);
    left_dark->scale(Point3D(0,0,0), factor2);

    new_portal->translate(Vector3D(20, 5, 20-EPSILON));
    new_portal->scale(Point3D(0,0,0), factor3);

    carving->translate(Vector3D(20, 15, 20-EPSILON));
    carving->scale(Point3D(0,0,0), factor4);

    double factorS1[3] = { 1.0, 1.0, 1.0 };
    double factorS2[3] = { 1.5, 1.5, 1.5 };

    sphere2->translate(Vector3D(7.5, 14, 12));
    sphere2->scale(Point3D(0,0,0), factorS2);

    sphere3->translate(Vector3D(33, 3, 17));
    sphere3->scale(Point3D(0, 0, 0), factorS2);
    // Pointing into the ground floor blue portal, which transports the rays above the orange portal looking outside,
    // can also see the effect of refraction by the "water" ball in the background.
    Camera camera1(Point3D(14, 6.5, 6), Vector3D(0.2, -0.16, -1.3), Vector3D(0, 1, 0), 60.0);

    // Pointing at an angle into the same blue portal but this time because of the incident viewing angle, the rays
    // are transported directed at the same blue portal, finally being transported once more and hitting the text on
    // the wall. The mirror ball is in this view to showcase reflection and give a sneak peak into the rest of the
    // environment.
    Camera camera2(Point3D(22, 7.5, 4.5), Vector3D(-1.1, -0.4, -1.5), Vector3D(0, 1, 0), 60.0);

    Image image(width, height);

    Raytracer finaltracer(false, 5, true, true);
    finaltracer.render(camera1, scene, light_list, image);
    image.flushPixelBuffer("final1.bmp");
    std::cout << "Done: final1" << std::endl;

    finaltracer.render(camera2, scene, light_list, image);
    image.flushPixelBuffer("final2.bmp");
    std::cout << "Done: final2" << std::endl;

    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;

}
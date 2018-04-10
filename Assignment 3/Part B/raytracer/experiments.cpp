//
// Created by logan on 10/04/18.
//

#include "experiments.h"

int refraction(int width, int height) {
    LightList light_list;
    Scene scene;

    // Start with the basic scene
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

    Camera camera4(Point3D(25, 5, 17), Vector3D(0.8, -0.1, -0.7), Vector3D(0, 1, 0), 60.0);

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

//    Camera camera1(Point3D(18, 10, 15), Vector3D(-2, -1, -1), Vector3D(0, 1, 0), 60.0);
//    Image image1(width, height);
//    shadows.render(camera1, scene, light_list, image1);
//    image1.flushPixelBuffer("softShadows1.bmp");
//    std::cout << "Done: softShadows1" << std::endl;
//
//    Camera camera2(Point3D(18, 10, 2), Vector3D(-1, -0.5, 1), Vector3D(0, 1, 0), 60.0);
//    Image image2(width, height);
//    shadows.render(camera2, scene, light_list, image2);
//    image2.flushPixelBuffer("softShadows2.bmp");
//    std::cout << "Done: softShadows2" << std::endl;

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

int texture_mapping(int width, int height) {
    // NEED MORE IMAGES FOR TEXTURE MAPPING (SHOW CUBE, PLANE, SPHERE)
    LightList light_list;
    Scene scene;

    portal_scene(light_list, scene);

    SceneNode* green_planet = new SceneNode(new UnitSphere(), &obsidian);
    green_planet->texture = new Texture(1, 1);
    green_planet->has_texture = true;
    green_planet->texture->loadBitmap("textures/green_gas.bmp");
    scene.push_back(green_planet);

    double factorS1[3] = { 4.0, 4.0, 4.0 };
    green_planet->translate(Vector3D(0, 8, 38));
    green_planet->scale(Point3D(0, 0, 0), factorS1);

    Camera camera1(Point3D(26, 5.5, 22), Vector3D(-1, -0.13, -1.8), Vector3D(0, 1, 0), 60.0);

    Image image(width, height);

    Raytracer txtmapping(true, 4, false, false);
    txtmapping.render(camera1, scene, light_list, image);
    image.flushPixelBuffer("textureMapping1.bmp");
    std::cout << "Done: textureMapping1" << std::endl;

    for (size_t i = 0; i < scene.size(); ++i) {
        delete scene[i];
    }

    for (size_t i = 0; i < light_list.size(); ++i) {
        delete light_list[i];
    }
    return 0;
}

int portal_test(int width, int height) {
    LightList light_list;
    Scene scene;
    simple_scene(light_list, scene);

    Raytracer portal(false, 10, true, false);
}
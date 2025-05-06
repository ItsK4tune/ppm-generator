#include "rtweekend.h"

#include "camera.h"
#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

#include <iostream>
using namespace std;

int main()
{
    hittable_list world;

    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
    // world.add(make_shared<sphere>(point3(10,-100.5,-2), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1920;
    cam.samples_per_pixel = 10;
    cam.max_depth = 50;
    cam.image_file = "image/diffuse-sphere-with-ignorance.ppm";

    cam.render(world);

    return 0;
}
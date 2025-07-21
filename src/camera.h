#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"
#include <math.h>

typedef struct{
    Vec3 postion; 
    float yaw; // left, right
    float pitch; // up, down
}Camera; 

Vec3 TransformCamera(Vec3 vertex, Camera cam);











#endif
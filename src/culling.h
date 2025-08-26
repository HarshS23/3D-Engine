#ifndef CULLING_H
#define CULLING_H


#include "vector.h"

//returns 1 if visibile else 0 and does not render the face. 
int FaceVisible(Vec3 v0, Vec3 v1, Vec3 v2);
static Vec3 ComputeFaceNormal(Vec3 v0, Vec3 v1, Vec3 v2);


#endif 
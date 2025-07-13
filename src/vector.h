#ifndef VECTOR_H
#define VECTOR_H 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{

    float x, y, z; 

}Vec3;

typedef struct{

    float u, v;

}Vec2;



// functions needed for vector computations 

Vec3 addVec3(Vec3 a , Vec3 b); // addition of vectors 
Vec3 subVec3(Vec3 a , Vec3 b); // subtraction of vectors 
Vec3 scalVec3(Vec3 a , float s ); // scale vector 
float dotVec3(Vec3 a, Vec3 b); // dot product
Vec3 crossVec3(Vec3 a, Vec3 b); // cross product 
float lengthVec3(Vec3 a); // vector magnitude (lenght or size of vector)
Vec3 normalizeVec3(Vec3 a); // normalize vector (have vector point in the same direction but change value to 1 ) 








#endif
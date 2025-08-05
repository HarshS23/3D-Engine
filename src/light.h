#ifndef LIGHT_H 
#define LIGHT_H 



#include "vector.h"

typedef struct{

    Vec3 direction; // light direction 
    float intensity; // light strenght 

}Light;

Vec3 ComputeFaceNormal(Vec3 v0, Vec3 v1, Vec3 v2);
float ComputeLightIntensity(Vec3 normal, Light light);





#endif 
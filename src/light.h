#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"

typedef struct{
    Vec3 direction; 
    float intensity; // capped between 0.0 and 1.0
}Light;


float ComputeLighting(Vec3 normal, Light light);




#endif 
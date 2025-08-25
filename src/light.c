#include "light.h"
#include <math.h>


float ComputeLighting(Vec3 normal, Light light){
    normal = normalizeVec3(normal);
    Vec3 light_direction = normalizeVec3(light.direction);
    
    float dot = dotVec3(normal, light_direction); 
    float intensity = fmaxf(0.0f, dot * light.intensity);

    return intensity;
}
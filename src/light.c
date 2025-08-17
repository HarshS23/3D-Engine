#include "light.h"

Vec3 ComputeFaceNormal(Vec3 v0, Vec3 v1, Vec3 v2){
    Vec3 edge1 = subVec3(v1,v0);
    Vec3 edge2 = subVec3(v2,v0);
    Vec3 normal = crossVec3(edge1, edge2);
    return normalizeVec3(normal); 
}


float ComputeLightIntensity(Vec3 normal, Light light){
    float dot = dotVec3(normalizeVec3(normal), normalizeVec3(light.direction));
    return fmaxf(0.0f, dot * light.intensity);
}

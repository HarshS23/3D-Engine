#include "culling.h"
#include "vector.h"

int FaceVisible(Vec3 v0, Vec3 v1, Vec3 v2){
    Vec3 edge1 = subVec3(v1, v0);
    Vec3 edge2 = subVec3(v2, v0);
    
    Vec3 normal = normalizeVec3(crossVec3(edge2, edge1));


    Vec3 view_direc = {0.0f,0.0f,1.0f}; 

    float dot = dotVec3(normal, view_direc);

    return dot > -0.0f;

}

Vec3 ComputeFaceNormal(Vec3 v0, Vec3 v1, Vec3 v2) {
    Vec3 edge1 = subVec3(v1, v0);
    Vec3 edge2 = subVec3(v2, v0);
    Vec3 normal = crossVec3(edge2, edge1);
    return normalizeVec3(normal);

}


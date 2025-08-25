#include "culling.h"
#include "vector.h"

int FaceVisible(Vec3 v0, Vec3 v1, Vec3 v2){
    Vec3 edge1 = subVec3(v1, v0);
    Vec3 edge2 = subVec3(v2, v0);
    Vec3 normal = normalizeVec3(crossVec3(edge1, edge2));
    
    Vec3 view_direc = {0,0,1}; 
    return dotVec3(normal , view_direc) > 0.0f ;

}
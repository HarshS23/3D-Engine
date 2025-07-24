#include "camera.h"

Vec3 RotateYawPitch(Vec3 v, float yaw, float pitch){

    // apply rotation around y axis 
    float CosYaw = cosf(yaw);
    float SinYaw = sinf(yaw); 

    float x1 = v.x * CosYaw - v.z * SinYaw;
    float z1 = v.x * SinYaw + v.z * CosYaw; 
    float y1 = v.y;

    // apply pitching rotation around x axis 
    float CosPitch = cosf(pitch);
    float SinPitch = sinf(pitch);

    float y2 = y1 * CosPitch - z1 * SinPitch; 
    float z2 = y1 * SinPitch + z1 * CosPitch; 
    float x2 = x1; 

    Vec3 rotated; 
    rotated.x = x2; 
    rotated.y = y2; 
    rotated.z = z2; 

    return rotated;

}

Vec3 TransformCamera(Vec3 vertex, Camera cam){
    Vec3 translate;
    translate.x = vertex.x - cam.postion.x; 
    translate.y = vertex.y - cam.postion.y;
    translate.z = vertex.z - cam.postion.z;


    Vec3 rotated = RotateYawPitch(translate , cam.yaw, cam.pitch);
    return rotated; 

    

}


Vec3 GetForwardVector(Camera cam){
    Vec3 forward; 
    forward.x = cosf(cam.pitch) * sinf(cam.yaw);
    forward.y = sinf(cam.pitch); 
    forward.z = cosf(cam.pitch) * cosf(cam.yaw);
    return normalizeVec3(forward);
}


Vec3 GetRightVector(Camera cam){
    Vec3 forward = GetForwardVector(cam);
    Vec3 up = {0,0,0}; 
    return normalizeVec3(crossVec3(forward, up));
}
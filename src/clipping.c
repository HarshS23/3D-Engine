#include "clipping.h"

static Vec3 lerp_vec3(Vec3 a, Vec3 b, float t){

    return (Vec3){
        .x = a.x +(b.x - a.x) * t,
        .y = a.y +(b.y - a.y) * t,
        .z = a.z +(b.z - a.z) * t
    };
}




int ClipTriangleNearPlane(Vec3 v0, Vec3 v1, Vec3 v2, Vec3 out[2][3], float nearZ){
    Vec3 in[3] = {v0, v1, v2};
    Vec3 inside[3];
    Vec3 outside[3];
    
    int incount = 0 , outcount = 0; 

    for(int i = 0; i <3; i++){
        if (in[i].z >= nearZ){
            inside[incount++] = in[i];
        }else{
            outside[outcount++] = in[i];
        }
    }


    if(incount == 0) return 0; // completely clipped
    if (incount == 3){
        out[0][0] = v0, out[0][1] = v1; out[0][2] = v2;
        return 1; 
    }

    if(incount == 1 && outcount == 2){
        Vec3 a = inside[0]; 
        Vec3 b = lerp_vec3(inside[0], outside[0], (nearZ - inside[0].z)/(outside[0].z - inside[0].z));
        Vec3 c = lerp_vec3(inside[0], outside[1], (nearZ - inside[0].z)/(outside[1].z - inside[0].z)); 
        out[0][0] = a; out[0][1] = b; out[0][2] = c;
        return 1;
    }

    if(incount == 2 && outcount == 1){
        Vec3 a = inside[0];
        Vec3 b = inside[1];
        Vec3 c = lerp_vec3(inside[0], outside[0], (nearZ - inside[0].z)/(outside[0].z - inside[0].z));
        Vec3 d = lerp_vec3(inside[1], outside[0], (nearZ - inside[0].z)/(outside[1].z - inside[0].z));

        out[0][0] = a; out[0][1] = b; out[0][2] = c;
        out[1][0] = b; out[1][1] = d; out[1][2] = c;
        return 2;
    }

    return 0 , printf("ERROR CHECK(CLIPPING.C)"); // this should never run






}
#include "vector.h"

// addition of vectors 
Vec3 addVec3(Vec3 a , Vec3 b){
    
    Vec3 c;

    c.x = a.x + b.x;
    c.y = a.y + b.y; 
    c.z = a.z + b.z; 

    return c; 
}  

// subtraction of vectors
Vec3 subVec3(Vec3 a , Vec3 b){ 

    Vec3 c; 
    
    c.x = a.x - b.x; 
    c.y = a.y - b.y; 
    c.z = a.z - b.z; 
    
    return c; 
}

// scale vector 
Vec3 scalVec3(Vec3 a , float s ){

    Vec3 c; 
    c.x = a.x * s; 
    c.y = a.y * s;
    c.z = a.z * s; 

    return c; 
} 

 // dot product
float dotVec3(Vec3 a, Vec3 b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// cross product 
Vec3 crossVec3(Vec3 a, Vec3 b){
    Vec3 c; 

    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;

    return c; 

} 

// vector magnitude (lenght or size of vector)
float lengthVec3(Vec3 a){
    return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);

}


// normalize vector (have vector point in the same direction but change value to 1 ) 
Vec3 normalizeVec3(Vec3 a){ 

    float len = lengthVec3(a);

    if(len == 0.0f){
        return (Vec3) {0.0 , 0.0, 0.0};
    }

    return scalVec3(a , 1.0 / len);


}


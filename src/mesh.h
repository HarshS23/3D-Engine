#ifndef MESH_H 
#define MESH_H


#include "vector.h"
#include "file_finder.h"

// a face triangle stores 3 vertex indices 
typedef struct{

    int a; 
    int b; 
    int c; 

}Face;

// a Mesh stores all vertieces and faces from the obj file 

typedef struct{

    Vec3 *vertices; // array of vertex 
    Face *face; // array of faces
    int vertex_count; 
    int face_count; 

}Mesh;

// loading a mesh from an obj file 

Mesh LoadMeshFromOBJ(const char *filename);



#endif // MESH_H 
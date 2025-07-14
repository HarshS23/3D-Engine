#ifndef MESH_H 
#define MESH_H


#include "vector.h"
#include "file_finder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a face triangle stores 3 vertex indices 
typedef struct{

    int v[3]; // vector 
    int vt[3]; //texture 
    int vn[3]; //normal 

}Face;

// a Mesh stores all vertieces and faces from the obj file 

typedef struct{

    Vec3 *vertices; // array of vertex 
    Face *face; // array of faces
    Vec3 *Normal_Vec; 
    Vec2 *texture;
    int Num_vertex; 
    int Num_face; 
    int Num_Nvec;
    int Num_texture;

}Mesh;


void FreeMesh(Mesh model); 


// loading a mesh from an obj file 
Mesh LoadMeshFromOBJ(const char *filename);




#endif // MESH_H 
#include "mesh.h"


char line[256]; 

Mesh LoadMeshFromOBJ(const char *filename){

    FILE *fread; 
    
    fread = fopen(filename, "r"); 

    if(fread  == NULL){
        printf("There is no file to be read (mesh.c)\n");
        exit(EXIT_FAILURE);
    }

    Mesh model;

    while(fgets(line, sizeof(line), fread)){

        if(line[0] == 'v' && line[1] == ' ')model.Num_vertex++; 
        if(line[0] == 'f' && line[1] == ' ')model.Num_face++; 
        if(line[0] == 'v' && line[1] == 't' && line[2] == ' ')model.Num_texture++; 
        if(line[0] == 'v' && line[1] == 'n' && line[2] == ' ') model.Num_Nvec++; 

    }

    // alocating memeory to read data 
    model.vertices = malloc(model.Num_vertex * sizeof(Vec3)); 
    model.face = malloc(model.Num_face * sizeof(Face)); 
    model.texture = malloc(model.Num_texture * sizeof(Vec2)); 
    model.Normal_Vec = malloc(model.Num_Nvec * sizeof(Vec3)); 


    if(model.vertices == NULL || model.face == NULL || model.texture == NULL || model.Normal_Vec == NULL){
        printf("Unable to allocate memory (mesh.c)\n");
        exit(EXIT_FAILURE); 
    }

    
}
#include "mesh.h"


char line[256]; 

Mesh LoadMeshFromOBJ(const char *filename){

    FILE *fread; 
    
    fread = fopen(filename, "r"); 

    if(fread  == NULL){
        printf("There is no file to be read (mesh.c)\n");
        exit(EXIT_FAILURE);
    }


    // initiilzing model components
    Mesh model;
    model.Num_vertex = 0;
    model.Num_face = 0; 
    model.Num_Nvec = 0; 
    model.Num_texture = 0;


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

    rewind(fread); // resets pointer to the beginning of the file 

    int Vidx = 0, Fidx = 0, Nidx = 0, Tidx = 0; 

    while(fgets(line, sizeof(line), fread)){
        // defines vertex v, and stores in vectices array 
        if(line[0] == 'v' && line[1] == ' '){
            sscanf(line, "v %f %f %f", &model.vertices[Vidx].x, &model.vertices[Vidx].y, &model.vertices[Vidx].z);
            Vidx++;
        }

        //f v/vt/vn
        //f 3220/1805/2160 3205/1790/2160 3219/1804/2160 
        if(line[0] == 'f' && line[1] == ' '){
            sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d" ,&model.face[Fidx].v[0], &model.face[Fidx].vt[0] , &model.face[Fidx].vn[0]
                                                        ,&model.face[Fidx].v[1], &model.face[Fidx].vt[1] , &model.face[Fidx].vn[1]
                                                        ,&model.face[Fidx].v[2], &model.face[Fidx].vt[2] , &model.face[Fidx].vn[2]);

            for(int i = 0; i < 3 ; i++){
                model.face[Fidx].v[i] -= 1;
                model.face[Fidx].vt[i] -= 1;
                model.face[Fidx].vn[i] -= 1;
            }
            Fidx++;
        }

        if(line[0] == 'v' && line[1] == 't' && line[2] == ' '){
            sscanf(line,"vt %f %f", &model.texture[Tidx].u, &model.texture[Tidx].v);
            Tidx++;
        }

        if(line[0] == 'v' && line[1] == 'n' && line[2] == ' '){
            sscanf(line, "vn %f %f %f", &model.Normal_Vec[Nidx].x, &model.Normal_Vec[Nidx].y, &model.Normal_Vec[Nidx].z);
            Nidx++;
        }


        else{
            continue;
        }

        for(int i = 0; i < model.Num_vertex; i++){
            model.vertices[i].z += 0.05;
        }
    }



    fclose(fread);

    return model;
}

void FreeMesh(Mesh model){
    free(model.vertices);
    free(model.face);
    free(model.Normal_Vec);
    free(model.texture);
}
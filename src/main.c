#include "main.h"

// dynamic arrays for file names 
const char **FileList; 
const char *Filename;
const char *FullPath; 

Mesh model;




int main(){
    FileList = list_asset_files("assets"); 
    Filename = select_file(FileList);
    FullPath = FindFile(Filename);
    printf("Here is the file name!!!! : %s\n", FullPath);

    model = LoadMeshFromOBJ(FullPath); // accessing the model.obj file 
    
    init_display(800, 600);
    SDL_Event event; 

    int running = 1; 

    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0; 
            }
        }

        clear_display();
        rendermesh(&model);
        present_display();

    }

    shutdown();
    FreeMesh(model);
    free_arrays();


    return 0; 
}


char* FindFile(const char *filename){
    const char prefix[] = "assets/";
    unsigned int needed = (sizeof(prefix) - 1) + strlen(filename) - 1; // byte size allocation
    char *inputfile = malloc(needed); 

    if(!inputfile){
        perror("Failed to allocate memory for path to file!\n"); 
        exit(EXIT_FAILURE); 
    }

    strcpy(inputfile, prefix);
    strcat(inputfile, filename);

    return inputfile;

}

void free_arrays(){
    for(int i = 0; FileList[i]; i++){
        free((void *) FileList[i]);
    }
    free((void*)FileList);

    free(FullPath);
}
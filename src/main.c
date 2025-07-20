#include "main.h"

// dynamic arrays for file names 
char **FileList; 
char *Filename;
char *FullPath; 

Mesh model;




int main(){

    FileList = list_asset_files("assets"); 
    Filename = select_file(FileList);

    FullPath = FindFile(Filename);
    
    model = LoadMeshFromOBJ(FullPath); // accessing the model.obj file 
    
    init_display(1080, 900);
    SDL_Event event; 

    int running = 1; 
    int render_mode = 1; // 1 = wirefram, 2 = wirevertex; 



    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0; 
            }

            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_1) render_mode = 1; 
                if(event.key.keysym.sym == SDLK_2) render_mode = 2;
            }
        }

        clear_display();

        if(render_mode == 1){
            RenderWireFrame(&model);
        }

        if(render_mode == 2){
            RenderWireVertrix(&model);
        }
        
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

    printf("\n\nINPUT FILE : %s\n\n", inputfile);
    return inputfile;

}

void free_arrays(){
    for(int i = 0; FileList[i]; i++){
        free((void *) FileList[i]);
    }
    free((void*)FileList);

    free(FullPath);
}
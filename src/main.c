#include "main.h"

// dynamic arrays for file names 
char **FileList; 
char *Filename;
char *FullPath; 

Mesh model;

Camera cam;




int main(){

    cam.postion = (Vec3){0.0f, 0.0f, 3.0f};
    cam.yaw = 0.0f;
    cam.pitch = 0.0f;

    FileList = list_asset_files("assets"); 
    Filename = select_file(FileList);

    FullPath = FindFile(Filename);
    
    model = LoadMeshFromOBJ(FullPath); // accessing the model.obj file 
    
    init_display(1080,900);

    SDL_Event event; 

    int running = 1; 
    int render_mode = 1; // 1 = wirefram, 2 = wirevertex; 



    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0; 
            }
            
            const Uint8 *keys = SDL_GetKeyboardState(NULL);
             // camera movement 
            Vec3 forward = GetForwardVector(cam);
            Vec3 right = GetRightVector(cam);


            if(keys[SDL_SCANCODE_W]) cam.postion = addVec3(cam.postion, scalVec3(forward, 0.05f)); // forwards
            if(keys[SDL_SCANCODE_S]) cam.postion = subVec3(cam.postion, scalVec3(forward, 0.05f)); // backwards 
            if(keys[SDL_SCANCODE_A]) cam.postion = subVec3(cam.postion, scalVec3(right, 0.05f)); // left 
            if(keys[SDL_SCANCODE_D]) cam.postion = addVec3(cam.postion, scalVec3(right, 0.05f)); // right 

            // up / down vertical movements  (NOT PITCH)
            if(keys[SDL_SCANCODE_Q]) cam.postion.y += 0.05f; // move camera upwardes 
            if(keys[SDL_SCANCODE_E]) cam.postion.y -= 0.05f; // more camera downwards 


            if(keys[SDL_SCANCODE_LEFT]) cam.yaw -= 0.03f; // rotate left 
            if(keys[SDL_SCANCODE_RIGHT]) cam.yaw += 0.03f; // rotate right 

            if(keys[SDL_SCANCODE_UP]) cam.pitch += 0.03f; // rotate up 
            if(keys[SDL_SCANCODE_DOWN]) cam.pitch -= 0.03f; // rotate down 

            if(cam.pitch > 1.5f) cam.pitch = 1.5f; 
            if(cam.pitch < -1.5f) cam.pitch = -1.5f;

            if(event.type == SDL_KEYDOWN){
                // render modes
                if(event.key.keysym.sym == SDLK_1) render_mode = 1; 
                if(event.key.keysym.sym == SDLK_2) render_mode = 2;
                if(event.key.keysym.sym == SDLK_3) render_mode = 3;
                if(event.key.keysym.sym == SDLK_4) render_mode = 4;
                // reset option
                if(event.key.keysym.sym == SDLK_r){
                    cam.postion = (Vec3){0.0f, 0.0f, 1.5f}; 
                    cam.yaw = 0; 
                    cam.pitch = 0;
                }
            }

        }




        clear_display();

        if(render_mode == 1){
            RenderWireFrame(&model, cam);
        }

        if(render_mode == 2){
            RenderWireVertrix(&model, cam);
        }
        
        if(render_mode == 3){
            RenderFilled(&model, cam);
        }

        if(render_mode == 4){
            RenderFilledVertex(&model, cam);
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
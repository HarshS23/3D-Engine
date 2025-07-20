#include "display.h"



static SDL_Window *Window = NULL; 
static SDL_Renderer *Renderer = NULL; 
static int center_x, center_y; 
static float scale = 1000.0f; 






void init_display(int width, int height){
    SDL_Init(SDL_INIT_EVERYTHING);
     if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        printf("Unable to initlizize (display.c)\n");
        exit(EXIT_FAILURE);
    }

    Window = SDL_CreateWindow("3D-ENGINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,\
    width, height , SDL_WINDOW_SHOWN);

    if(!Window){
        printf("The window could not be created! (display.c)\n");
        exit(EXIT_FAILURE);
    }

    Renderer = SDL_CreateRenderer(Window,-1, 0);

    if(Renderer == NULL){
        printf("Could not be rendererd (display.c)\n");
        SDL_DestroyWindow(Window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    center_x = width / 2;
    center_y = height / 2;
}


void clear_display(void){

    SDL_SetRenderDrawColor(Renderer, 0 , 0, 0 , 255);  // this is the background color
    SDL_RenderClear(Renderer);
}




void RenderWireFrame(const Mesh *model){

    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255); // line color is white 

    for(int i = 0; i < model->Num_face; i++){
        Face face = model->face[i]; 


        for(int edge = 0; edge < 3; edge++){
            int idx0 = face.v[edge]; 
            int idx1 = face.v[(edge + 1) % 3];
            
            Vec3 v0 = model->vertices[idx0];
            Vec3 v1 = model->vertices[idx1];

            int x0 = (v0.x  / v0.z) * scale + center_x; 
            int y0 = -(v0.y / v0.z) * scale + center_y;
            int x1 = (v1.x  / v1.z) * scale + center_x; 
            int y1 = -(v1.y / v1.z) * scale + center_y;


            SDL_RenderDrawLine(Renderer, x0 ,y0 , x1 , y1);


        }
    }
}


void present_display(void){
    SDL_RenderPresent(Renderer);
}


void shutdown(void){
    SDL_DestroyRenderer(Renderer); 
    SDL_DestroyWindow(Window);
    SDL_Quit();
}
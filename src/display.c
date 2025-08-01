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


void DrawLinePickColor(const Mesh *model, Camera cam, int r , int g, int b){

    if ((r < 0) || (r > 255)){
        perror("Color is not within the index of 0 < r < 255: (display.c)\n"); 
        exit(EXIT_FAILURE);
    }
     if ((g < 0) || (g > 255)){
        perror("Color is not within the index of 0 < g < 255: (display.c)\n"); 
        exit(EXIT_FAILURE);
    }
     if ((b < 0) || (b > 255)){
        perror("Color is not within the index of 0 < b < 255: (display.c)\n"); 
        exit(EXIT_FAILURE);
    }


    SDL_SetRenderDrawColor(Renderer, r, g, b, 255); // line color is white 

    for(int i = 0; i < model->Num_face; i++){
        Face face = model->face[i]; 


        for(int edge = 0; edge < 3; edge++){
            int idx0 = face.v[edge]; 
            int idx1 = face.v[(edge + 1) % 3];
            
            Vec3 v0 = model->vertices[idx0];
            Vec3 v1 = model->vertices[idx1];

            Vec3 transform_v0 = TransformCamera(v0 , cam); 
            Vec3 transform_v1 = TransformCamera(v1 , cam);

            if(transform_v0.z <= 0.01f || transform_v1.z <= 0.01f) continue;



            int x0 = (transform_v0.x  / transform_v0.z) * scale + center_x; 
            int y0 = -(transform_v0.y / transform_v0.z) * scale + center_y;
            int x1 = (transform_v1.x  / transform_v1.z) * scale + center_x; 
            int y1 = -(transform_v1.y / transform_v1.z) * scale + center_y;


            SDL_RenderDrawLine(Renderer, x0 ,y0 , x1 , y1);
        }
    }

}

void RenderWireFrame(const Mesh *model, Camera cam){

    DrawLinePickColor(model, cam, 255 , 255, 255); 

}

void RenderWireVertrix(const Mesh *model, Camera cam){
    DrawLinePickColor(model, cam, 255 , 255, 255); 

    SDL_SetRenderDrawColor(Renderer, 255, 0 , 0 ,255); // this is red 

    for(int i = 0; i < model->Num_vertex; i++){
        Vec3 v = model->vertices[i];
        Vec3 transform = TransformCamera(v , cam);

        if(transform.z <= 0 ) continue;

        int x = (transform.x / transform.z) * scale + center_x; 
        int y = -(transform.y / transform.z) * scale + center_y;

        DrawCircle(Renderer, x, y, 5);
    }

}

void DrawCircle(SDL_Renderer *Renderer, int x, int y, int r){

    SDL_Rect dot = {x-2, y - 2, 4,4}; 
    SDL_RenderFillRect(Renderer, &dot);
}



void RenderFilled(const Mesh *model, Camera cam){
    SDL_SetRenderDrawColor(Renderer, 200, 200, 200, 255); 
    for(int i = 0; i < model->Num_face; i++){
        Face face = model->face[i];
        Vec3 v0 = TransformCamera(model->vertices[face.v[0]], cam);
        Vec3 v1 = TransformCamera(model->vertices[face.v[1]], cam);
        Vec3 v2 = TransformCamera(model->vertices[face.v[2]], cam);

        if(v0.z <= 0 || v1.z <=0 || v2.z <= 0) continue; 

        int x0 = (v0.x / v0.z) * scale + center_x;
        int y0 = -(v0.y / v0.z) * scale + center_y;
        int x1 = (v1.x / v1.z) * scale + center_x;
        int y1 = -(v1.y / v1.z) * scale + center_y;
        int x2 = (v2.x / v2.z) * scale + center_x;
        int y2 = -(v2.y / v2.z) * scale + center_y;

        filledTriangle(Renderer, x0, y0, x1, y1, x2, y2);
        //printf("Rendering filled triangle mode...\n");
    }

}

void RenderFilledVertex(const Mesh *model, Camera cam){

    SDL_SetRenderDrawColor(Renderer, 200, 200, 200, 255); 
    for(int i = 0; i < model->Num_face; i++){
        Face face = model->face[i];
        Vec3 v0 = TransformCamera(model->vertices[face.v[0]], cam);
        Vec3 v1 = TransformCamera(model->vertices[face.v[1]], cam);
        Vec3 v2 = TransformCamera(model->vertices[face.v[2]], cam);

        if(v0.z <= 0 || v1.z <=0 || v2.z <= 0) continue; 

        int x0 = (v0.x / v0.z) * scale + center_x;
        int y0 = -(v0.y / v0.z) * scale + center_y;
        int x1 = (v1.x / v1.z) * scale + center_x;
        int y1 = -(v1.y / v1.z) * scale + center_y;
        int x2 = (v2.x / v2.z) * scale + center_x;
        int y2 = -(v2.y / v2.z) * scale + center_y;

        filledTriangle(Renderer, x0, y0, x1, y1, x2, y2);
    }

    DrawLinePickColor(model, cam, 0 , 0, 0); 

    SDL_SetRenderDrawColor(Renderer, 255, 0 , 0 ,255); // this is red 

    Vec3 *transformed = malloc(model->Num_vertex * sizeof(Vec3));
    for(int i = 0; i < model->Num_vertex; i++){
        Vec3 v = model->vertices[i];
        transformed[i] = TransformCamera(v, cam);
    }
    // now we render using that temp/ transformed i 

    for(int i = 0; i < model->Num_vertex; i++){
        Vec3 t = transformed[i];

        if(t.z <= 0.1f) continue;

        int x = (t.x / t.z) * scale + center_x; 
        int y = -(t.y / t.z) * scale + center_y;

        DrawCircle(Renderer, x, y, 5);

    }

    free(transformed);

}






void present_display(void){
    SDL_RenderPresent(Renderer);
}


void shutdown(void){
    SDL_DestroyRenderer(Renderer); 
    SDL_DestroyWindow(Window);
    SDL_Quit();
}
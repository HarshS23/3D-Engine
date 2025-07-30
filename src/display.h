#ifndef DISPLAY_H
#define DISPLAY_H


#include "SDL.h"
#include "mesh.h"
#include "vector.h"
#include "camera.h"
#include "triangle.h"

int initlizeWindow(void);
void init_display(int width, int height); 
void clear_display(void);
void DrawCircle(SDL_Renderer *Renderer, int x, int y, int r);

void RenderWireFrame(const Mesh *model, Camera cam);
void RenderWireVertrix(const Mesh *model, Camera cam);
void present_display(void); 
void shutdown(void);

void RenderFilled(const Mesh *model, Camera cam);



#endif



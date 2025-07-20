#ifndef DISPLAY_H
#define DISPLAY_H


#include "SDL.h"
#include "mesh.h"
#include "vector.h"

int initlizeWindow(void);
void init_display(int width, int height); 
void clear_display(void);
void DrawCircle(SDL_Renderer *Renderer, int x, int y, int r);

void RenderWireFrame(const Mesh *model);
void RenderWireVertrix(const Mesh *model);
void present_display(void); 
void shutdown(void);




#endif



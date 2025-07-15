#ifndef DISPLAY_H
#define DISPLAY_H


#include "SDL.h"
#include "mesh.h"
#include "vector.h"


void init_display(uint32_t width, uint32_t height); 
void clear_display(void);
void rendermesh(const Mesh *model);
void present_display(void); 
void shutdown(void);




#endif



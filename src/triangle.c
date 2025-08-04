
#include "triangle.h"

void filledTriangle(SDL_Renderer *renderer, int x0, int y0, int x1, int y1, int x2 , int y2){

    // Sort by y-coordinate ascending (y0 <= y1 <= y2)
    if (y0 > y1) { int t=y0; y0=y1; y1=t; t=x0; x0=x1; x1=t; }
    if (y1 > y2) { int t=y1; y1=y2; y2=t; t=x1; x1=x2; x2=t; }
    if (y0 > y1) { int t=y0; y0=y1; y1=t; t=x0; x0=x1; x1=t; }

    float dx1 = 0, dx2 = 0;

    if (y1 - y0 > 0)
        dx1 = (float)(x1 - x0) / (y1 - y0);
    if (y2 - y0 > 0)
        dx2 = (float)(x2 - x0) / (y2 - y0);

    float sx = x0;
    float ex = x0;

    for (int y = y0; y <= y1; y++) {
        SDL_RenderDrawLine(renderer, (int)sx, y, (int)ex, y);
        sx += dx1;
        ex += dx2;
    }

    if (y2 - y1 > 0)
        dx1 = (float)(x2 - x1) / (y2 - y1);
    if (y2 - y0 > 0)
        dx2 = (float)(x2 - x0) / (y2 - y0);

    sx = x1;
    ex = x0 + dx2 * (y1 - y0);

    for (int y = y1; y <= y2; y++) {
        SDL_RenderDrawLine(renderer, (int)sx, y, (int)ex, y);
        sx += dx1;
        ex += dx2;
    }
}




void filledTriangleVertex(SDL_Renderer *renderer, int x0, int y0, int x1, int y1, int x2 , int y2){

    // Sort by y-coordinate ascending (y0 <= y1 <= y2)
    if (y0 > y1) { int t=y0; y0=y1; y1=t; t=x0; x0=x1; x1=t; }
    if (y1 > y2) { int t=y1; y1=y2; y2=t; t=x1; x1=x2; x2=t; }
    if (y0 > y1) { int t=y0; y0=y1; y1=t; t=x0; x0=x1; x1=t; }

    float dx1 = 0, dx2 = 0;

    if (y1 - y0 > 0)
        dx1 = (float)(x1 - x0) / (y1 - y0);
    if (y2 - y0 > 0)
        dx2 = (float)(x2 - x0) / (y2 - y0);

    float sx = x0;
    float ex = x0;

    for (int y = y0; y <= y1; y++) {
        SDL_RenderDrawLine(renderer, (int)sx, y, (int)ex, y);
        sx += dx1;
        ex += dx2;
    }

    if (y2 - y1 > 0)
        dx1 = (float)(x2 - x1) / (y2 - y1);
    if (y2 - y0 > 0)
        dx2 = (float)(x2 - x0) / (y2 - y0);

    sx = x1;
    ex = x0 + dx2 * (y1 - y0);

    for (int y = y1; y <= y2; y++) {
        SDL_RenderDrawLine(renderer, (int)sx, y, (int)ex, y);
        sx += dx1;
        ex += dx2;
    }
}






#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "SDL.h"
#include "file_finder.h"
#include "display.h"
#include "mesh.h"
#include "vector.h"
#include "camera.h"
#include "light.h"

void free_arrays();

char* FindFile(const char *filename);

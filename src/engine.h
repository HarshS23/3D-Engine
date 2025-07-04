#ifndef ENGINE_H 
#define ENGINE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <dirent.h>
#include "SDL.h"


// fuctions needed 

char** list_asset_files(const char* folder); 
const char *select_file(const char** filename);


#endif
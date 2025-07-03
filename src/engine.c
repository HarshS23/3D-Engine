
#include "engine.h"

void list_asset_files(const char* folder){
    DIR *dir = opendir(folder); 

    if(!dir){
        printf("Unable to oepn assets directory!\n"); 
        return 0; 
    }

    printf("Avaliable object files: \n"); 
    struct dirent *entry;

    while(entry == readdir(dir) != NULL){
        if(strstr(entry->d_name, ".obj"));
        printf("- %s\n", entry->d_name);
    }

    closedir(dir); 
}
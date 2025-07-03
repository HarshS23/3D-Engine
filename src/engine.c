
#include "engine.h"

void list_asset_files(const char* folder){

    DIR *dir = opendir(folder); 

    if(!dir){
        printf("Unable to oepn assets directory!\n"); 
        return; 
    }

    printf("Avaliable object files: \n"); 

    struct dirent *entry;
    int count = 0;
    while((entry = readdir(dir)) != NULL){
        if(strstr(entry->d_name, ".obj")){
            printf("- %s\n", entry->d_name);
            count++;
        }
    }

    closedir(dir); 
}

void select_file(const char* filepath){


    void;
}
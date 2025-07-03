
#include "engine.h"

char** list_asset_files(const char* folder){

    DIR *dir = opendir(folder); 

    if(!dir){
        printf("Unable to oepn assets directory!\n"); 
        exit(EXIT_FAILURE);
         
    }

    printf("Avaliable object files: \n"); 

    struct dirent *entry;
    char** filename = NULL;
    int count = 0;
    while((entry = readdir(dir)) != NULL){
        if(strstr(entry->d_name, ".obj")){
            printf("- %s\n", entry->d_name);
            filename = realloc(filename, (count + 1) * sizeof(char*));
            filename[count] = strdup(entry->d_name); // allocate and copy
            count++;
        }
    }
    closedir(dir); 

    return filename;
}

void select_file(const char* filepath){


    void;
}
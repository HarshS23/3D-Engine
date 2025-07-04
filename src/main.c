#include "main.h"

const char **FileList; 
const char *Filename;


int main(){
    FileList = list_asset_files("assets"); 
    Filename = select_file(FileList);
    printf("Here is the file you selected: %s\n", Filename);
    free_arrays();
    return 0; 
}

void free_arrays(){
    for(size_t i = 0; FileList[i]; i++){
        free(Filename);
        //free((void *) FileList[i]);
    }
    free((void*)FileList);
    // free(Filename);
}
#include "main.h"

// all pointers needed 
const char **FileList; 
const char *Filename;


int main(){
    FileList = list_asset_files("assets"); 
    Filename = select_file(FileList);
    ParseFile(Filename);    
    free_arrays();
    return 0; 
}


void ParseFile(const char *filename){
    const char prefix[] = "assets/";
    unsigned int needed = (sizeof(prefix) - 1) + strlen(filename) - 1; // byte size allocation
    char *inputfile = malloc(needed); 

    if(!inputfile){
        perror("Failed to allocate memory for path to file!\n"); 
        exit(EXIT_FAILURE); 
    }

    strcpy(inputfile, prefix);
    strcat(inputfile, filename);

    printf("Here is the filename: %s\n", inputfile);





}

void free_arrays(){
    for(int i = 0; FileList[i]; i++){
        free((void *) FileList[i]);
    }

    free((void*)FileList);
}
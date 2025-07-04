#include "main.h"




int main(){
    char** files; 

    files = list_asset_files("assets"); 
    select_file(files);
    return 0; 
}
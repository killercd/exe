#include <stdio.h>

char exefile[] = "whoami.exe";
int main(){
    char f,s;

    printf("opening file %s...\n", exefile);
    void *fhandle = fopen(exefile, "r");

    if(fhandle==NULL){
        goto jmp_error;
    }



    //check PE header
    f=fgetc(fhandle);
    s=fgetc(fhandle);

    if(f!='M' || s !='Z'){
        printf("not executable file found\n");
        goto jmp_error;
    }


    jmp_error:
    if(fhandle == NULL) fclose(fhandle);
    
    return 0;
}

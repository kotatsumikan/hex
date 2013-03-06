#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1

int main(int argc, char** args){
    FILE *f;
    void *buf;
    if(argc <= 1){
        printf("Usage: hex [FILE|-]\n");
        return(1);
    }

    buf = malloc(BUFSIZE);
    buf = memset(buf, 0, BUFSIZE);

    if(strlen(args[1]) == 1 && *args[1] == '-'){
        f = stdin;
    }else{
        f = fopen(args[1], "r");
    }
    if(!f){
        fprintf(stderr, "file open error\n");
        return(-1);
    }
    while(fread(buf, BUFSIZE, 1, f)){
        printf("%02x", *(unsigned char*)buf);
    }
    fclose(f);
    free(buf);
    printf("\n");
    return(0);
}

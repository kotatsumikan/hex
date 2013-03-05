#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1

int main(int argc, char** args){
    FILE *f;
    void *buf;
    if(argc <= 1){
        printf("Usage: hex filename\n");
        return(1);
    }

    buf = malloc(BUFSIZE);
    buf = memset(buf, 0, BUFSIZE);

    f = fopen(args[1], "r");
    while(fread(buf, BUFSIZE, 1, f)){
        printf("%02x", *(char*)buf);
    }
    fclose(f);
    free(buf);
    printf("\n");
    return(0);
}

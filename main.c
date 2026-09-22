#include "functions.h"
#include <stdio.h>
struct stat st;
int main(int a1, char** args) {
    FILE* fptr = fopen(args[1], "r");
    stat(args[1], &st);
    int filesize = st.st_size;
    char filecontent[filesize];
    fread(filecontent, filesize, sizeof(char), fptr);
    filecontent[filesize] = '\0';
    int filelines = countlines(filecontent);
    // retline result;
    // result = getlines(filecontent,3);
    // retword result2 = getword(result.buffer,2);
    printf("LINES = %i\n" ,filelines);
    printf("FILE NAME = %s\n", args[1]);
    int saida = RunCode(filecontent, filesize, args[1]);
    if (!saida) {
        puts("codigo com erros.");
    }
    return 0;
}

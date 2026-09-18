#include "codefunctions.h"
#include "../functions.h"
#include <stdio.h>
#include <string.h>
int print(char* linestr, int wordcount, int line) {
    //puts("LA ELE !");
  //  printf("wordcount %i\n", wordcount);
    if (wordcount == 0) return 0;
    if (wordcount < 2) {
        printf("\nuso incorreto do print ! LINE:%i\n", line+1);
    }
    for (int i=0;i<wordcount;i++) {
    retword actualstr = getword(linestr, i);;
    if (actualstr.aspas == 1) {
    printf("%s", actualstr.string);
    }
    if (strcmp(actualstr.string,"NL") == 0) {
        printf("\n");
    }
    }
    return 1;
}



#include "functions.h"
#include "code/codefunctions.h"
retword getword(char* str, int index){
    retword ret;
    if (str == NULL) return ret;
    int spacecount = 0;
    int strsize = strlen(str);
    int start[strsize+10];
    char *buffer = malloc(strsize);
    int dentroaspas = 0;
    ret.aspas = 0;
    start[0]=0;
    for (int i=0;i<strsize;i++) {
        if (str[i] == '"') {
            dentroaspas = !dentroaspas;
           // ret.aspas=1;
          //  printf("aspas = %i\n", dentroaspas);
        }
        else if (str[i] == ' ') {
            if (dentroaspas ==0 ) {
                spacecount++;
                start[spacecount] = i+1;
            }
            //    puts("espaco achado");
        }
    }
    if (index > spacecount) return ret;
    int loop = 0;
    if (dentroaspas == 1) {
        puts("ASPAS NAO FINALIZADA !");
    }
    dentroaspas = 0;
    if(str[start[index]] == '"') {
    }
    int idx = start[index];
    while (str[idx] != '\0') {
        if (str[idx] == '"') {
            dentroaspas = !dentroaspas;
            ret.aspas=1;
            idx++;
            continue;
        }
        else if (str[idx] == ' ' && dentroaspas == 0) {
            break;
        }
        buffer[loop] = str[idx];
        idx++;
        loop++;
    }
    buffer[loop] = '\0';
    //printf("\nbuffer = %s\n", buffer);
   // memcpy(ret.string, buffer, sizeof(buffer));
    ret.quantity = spacecount;
    ret.start = start[index];
    ret.string = buffer;
    return ret;
}

int countlines(const char* str) {
    int result = 0;
    int len = strlen(str);
    if (len>result) result = 1;
    for (int i=0;i<strlen(str);i++) {
        if (str[i] == '\n') {
            result++;
        }
    }
    return result;
}
int countwords(const char* str) {
    int ret=0;
    int aspas =0;
    int strsize = strlen(str);
    int wordscounts = 0;
    for (int i=0;i<strsize;i++) {
        if (str[i] == '"') {
          // puts("ASPAS");
            aspas = !aspas;
            continue;
        }
        if (str[i] == ' ' && str[i] != '\n' && str[i] != '\0') {
            wordscounts++;
        }
    }
    ret = wordscounts;
    return ret + 1;
}
retline getlines(char* str, int argline) {
    retline ret;
    int strsize = strlen(str);
    char *buffer = malloc(strsize + 1);
    int start[strsize + 1];
    int count = 0;
    start[0] = 0;
    for (int i=0;i<strlen(str);i++) {
        if (str[i] == '\n') {
            count++;
            start[count] = i+1;
        }
    }
    int base = start[argline];
    int loop = 0;
    while (str[loop + base] != '\n' && str[loop + base] != '\0') {
        buffer[loop] = str[loop + base];
        loop++;
    };
    buffer[loop] = '\0';
  //buffer[loop] = str[loop+start[argline]];
    ret.buffer = buffer;
    ret.start = base;
    return ret;
}
int RunCode(char* codestr, int codesize, char* filename) {
    int ret = 1;
    int linescount = countlines(codestr);
       int canstart = 0;
    printf("lines count = %i\n\n\n", linescount);
    for (int lineloop=0;lineloop<linescount;lineloop++) {
        retline actualline = getlines(codestr, lineloop);
        //printf("actual line = %s\n", actualline.buffer);
        int wordcount = countwords(actualline.buffer);
        //printf("space counts %i\n", wordcount);
        if (wordcount>0) {
           // puts("wcount");
            retword word = getword(actualline.buffer, 0);
           // puts(word.string);
            if (strcmp(word.string, "main:") == 0) {
                canstart = 1;
            }
            if (canstart == 1) {
            if (strcmp(word.string, "print") == 0) {
                print(actualline.buffer,wordcount,lineloop);
            }
            }
        } // if (spacecounts>0)
    } // for (int mainloop=0;mainloop<linescount;mainloop++)
    return ret;
}

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistdio.h>
#include <sys/stat.h>
#include <string.h>
typedef struct {
    int start;
    char* buffer;
} retline;
typedef struct {
    int start;
    char* string;
    int quantity;
    int aspas;
    int argument;
    int variable;
} retword;
retword getword(char* str, int index);
int countlines(const char* str);
int countwords(const char* str);
retline getlines(char* str, int argline);
int RunCode(char* codestr, int size, char* filename);

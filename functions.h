#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#ifndef prototype
#define prototype

#define LIST_FILE "sources/list.info"
#define NAME_SIZE 50

typedef struct source source;

int initProgram();
int checkFile(char*);
int getFileSize(FILE*);

void showSources(source*);

source* loadSources();
source* newSource(source*,char*);

#endif

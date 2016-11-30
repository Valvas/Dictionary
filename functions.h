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

void showSources(source*);
void newSource(source*,char*);

source* loadSources();

#endif

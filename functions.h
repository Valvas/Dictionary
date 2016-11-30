#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#ifndef prototype
#define prototype

#define LIST_FILE "../../sources/list.info"

typedef struct source source;

int initProgram();

source* loadSources();

#endif

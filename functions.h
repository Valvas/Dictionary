#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "enum.h"

#ifndef prototype
#define prototype

#define LIST_FILE "sources/list.info"
#define NAME_SIZE 50

#ifdef _WIN32
#define CLEAR system("cls");
#endif

#ifdef linux
#define CLEAR system("clear");
#endif

typedef struct source source;

int initProgram();
int entry(char*,int);
int checkFile(char*);
int getFileSize(FILE*);
int checkNumberOfArguments(char*,int*);

long integer(int);

void menu(source*);
void cleanBuffer();
void showSources(source*);
void beginningFormat(char*,int*);
void removeBlankAtEnd(char*,int*);
void setContentToLowercase(char*,int*);
void printContentSourceFile(char*,char*);
void removeBlankAfterLineBreak(char*,int*,int);
void removeBlankBeforeLineBreak(char*,int*,int);

source* loadSources();
source* newSource(source*,char*);

#endif

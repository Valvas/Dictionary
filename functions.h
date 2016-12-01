#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "enum.h"

#ifndef prototype
#define prototype

#define LIST_FILE "sources/list.info"
#define NAME_SIZE 50
#define NAME_SIZE_NO_PATH 40
#define SOURCE_FOLDER_PATH "sources/"

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
int addSourceInList(char*);
int checkNumberOfArguments(char*,int*);
int checkSourceExistence(source*,char*);

long integer(int);

void menu(source*);
void cleanBuffer();
void addSource(source*);
void manageSources(source*);
void showSources(source*,int*);
void beginningFormat(char*,int*);
void removeBlankAtEnd(char*,int*);
void setContentToLowercase(char*,int*);
void printContentSourceFile(char*,char*);
void removeBlankAfterLineBreak(char*,int*,int);
void removeBlankBeforeLineBreak(char*,int*,int);

source* loadSources();
source* newSource(source*,char*);

#endif

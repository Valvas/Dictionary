#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "enum.h"

#ifndef prototype
#define prototype

#define TITLE 100
#define ORIGIN 100
#define NAME_SIZE 50
#define DEFINITION 1000
#define NAME_SIZE_NO_PATH 40
#define LIST_FILE "sources/list.info"
#define SOURCE_FOLDER_PATH "sources/"

#ifdef _WIN32
#define CLEAR system("cls");
#endif

#ifdef APPLE
#define CLEAR system("cls");
#endif

#ifdef linux
#define CLEAR system("clear");
#endif

typedef struct head head;
typedef struct word word;
typedef struct source source;
typedef struct primary primary;

int initProgram();
int entry(char*,int);
int checkFile(char*);
int getFileSize(FILE*);
int addSourceInList(char*);
int newSource(head*,char*);
int removeSourceInList(char*);
int removeSource(head*,source*);
int checkNumberOfArguments(char*,int*);
int checkSourceExistenceForAdding(head*,char*);
int checkSourceExistenceForRemoving(head*,char*);

long integer(int);

void menu(head*);
void cleanBuffer();
void addSource(head*);
void loadSources(head*);
void deleteSource(head*);
void manageSources(head*);
void getWord(primary*,char*);
void showSources(source*,int*);
void readSource(primary*,char*);
void beginningFormat(char*,int*);
void removeBlankAtEnd(char*,int*);
void browseSources(head*,primary*);
void setContentToLowercase(char*,int*);
void printContentSourceFile(char*,char*);
void createWord(primary*,char*,char*,char*);
void removeBlankAfterLineBreak(char*,int*,int);
void removeBlankBeforeLineBreak(char*,int*,int);

source* initSources(head*,char*);

#endif

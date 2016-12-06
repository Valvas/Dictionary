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


/** Prototypes without descriptions are in a 'c' file with the same name as the function **/

int initProgram();
int entry(char*,int);
int checkFile(char*);
int getFileSize(FILE*);
int addSourceInList(char*);
int newSource(head*,char*);
int removeSourceInList(char*);
int removeSource(head*,source*);
int checkNumberOfArguments(char*,int*);				/** "formatSources.c" **/
int checkSourceExistenceForAdding(head*,char*);
int checkSourceExistenceForRemoving(head*,char*);

long integer(int);

void cleanBuffer();
void addWord(char*);
void printWord(word*);
void addSource(head*);
void loadSources(head*);
void deleteSource(head*);
void menu(head*,primary*);
void getWord(primary*,char*);
void showSources(source*,int*);
void readSource(primary*,char*);
void beginningFormat(char*,int*); 					/** "formatSources.c" **/
void removeBlankAtEnd(char*,int*);					/** "formatSources.c" **/
void createSource(head*,primary*);
void browseSources(head*,primary*);
void manageSources(head*,primary*);
void setContentToLowercase(char*,int*);				/** "formatSources.c" **/
void printContentSourceFile(char*,char*);			/** "formatSources.c" **/
void createWord(primary*,char*,char*,char*);
void removeBlankAfterLineBreak(char*,int*,int); 	/** "formatSources.c" **/
void removeBlankBeforeLineBreak(char*,int*,int); 	/** "formatSources.c" **/

source* initSources(head*,char*);

#endif

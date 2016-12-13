#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "enum.h"

#ifndef prototype
#define prototype

#define LIMIT 2
#define TITLE 100
#define ORIGIN 100
#define NAME_SIZE 50
#define DEFINITION 1000
#define NAME_SIZE_NO_PATH 40
#define LIST_FILE "sources/list.info"
#define SOURCE_FOLDER_PATH "sources/"
#define DOCUMENT_FOLDER_PATH "doc/"

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
int getTitle(char*);								/** "addWord.c" **/
int entry(char*,int);
int checkFile(char*);
int getOrigin(char*);								/** "addWord.c" **/
int getDefinition(char*);							/** "addWord.c" **/
int addSourceInList(char*);
int newSource(head*,char*);
int removeSourceInList(char*);
int removeSource(head*,source*);
int checkWord(primary*,char*,char*);
int checkSourceExistenceForAdding(head*,char*);
int checkSourceExistenceForRemoving(head*,char*);

long integer(int);

long long getFileSize(FILE*);

void cleanBuffer();
void freeWords(word*);
void printWord(word*);
void searchWord(word*);
void loadSources(head*);
void deleteSource(head*);
void freeSources(source*);
void menu(head*,primary*);
void addWord(primary*,char*);
void showSources(source*,int*);
void selectSource(head*,char*);
void addSource(head*,primary*);
void createWord(primary*,char*);
void readSource(primary*,char*);
void replaceContent(char*,char*);
void createSource(head*,primary*);
void browseSources(head*,primary*);
void manageSources(head*,primary*);
void insertWordInSource(char*,char*);

source* initSources(head*,char*);

#endif

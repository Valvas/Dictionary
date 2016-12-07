#include "functions.h"

/**

1 - Calling function 'initProgram' to check if sources list file can be opened
2 - Exiting program with error message for user
3 - Loading all sources in LIST_FILE (constant defined in "functions.h")
4 - Loading all words in sources
5 - Call main menu
6 - Free source linked list
7 - Free word linked list
8 - Free pointer for each linked list

**/

int main(int argc, char* argv[])
{
    /** Step 1 **/
    if(initProgram() == 0)
    {
        /** Step 2 **/
        printf("\nERROR : file at path \"%s\" cannot be created or opened !\n",LIST_FILE);
        printf("\nPress enter to exit...");
        getchar();
        exit(0);
    }
	
	primary* firstWord = malloc(sizeof(primary));
	firstWord->wordTarget = malloc(sizeof(word));
	firstWord->wordTarget = NULL;
	
	head* listHead = malloc(sizeof(head));
	listHead->sourceTarget = malloc(sizeof(source));
	listHead->sourceTarget = NULL;
	
	/** Step 3 **/
	loadSources(listHead);
	
	/** Step 4 **/
	browseSources(listHead,firstWord);
	
	//readDocument(firstWord); TEST FOR READ DOCUMENT AND CHECK WORD
	
	/** Step 5 **/
	menu(listHead,firstWord);
	
	/** Step 6 **/
	freeSources(listHead->sourceTarget);
	
	/** Step 7 **/
	freeWords(firstWord->wordTarget);
	
	/** Step 8 **/
	free(listHead->sourceTarget);
	free(firstWord->wordTarget);
	free(listHead);
	free(firstWord);

    return 0;
}

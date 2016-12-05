#include "functions.h"

/**

1 - Calling function 'initProgram' to check if sources list file can be opened
2 - Exiting program with error message for user
3 - Loading all sources in LIST_FILE (constant defined in "functions.h")
4 - Call main menu

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
	
	head* listHead = malloc(sizeof(head));
	listHead->sourceTarget = malloc(sizeof(source));
	listHead->sourceTarget = NULL;
	
	/** Step 3 **/
	loadSources(listHead);
	
	/** Step 4 **/
	menu(listHead);

    return 0;
}

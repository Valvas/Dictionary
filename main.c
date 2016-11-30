#include "functions.h"

/**

1 - Calling function 'initProgram' to check if sources list file can be opened
2 - Exiting program with error message for user

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
	
	source* firstSource = loadSources();
	
	showSources(firstSource);

    return 0;
}

#include "functions.h"

/**

INFO -	This function adds the new source path in LIST_FILE (constant defined in "functions.h")

1 - Open LIST_FILE in write mode
2 - Write the path of the new source file at the end of LIST_FILE on a new line

**/

int addSourceInList(char* name)
{
    FILE* file = NULL;

    
	/** Step 1 **/
	file = fopen(LIST_FILE,"a");

    if(file != NULL)
    {
        /** Step 2 **/
		fprintf(file,"\n%s",name);
        fclose(file);
		
		CLEAR
		printf("\nSUCCESS : source file added in \"%s\" !\n",LIST_FILE);
		printf("\nPress enter to continue...");
		getchar();
		return 1;
    }

    else
    {
        CLEAR
        printf("\nERROR : cannot open \"list.info\" !\n");
        printf("\nPress enter to continue...");
        getchar();
		return 0;
    }
}

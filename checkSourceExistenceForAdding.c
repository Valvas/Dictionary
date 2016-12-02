#include "functions.h"

/**

INFO -	This function checks if there is not already another source with the same name in the linked list

1 - Create a temporary source in order to browse all the linked list
2 - Check if the temporary source contains the first source of the linked list
3 - Loop which executes itself while 'tmpSource' is not NULL
4 - Check if 'tmpSource->sourcePath' and the new source path are the same
5 - If they are not the same pick the next source in the linked list and execute the loop again

**/

int checkSourceExistenceForAdding(source* firstSource, char* name)
{	
	/** Step 1 **/
	source* tmpSource = firstSource;
	
	/** Step 2 **/
	if(tmpSource)
	{		
		/** Step 3 **/
		while(tmpSource)
		{
			/** Step 4 **/
			if(strcmp(tmpSource->sourcePath,name) == 0)
			{
				CLEAR
				printf("\nERROR : source file already exists !\n");
				printf("\nPress enter to continue...");
				getchar();
				return 0;
			}

			/** Step 5 **/
			tmpSource = tmpSource->nextSource;
		}
		
		return 1;
	}
	
	else
	{
		CLEAR
		printf("\nERROR : cannot create temporary source element !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
	}
}
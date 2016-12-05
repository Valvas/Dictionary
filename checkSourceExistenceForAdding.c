#include "functions.h"

/**

INFO -	This function checks if there is not already another source with the same name in the linked list

1 - Check if there is at least one source, if not there is no need to check if source to add already exists
2 - Create a temporary source in order to browse all the linked list
3 - Check if the temporary source contains the first source of the linked list
4 - Loop which executes itself while 'tmpSource' is not NULL
5 - Check if 'tmpSource->sourcePath' and the new source path are the same
6 - If they are not the same pick the next source in the linked list and execute the loop again

**/

int checkSourceExistenceForAdding(head* listHead, char* name)
{	
	/** Step 1 **/
	if(listHead->sourceTarget == NULL)
	{
		return 1;
	}
	
	/** Step 2 **/
	source* tmpSource = listHead->sourceTarget;
	
	/** Step 3 **/
	if(tmpSource)
	{		
		/** Step 4 **/
		while(tmpSource)
		{
			/** Step 5 **/
			if(strcmp(tmpSource->sourcePath,name) == 0)
			{
				CLEAR
				printf("\nERROR : source file already exists !\n");
				printf("\nPress enter to continue...");
				getchar();
				return 0;
			}

			/** Step 6 **/
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
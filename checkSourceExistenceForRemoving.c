#include "functions.h"

/**

INFO -	This function checks if the name of source entered by user exists, it returns 1 if source is found in the linked list

1 - Check if 'tmpSource' is not null
2 - Loop which browse all the linked list
3 - Compare value entered by user with 'sourcePath' of each source
4 - Call function which removes the source from the linked list and get 1 if removing succeded
5 - If actual element of the linked list is not the researched one, pick the next in the linked list

**/

int checkSourceExistenceForRemoving(source* firstSource, char* name)
{
	source* tmpSource = firstSource;
	
	/** Step 1 **/
	if(tmpSource)
	{
		/** Step 2 **/
		while(tmpSource)
		{
			/** Step 3 **/
			if(strcmp(tmpSource->sourcePath,name) == 0)
			{
				/** Step 4 **/
				if(removeSource(firstSource,tmpSource))
				{
					return 1;
				}
				
				else
				{
					CLEAR
					printf("\nERROR : cannot delete source file !\n");
					printf("\nPress enter to continue...");
					getchar();
					return 0;
				}
			}
			
			/** Step 5 **/
			tmpSource = tmpSource->nextSource;
		}
		
		CLEAR
		printf("\nERROR : cannot find source file !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
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
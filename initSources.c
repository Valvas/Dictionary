#include "functions.h"

/**

INFO -	This functions is called at start of the program and is no longer used after
		It create the linked list with all sources found in LIST_FILE (constant defined in "functions.h")
		It is called by function "loadSources.c"
		
		It receives two parameters:
		
			- The first source of the linked list (worth NULL at first call)
			- The name of the source to add to the linked list
			
		It returns the new source once created
	
1 - Check if the allocation of the new source succeded, print error message in case of failure and exit program
2 - Allocate memory for 'sourcePath' of the new source
3 - Set 'sourcePath' of the new source the second parameter received by the function
4 - Set the next source of the new source equals to NULL because this new source will be added at the end of the linked list
5 - If 'firstSource' is NULL, just return the new source that will be set 'firstSource' by function "loadSources.c", else execute the content of this if
6 - 'tmpSource' will be used for the next instructions and receives 'firstSource'
7 - Loop that checks if there is a next source for 'tmpSource', at the end of the loop 'tmpSource' will be the last source of the linked list
8 - Set the new source the next source of the last source of the linked list 

	EXAMPLE : 
	
		firstSource -> secondSource -> thirdSource -> tmpSource -> NULL
		firstSource -> secondSource -> thirdSource -> tmpSource -> newSource -> NULL

**/

source* initSources(source* firstSource, char* sourcePath)
{			
	source* newSource = malloc(sizeof(source));
		
	/** Step 1 **/
	if(newSource == NULL)
	{
		CLEAR
		printf("\nERROR : cannot create new source !\n");
		printf("\nPress enter to exit...");
		getchar();
		exit(0);
	}
	
	/** Step 2 **/
	newSource->sourcePath = calloc(NAME_SIZE,sizeof(char));
	
	/** Step 3 **/
	strcpy(newSource->sourcePath,sourcePath);
	
	/** Step 4 **/
	newSource->nextSource = NULL;
	
	/** Step 5 **/
	if(firstSource != NULL)
	{
		/** Step 6 **/
		source* tmpSource = firstSource;
		
		/** Step 7 **/
		while(tmpSource->nextSource != NULL)
		{
			tmpSource = tmpSource->nextSource;
		}
		
		/** Step 8 **/
		tmpSource->nextSource = newSource;
	}
	
	return newSource;
}
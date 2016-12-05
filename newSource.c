#include "functions.h"

/**

INFO -	This function create a new structure source and adds it at the end of the linked list
		It receives two parameters :
		
			- The first source in the linked list
			- The path of the new source to create that will be stored in 'newSource->sourcePath'

		Returns 1 if source is created and 0 if something went wrong
		
1 - Print an error message and exit function if memory allocation for new source failed
2 - Print an error message and exit function if memory allocation for new source path failed
3 - Set the second parameter of the function to 'newSource->sourcePath'
4 - The new source will be added at the end of the linked list so its next source will be null
5 - If there is no sources yet 'firstSource' is null and it will receive the new source
6 - If there is already a first source in the linked list, execute the instructions in the 'else'

	6.1 - Check if 'tmpSource' well received 'firstSource'
		  Temporary source will be used for the following instructions
	6.2 - Loop that browse all the linked list by checking if there is a next source to 'tmpSource' and affects it to 'tmpSource'
		  At the end of the loop 'tmpSource' will be the last source in the linked list
	6.3 - 'tmpSource' is the last source of the linked list, its next source is null, so we set 'newSource' its 'nextSource' instead
	
		EXAMPLE :
		
			- source1 -> source2 -> source3 -> NULL
			- source1 -> source2 -> source3 -> newSource -> NULL
			
	6.4 - Print error message and exit function if the new source is not added at the end of the linked list
	
7 - Return 1 because everything went well
		
**/

int newSource(head* listHead, char* path)
{
	source* newSource = malloc(sizeof(source));
	
	/** Step 1 **/
	if(newSource == NULL)
	{
		CLEAR
		printf("\nERROR : cannot allocate memory for new source !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
	}
	
	newSource->sourcePath = calloc(NAME_SIZE,sizeof(char));
	
	/** Step 2 **/
	if(newSource->sourcePath == NULL)
	{
		CLEAR
		printf("\nERROR : cannot allocate memory for new source !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
	}
	
	/** Step 3 **/
	strcpy(newSource->sourcePath,path);
	
	/** Step 4 **/
	newSource->nextSource = NULL;
	
	/** Step 5 **/
	if(listHead->sourceTarget == NULL)
	{
		listHead->sourceTarget = newSource;
	}
	
	/** Step 6 **/
	else
	{
		source* tmpSource = listHead->sourceTarget;
	
		/** Step 6.1 **/
		if(tmpSource == NULL)
		{
			CLEAR
			printf("\nERROR : cannot create temporary source !\n");
			printf("\nPress enter to continue...");
			getchar();
			return 0;
		}
	
		/** Step 6.2 **/
		while(tmpSource->nextSource)
		{
			tmpSource = tmpSource->nextSource;
		}
		
		/** Step 6.3 **/
		tmpSource->nextSource = newSource;
	
		/** Step 6.4 **/
		if(tmpSource->nextSource == NULL)
		{
			CLEAR
			printf("\nERROR : cannot add new source in the list !\n");
			printf("\nPress enter to continue...");
			getchar();
			return 0;
		}
	}
	
	/** Step 7 **/
	return 1;
}
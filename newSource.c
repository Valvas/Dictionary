#include "functions.h"

/**

INFO -	This function create a new structure source and adds it at the end of the linked list
		It receives two parameters :
		
			- The first source in the linked list
			- The path of the new source to create that will be stored in 'newSource->sourcePath'

		Returns 1 if source is created and 0 if something went wrong
		
**/

int newSource(source* firstSource, char* path)
{
	source* newSource = malloc(sizeof(source));
	
	if(newSource == NULL)
	{
		CLEAR
		printf("\nERROR : cannot allocate memory for new source !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
	}
	
	newSource->sourcePath = calloc(NAME_SIZE,sizeof(char));
	
	if(newSource->sourcePath == NULL)
	{
		CLEAR
		printf("\nERROR : cannot allocate memory for new source !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
	}
	
	strcpy(newSource->sourcePath,path);
	
	newSource->nextSource = NULL;
	
	source* tmpSource = firstSource;
	
	if(tmpSource == NULL)
	{
		CLEAR
		printf("\nERROR : cannot create temporary source !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
	}
	
	while(tmpSource->nextSource)
	{
		tmpSource = tmpSource->nextSource;
	}
	
	tmpSource->nextSource = newSource;
	
	if(tmpSource->nextSource == NULL)
	{
		CLEAR
		printf("\nERROR : cannot add new source in the list !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
	}
	
	return 1;
}
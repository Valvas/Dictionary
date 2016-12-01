#include "functions.h"

source* newSource(source* firstSource, char* sourcePath)
{			
	source* newSource = malloc(sizeof(source));
		
	if(newSource == NULL)
	{
		printf("\nERROR : cannot create new source !\n");
		printf("\nPress enter to exit...");
		getchar();
		exit(0);
	}
	
	newSource->sourcePath = calloc(NAME_SIZE,sizeof(char));
	strcpy(newSource->sourcePath,sourcePath);
	newSource->nextSource = NULL;
	
	if(firstSource != NULL)
	{
		source* tmpSource = malloc(sizeof(source));
		tmpSource->sourcePath = calloc(NAME_SIZE,sizeof(char));
		tmpSource = firstSource;
		
		while(tmpSource->nextSource != NULL)
		{
			tmpSource = tmpSource->nextSource;
		}
		
		tmpSource->nextSource = newSource;
	}
	
	return newSource;
}
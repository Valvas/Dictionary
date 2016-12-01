#include "functions.h"

int checkSourceExistence(source* firstSource, char* name)
{
	source* tmpSource = malloc(sizeof(source));
	tmpSource->sourcePath = calloc(NAME_SIZE,sizeof(char));
	
	if(tmpSource)
	{
		tmpSource = firstSource;
		
		while(tmpSource)
		{
			if(tmpSource->sourcePath == name)
			{
				printf("\nERROR : this source already exists !\n");
				printf("\nPress enter to continue...");
				getchar();
				return 0;
			}
			
			tmpSource = tmpSource->nextSource;
		}
		
		return 1;
	}
	
	else
	{
		printf("\nERROR : cannot create temporary source element !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
	}
}
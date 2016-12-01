#include "functions.h"

int checkSourceExistence(source* firstSource, char* name)
{	
	source* tmpSource = firstSource;
	
	if(tmpSource)
	{		
		while(tmpSource)
		{
			if(strcmp(tmpSource->sourcePath,name) == 0){ printf("|TRUE|\n"); getchar(); }
			else{ printf("|FALSE|\n"); getchar(); }
			tmpSource = tmpSource->nextSource;
		}
	}
	
	else
	{
		printf("\nERROR : cannot create temporary source element !\n");
		printf("\nPress enter to continue...");
		getchar();
		return 0;
	}
}
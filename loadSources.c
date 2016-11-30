#include "functions.h"

/**

INFO -	This function get paths of all source files in LIST_FILE (see constant in "functions.h")

**/

source* loadSources()
{
	char sourcePath[NAME_SIZE];
	char* c;
	
	source* firstSource = NULL;
	source* src = NULL;
	
	FILE* file = NULL;
	
	file = fopen(LIST_FILE,"r");
	
	if(file != NULL)
	{
		while(fgets(sourcePath,NAME_SIZE,file) != NULL)
        {
            if((c = strchr(sourcePath,'\n')) != 0) *c = 0;
			src = newSource(firstSource,sourcePath);
			if(firstSource == NULL) firstSource = src;
        }
		
		fclose(file);
	}
	
	else
	{
		printf("\nERROR : cannot open \"%s\" !\n",LIST_FILE);
		printf("\nPress enter to exit...");
		getchar();
		exit(0);
	}
	
	return firstSource;
}

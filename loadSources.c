#include "functions.h"

/**

INFO -	This function get paths of all source files in LIST_FILE (see constant in "functions.h")
		It returns the first element in the linked list

1 - Create structure source for the first source in the linked list
2 - Open LIST_FILE (constant defined in functions.h) and try to read its content
3 - Get each line in LIST_FILE and create a structure source for each one
4 - Check if file is found at 'sourcePath', can be read and is on good format

**/

source* loadSources()
{
	char sourcePath[NAME_SIZE];
	char* c;
	
	/** Step 1 **/
	source* firstSource = NULL;
	source* src = NULL;
	
	FILE* file = NULL;
	
	/** Step 2 **/
	file = fopen(LIST_FILE,"r");
	
	if(file != NULL)
	{
		/** Step 3 **/
		while(fgets(sourcePath,NAME_SIZE,file) != NULL)
        {
            /** Step 4 **/
			if(checkFile(sourcePath))
			{
				if((c = strchr(sourcePath,'\n')) != 0) *c = 0;
				src = newSource(firstSource,sourcePath);
				if(firstSource == NULL) firstSource = src;
			}
        }
		/** End of Step 3 **/
		
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

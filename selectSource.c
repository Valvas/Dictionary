#include "functions.h"

/**

INFO -	Return the name of the source entered by the user

1 - Loop that executes while user's entry is invalid
2 - Print the list of all sources
3 - Clear the array 'name' that will receive user's entry
4 - Get user's entry
5 - Check if file exists and can be read

**/

void selectSource(head* listHead, char* sourcePath)
{
	int run = 1, count;
	
	/** Step 1 **/
	while(run)
	{
		count = 1;
		
		CLEAR
		
		/** Step 2 **/
		printf("======================================================================\n\n");
		
		showSources(listHead->sourceTarget,&count);
		
		printf("\n======================================================================\n");
		/** End of Step 2 **/
		
		printf("\nEnter the name of the source you want to select (with path) : ");
		
		/** Step 3 **/
		sourcePath[0] = '\0';
		
		/** Step 4 **/
		entry(sourcePath,NAME_SIZE);
		
		FILE* file = NULL;
		
		/** Step 5 **/
		file = fopen(sourcePath,"r");
		
		if(file != NULL)
		{
			fclose(file);
			
			run = 0;
		}
		
		else
		{
			CLEAR
			printf("\nERROR : cannot open \"%s\", file may be unavaible, check your entry !\n");
			printf("\nPress enter to continue...");
			getchar();
		}
	}
}
#include "functions.h"

/**



**/

void addWord(char* sourcePath)
{
	int run = 1, size = 3;
	long choice = 0;
	
	while(run)
	{
		while(choice < 1 || choice > 2)
		{
			CLEAR
			
			printf("======================================================================\n");
			printf("\n1. Enter new word");
			printf("\n2. Back");
			
			choice = integer(size);
			
			if(choice == 1)
			{
				FILE* file = NULL;
				
				file = fopen(sourcePath,"a");
				
				if(file != NULL)
				{
					//char title[TITLE] = getTitle();
					//char definition[DEFINITION] = getDefinition();
					//char origin[ORIGIN] = getOrigin();
					
					fclose(file);
				}
				
				else
				{
					printf("\nERROR : cannot open \"%s\" !\n",sourcePath);
					printf("\nPress enter to continue...");
					getchar();
					
					run = 0;
				}
			}
			
			else if(choice == 2)
			{
				run = 0;
			}
		}
	}
}
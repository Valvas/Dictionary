#include "functions.h"

/**

INFO -	This function gets the content of the source file given in parameter of the function and call "getWord.c" for each line of the source file

1 - Open the source file in read-only mode
2 - Loop that get each line of the source file content and call "getWord.c" for each of them

**/

void readSource(primary* firstWord, char* name)
{
	int j = 0, k = 0, percent = 0;
	
	long size = 0, i = 0;
	
	FILE* file = NULL;
	
	/** Step 1 **/
	file = fopen(name,"r");
				
	if(file != NULL)
	{	
		char wordContent[DEFINITION];
		
		while(fgets(wordContent,DEFINITION,file) != NULL)
		{
			size++;
		}
		
		rewind(file);
					
		/** Step 2 **/
		while(fgets(wordContent,DEFINITION,file) != NULL)
		{
			if(wordContent[strlen(wordContent) - 1] == '\n') wordContent[strlen(wordContent) - 1] = '\0';
			createWord(firstWord,wordContent);
			i++;
			
			if((((i * 100)/size) == percent) && percent < 101)
			{
				percent++;
				CLEAR
				printf("[");
				for(j = 0; j < percent; j++)
				{
					printf("=");
				}
			
				for(k = percent; k < 100; k++)
				{
					printf(" ");
				}
				printf("] - %d%%", percent);
			}
		}
		
		fclose(file);
	}
				
	else
	{
		printf("\nERROR : cannot read \"%s\" !\n",name);
		printf("\nPress enter to continue...");
		getchar();
	}
}
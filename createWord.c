#include "functions.h"

/**

NEW FUNCTION / DESCRIPTION NOT SET YET

**/

void createWord(primary* firstWord, char* title, char* definition, char* origin)
{
	word* newWord = malloc(sizeof(word));
	
	if(newWord)
	{
		newWord->title = calloc(TITLE,sizeof(char));
		newWord->definition = calloc(DEFINITION,sizeof(char));
		newWord->origin = calloc(ORIGIN,sizeof(char));
		
		strcpy(newWord->title,title);
		strcpy(newWord->definition,definition);
		strcpy(newWord->origin,origin);
		
		newWord->nextWord = NULL;
		
		if(firstWord->wordTarget == NULL)
		{
			firstWord->wordTarget = newWord;
		}
		
		else
		{
			word* tmpWord = firstWord->wordTarget;
			
			if(tmpWord != NULL)
			{
				while(tmpWord)
				{
					tmpWord = tmpWord->nextWord;
				}
			}
			
			else
			{
				printf("\nERROR : cannot allocate memory for new structure word !\n");
				printf("\nPress enter to exit...");
				exit(0);
			}
		}
	}
	
	else
	{
		printf("\nERROR : cannot allocate memory for new structure word !\n");
		printf("\nPress enter to exit...");
		exit(0);
	}
}
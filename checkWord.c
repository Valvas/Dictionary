#include "functions.h"

/**



**/

int checkWord(primary* firstWord, char* word, char* correctedWord)
{
	word* tmpWord = firstWord->wordTarget;
	
	if(tmpWord)
	{
		while(tmpWord)
		{
			if(strlen(tmpWord->title) < strlen(word))
			{
				for(int i = 0; i < strlen(tmpWord->title); i++)
				{
					
				}
			}
			
			else if(strlen(tmpWord->title > strlen(word))
			{
				
			}
			
			tmpWord = tmpWord->nextWord;
		}
	}
	
	else
	{
		printf("\nERROR : cannot create temporary element !\n");
		printf("\nPress enter to exit...");
		getchar();
		exit(0);
	}
}
#include "functions.h"

/**



**/

int checkWord(primary* firstWord, char* word, char* correctedWord)
{
	word* tmpWord = firstWord->wordTarget;
	
	int count;
	
	if(tmpWord)
	{
		while(tmpWord)
		{
			count = 0;
			
			if(strlen(tmpWord->title) < strlen(word))
			{
				count = strlen(word) - strlen(tmpWord->title);
				
				for(int i = 0; i < strlen(tmpWord->title); i++)
				{
					if(tmpWord->title[i] != word[i])
					{
						count++;
					}
				}
			}
			
			else if(strlen(tmpWord->title) > strlen(word))
			{
				count = strlen(tmpWord->title) - strlen(word);
				
				for(int j = 0; j < strlen(word); j++)
				{
					if(tmpWord->title[j] != word[j])
					{
						count++;
					}
				}
			}
			
			else
			{
				for(int k = 0; k < strlen(word); k++)
				{
					if(tmpWord->title[k] != word[k])
					{
						count++;
					}
				}
			}
			
			if(count <= 1)
			{
				strcpy(correctedWord,tmpWord->title);
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
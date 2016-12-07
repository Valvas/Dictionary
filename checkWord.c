#include "functions.h"

/**

INFO -	Check if word sent in parameter resemble a word in the dictionnary to one character and return this word in correction proposition

1 - Create a temporary word in order to browse the word linked list and compare each one with the word sent in parameter
2 - Execute loop for each word in the dictionary
3 - 'count' is used to count the number of differences between the word sent in parameter and each word in the dictionary
	It must be set to 0 at the beginning of the loop because we need to compare differences for each word
4 - Execute if the lengh of the word sent in parameter is longer than the word from the dictionary

	4.1 -
	4.2 -
	4.3 -
	
5 - Execute if the lengh of the word sent in parameter is shorter than the word from the dictionary

	5.1 -
	5.2 -
	5.3 -
	
6 - Execute if the two words have the same lengh

	6.1 - Loop to browse the two words in order to compare their characters
	6.2 - For each character of the two words, if they are different we increment 'count' to get the total of differences between the words
	
7 - Once checks are over with the words execute only if there is one difference between them

	7.1 - Copy the word of the dictionary into 'correctedWord' that will be used in "readDocument.c" to replace the old word in the document
	7.2 - Return 1 to "readDocument.c" to specify to use 'correctedWord' instead of the original word in the rewriting of the document
	
8 - Get the next word of the dictionary and execute the loop again

**/

int checkWord(primary* firstWord, char* wordToCheck, char* correctedWord)
{
	/** Step 1 **/
	word* tmpWord = firstWord->wordTarget;
	
	int count;
	
	if(tmpWord)
	{
		/** Step 2 **/
		while(tmpWord)
		{
			
			/** Step 3 **/
			count = 0;
			
			/** Step 4 **/
			if(strlen(tmpWord->title) < strlen(wordToCheck))
			{		
				count = strlen(wordToCheck) - strlen(tmpWord->title);
				
				for(int i = 0; i < strlen(tmpWord->title); i++)
				{
					if(tmpWord->title[i] != wordToCheck[i])
					{
						count++;
					}
				}
			}
			
			/** Step 5 **/
			else if(strlen(tmpWord->title) > strlen(wordToCheck))
			{			
				count = strlen(tmpWord->title) - strlen(wordToCheck);
				
				for(int j = 0; j < strlen(wordToCheck); j++)
				{
					if(tmpWord->title[j] != wordToCheck[j])
					{
						count++;
					}
				}
			}
			
			/** Step 6 **/
			else
			{
				/** Step 6.1 **/
				for(int k = 0; k < strlen(wordToCheck); k++)
				{
					/** Step 6.2 **/
					if(wordToCheck[k] != tmpWord->title[k])
					{
						count++;
					}
				}
			}
			
			/** Step 7 **/
			if(count == 1)
			{
				/** Step 7.1 **/
				strcpy(correctedWord,tmpWord->title);
				
				/** Step 7.2 **/
				return 1;
			}
			
			/** Step 8 **/
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
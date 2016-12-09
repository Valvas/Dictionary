#include "functions.h"

/**

INFO -	Check if word sent in parameter resemble a word in the dictionnary to one character and return this word in correction proposition

1 - Create a temporary word in order to browse the word linked list and compare each one with the word sent in parameter
2 - Words in the dictionary are in lowercase, we put the entire word to check in lowercase else comparison will not word ('Test' != 'test')
3 - Execute loop for each word in the dictionary
4 - 'count' is used to count the number of differences between the word sent in parameter and each word in the dictionary
	It must be set to 0 at the beginning of the loop because we need to compare differences for each word
5 - Execute if the lengh of the word sent in parameter is longer than the word from the dictionary

	5.1 - Get the difference of lengh between the two words
	5.2 - Execute the loop for each character of the shortest word
	5.3 - Increment 'count' for each different character in each word
	
		EXAMPLE : compare 'progress' and 'program', 'count' is going to worth 3 because 'program' is one character less than 'progress' and the two end
				  characters of 'program' are different from 'progress'
	
6 - Execute if the lengh of the word sent in parameter is shorter than the word from the dictionary

	6.1 - Get the difference of lengh between the two words
	6.2 - Execute the loop for each character of the shortest word
	6.3 - Increment 'count' for each different character in each word
	
7 - Execute if the two words have the same lengh

	7.1 - Loop to browse the two words in order to compare their characters
	7.2 - For each character of the two words, if they are different we increment 'count' to get the total of differences between the words
	
8 - Once checks are over with the words execute only if there is one difference between them

	8.1 - Copy the word of the dictionary into 'correctedWord' that will be used in "readDocument.c" to replace the old word in the document
	8.2 - Return 1 to "readDocument.c" to specify to use 'correctedWord' instead of the original word in the rewriting of the document
	
9 - If the two words are the same the function returns 0 to indicate that the word exists in the dictionary but there are no spelling mistakes
10 - Get the next word of the dictionary and execute the loop again

**/

int checkWord(primary* firstWord, char* wordToCheck, char* correctedWord)
{
	/** Step 1 **/
	word* tmpWord = firstWord->wordTarget;
	
	if(strlen(wordToCheck) == 0)
	{
		return 3;
	}
	
	/** Step 2 **/
	for(int i = 0; i < strlen(wordToCheck); i++)
	{
		if(wordToCheck[i] > 64 && wordToCheck[i] < 91)
		{
			wordToCheck[i] += 32;
		}
	}
	
	int count;
	
	if(tmpWord)
	{
		/** Step 3 **/
		while(tmpWord)
		{
			
			/** Step 4 **/
			count = 0;
			
			/** Step 5 **/
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
			
			/** Step 6 **/
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
			
			/** Step 7 **/
			else
			{
				/** Step 7.1 **/
				for(int k = 0; k < strlen(wordToCheck); k++)
				{
					/** Step 7.2 **/
					if(wordToCheck[k] != tmpWord->title[k])
					{
						count++;
					}
				}
			}
			
			/** Step 8 **/
			if(count == 1)
			{
				/** Step 8.1 **/
				strcpy(correctedWord,tmpWord->title);
				
				/** Step 8.2 **/
				return 1;
			}
			
			/** Step 9 **/
			else if(count == 0)
			{
				return 2;
			}
			
			/** Step 10 **/
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
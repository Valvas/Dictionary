#include "functions.h"

/**

INFO -	Browse all words in the linked list and print word corresponding to user's research

1 - Get user's research
2 - Loop to browse all the word linked list
3 - Execute these instructions if the lengh of the word is over user's research lengh

	3.1 - Increment 'wordDiff' with lengh difference between the word and the research
	3.2 - Browse the word and the research and increment 'wordDiff' each time characters are differents
	
4 - Execute these instructions if user's research lengh is over the lengh of the word

	4.1 - Increment 'wordDiff' with lengh difference between the word and the research
	4.2 - Browse the word and the research and increment 'wordDiff' each time characters are differents
	
5 - If the two words have the same lengh we just check character differences between them
6 - Check if differences between user's research and words is not over LIMIT (constant defined in "functions.h")
7 - Print word if it corresponds to user's research
8 - Increment 'count' each time a word is found by the research in order to know is there is a result or not
9 - Select the next word in the linked list in order to execute the loop again
10 - If 'count' worth 0 it means that there is no result for the research

**/

void searchWord(word* wrd)
{
	char value[NAME_SIZE];
	
	int count = 0, wordDiff = 0, check = 0, i = 0, j = 0;
	
	CLEAR
	
	printf("\nEnter you research : ");
	
	/** Step 1 **/
	entry(value,NAME_SIZE);
	
	CLEAR
	
	/** Step 2 **/
	while(wrd)
	{
		wordDiff = 0;
		
		/** Step 3 **/
		if(strlen(wrd->title) > strlen(value))
		{
			/** Step 3.1 **/
			wordDiff = strlen(wrd->title) - strlen(value);
			
			/** Step 3.2 **/
			for(i = 0; i < strlen(value); i++)
			{
				if(value[i] != wrd->title[i])
				{
					wordDiff++;
				}
			}
		}
		
		/** Step 4 **/
		else if(strlen(wrd->title) < strlen(value))
		{
			/** Step 4.1 **/
			wordDiff = strlen(value) - strlen(wrd->title);
			
			/** Step 4.2 **/
			for(j = 0; j < strlen(wrd->title); j++)
			{
				if(value[j] != wrd->title[j])
				{
					wordDiff++;
				}
			}
		}

		/** Step 5 **/
		else
		{
			for(j = 0; j < strlen(wrd->title); j++)
			{
				if(value[j] != wrd->title[j])
				{
					wordDiff++;
				}
			}
		}
		
		/** Step 6 **/
		if(wordDiff <= LIMIT)
		{
			/** Step 7 **/
			printf("\n%s :\n",wrd->title);
			printf("\n%s\n",wrd->definition);
			printf("\n%s\n",wrd->origin);
			printf("\n======================================================================\n");
			
			/** Step 8 **/
			count++;
		}
		
		/** Step 9 **/
		wrd = wrd->nextWord;
	}
	
	/** Step 10 **/
	if(count == 0)
	{
		printf("There is no result for \"%s\" !\n",value);
	}
	
	printf("\nPress enter to continue...");
	getchar();
}
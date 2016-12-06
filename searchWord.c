#include "functions.h"

/**

INFO -	Browse all words in the linked list and print word corresponding to user's research

1 - Get user's research
2 - Loop to browse all the word linked list
3 - Check if user's research is equal to the selected word at each execution of the loop
4 - Print word if it corresponds to user's research
5 - Increment 'count' each time a word is found by the research in order to know is there is a result or not
6 - Select the next word in the linked list in order to execute the loop again
7 - If 'count' worth 0 it means that there is no result for the research

**/

void searchWord(word* wrd)
{
	char value[NAME_SIZE];
	
	int count = 0, lenghDiff = 0, check = 0;
	
	CLEAR
	
	printf("\nEnter you research : ");
	
	/** Step 1 **/
	entry(value,NAME_SIZE);
	
	CLEAR
	
	/** Step 2 **/
	while(wrd)
	{
		if(strlen(wrd->title) > strlen(value))
		{
			lenghDiff = strlen(wrd->title) - strlen(value);
		}
		
		check = lenghDiff;
		
		
		
		/** Step 3 **/
		if(strcmp(wrd->title,value) == 0)
		{
			/** Step 4 **/
			printf("\n%s :\n",wrd->title);
			printf("\n%s\n",wrd->definition);
			printf("\n%s\n",wrd->origin);
			printf("\n======================================================================\n");
			
			/** Step 5 **/
			count++;
		}
		
		/** Step 6 **/
		wrd = wrd->nextWord;
	}
	
	/** Step 7 **/
	if(count == 0)
	{
		printf("There is no result for \"%s\" !\n",value);
	}
	
	printf("\nPress enter to continue...");
	getchar();
}
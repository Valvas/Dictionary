#include "functions.h"

/**

INFO -	Browse all words in the linked list and print word corresponding to user's research

1 - Get user's research
2 - Loop to browse all the word linked list
3 - If current word is equal to user's entry print the result
4 - Select the next word in the linked list and execute the loop again	
5 - Printed if there is no result for the research

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
		/** Step 3 **/
		if(strcmp(wrd->title,value) == 0)
		{
			printf("Search found in the dictionary : %s",value);
			printf("\n\nPress enter to continue...");
			getchar();
			return;
		}
		
		/** Step 4 **/
		wrd = wrd->nextWord;
	}
	
	/** Step 5 **/
	printf("There is no result for \"%s\" !\n",value);
	
	printf("\nPress enter to continue...");
	getchar();
}
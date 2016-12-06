#include "functions.h"

/**

INFO -	This function prints the content of each structure 'word' while structure 'word' given in parameter is not null
		It is a recursive function

1 - Check if 'word' given in parameter is not null
2 - Print the elements of 'word'
3 - Call this function by giving it the next word in the linked list as parameter

**/

void printWord(word* wrd)
{
	/** Step 1 **/
	if(wrd)
	{
		/** Step 2 **/
		printf("\n======================================================================\n");
		printf("\n%s :\n",wrd->title);
		printf("\n%s\n",wrd->definition);
		printf("\n%s\n",wrd->origin);
		
		/** Step 3 **/
		printWord(wrd->nextWord);
	}
}
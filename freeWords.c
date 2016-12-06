#include "functions.h"

/**

INFO -	Free memory allocation for each element of the word linked list

**/

void freeWords(word* wrd)
{
	if(wrd->nextWord)
	{
		freeWords(wrd->nextWord);
	}
	
	free(wrd);
}
#include "functions.h"

/**

INFO -	Free memory allocation for each element of the word linked list

**/

void freeWords(word* wrd)
{
	word* tmp;
	
	while(wrd != NULL)
	{
		tmp = wrd;
		wrd = wrd->nextWord;
		free(tmp);
	}
}
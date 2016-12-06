#include "functions.h"

/**



**/

void printWord(word* wrd)
{
	if(wrd)
	{
		printf("\n======================================================================\n");
		printf("\n%s :\n",wrd->title);
		printf("\n%s\n",wrd->definition);
		printf("\n%s\n",wrd->origin);
		
		printWord(wrd->nextWord);
	}
}
#include "functions.h"

/**

INFO -	Free memory allocation for each element of the source linked list

**/

void freeSources(source* src)
{
	if(src->nextSource)
	{
		freeSources(src->nextSource);
	}
	
	free(src);
}
#include "functions.h"

void showSources(source* src)
{
	if(src)
	{
		printf("Source path : %s\n",src->sourcePath);
		showSources(src->nextSource);
	}
}
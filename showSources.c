#include "functions.h"

/**

INFO -	This functions shows the path with the name of each source file
		It is a recursive function
		
1 - Check if the received element of the linked list is not null
2 - Print the path with the name of this element
3 - Call this function by sending the next element in the linked list

**/

void showSources(source* src, int* count)
{
	/** Step 1 **/
	if(src)
	{
		/** Step 2 **/
		printf("Source %d : %s\n",*count,src->sourcePath);
		
		*count += 1;
		
		/** Step 3 **/
		showSources(src->nextSource,count);
	}
}
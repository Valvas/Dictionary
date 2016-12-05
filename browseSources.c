#include "functions.h"

/**

INFO -	This function reads the content of each source files and get its content before sending it to "getWord.c" that will create a structure 'word' for each line of the file

1 - Check if there is at least one source
2 - Loop that will execute for each source file (at end of the loop replace 'tmpSource' by the next source in the linked list)
3 - Call "readSource.c" that will browse the source file and get its content

**/

void browseSources(head* listHead, primary* firstWord)
{
	/** Step 1 **/
	if(listHead->sourceTarget)
	{
		source* tmpSource = listHead->sourceTarget;
		
		FILE* file = NULL;
		
		if(tmpSource)
		{
			/** Step 2 **/
			while(tmpSource)
			{						
				/** Step 3 **/
				readSource(firstWord,tmpSource->sourcePath);
				
				tmpSource = tmpSource->nextSource;
			}
		}
		
		else
		{
			printf("\nERROR : cannot create temporary source element !\n");
			printf("\nPress enter to exit...");
			getchar();
			exit(0);
		}
	}
}
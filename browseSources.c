#include "functions.h"

/**

INFO -	This function reads the content of each source files and get its content before sending it to "getWord.c" that will create a structure 'word' for each line of the file

1 - Check if there is at least one source
2 - Loop that will execute for each source file (at end of the loop replace 'tmpSource' by the next source in the linked list)
3 - Open source file in read-only mode
4 - Loop that get each line of the source file and send it to "getWord.c" in order to create a structure 'word' for each line
5 - Call "getWord.c" that will separate content of each line in word, definition and source and create a structure 'word' with these elements

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
				file = fopen(tmpSource->sourcePath,"r");
				
				if(file != NULL)
				{
					char wordContent[DEFINITION];
					
					/** Step 4 **/
					while(fgets(wordContent,DEFINITION,file) != NULL)
					{
						/** Step 5 **/
						getWord(firstWord,wordContent);
					}
				}
				
				else
				{
					printf("\nERROR : cannot read \"%s\" !\n",tmpSource->sourcePath);
					printf("\nPress enter to continue...");
					getchar();
				}
				
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
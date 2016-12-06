#include "functions.h"

/**

INFO -	This function gets the content of the source file given in parameter of the function and call "getWord.c" for each line of the source file

1 - Open the source file in read-only mode
2 - Loop that get each line of the source file content and call "getWord.c" for each of them

**/

void readSource(primary* firstWord, char* name)
{
	FILE* file = NULL;
	
	/** Step 1 **/
	file = fopen(name,"r");
				
	if(file != NULL)
	{
		char wordContent[DEFINITION];
					
		/** Step 2 **/
		while(fgets(wordContent,DEFINITION,file) != NULL)
		{
			getWord(firstWord,wordContent);
		}
	}
				
	else
	{
		printf("\nERROR : cannot read \"%s\" !\n",name);
		printf("\nPress enter to continue...");
		getchar();
	}
}
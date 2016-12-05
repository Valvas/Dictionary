#include "functions.h"

/**



**/

void browseSources(head* listHead)
{
	if(listHead->sourceTarget)
	{
		source* tmpSource = listHead->sourceTarget;
		
		FILE* file = NULL;
		
		if(tmpSource)
		{
			while(tmpSource)
			{			
				file = fopen(tmpSource->sourcePath,"r");
				
				if(file != NULL)
				{
					char wordContent[WORD_CONTENT];
					
					while(fgets(wordContent,WORD_CONTENT,file) != NULL)
					{
						//CALL FUNCTION TO GET WORD, DEFINITION AND SOURCE BY CREATING STRUCTURES 'WORD'
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
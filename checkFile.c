#include "functions.h"

/**

INFO - This function calls other functions all in format_source.c

**/

int checkFile(char* name)
{
    /** Step 1 **/
    FILE* file = NULL;

    int c = 0, p = 0, i = 0, k = 0, size = 0;

    file = fopen(name,"r");
	
	char content[getFileSize(file)];
	
	size = getFileSize(file);

    if(file != NULL)
    {	
		for(k = 0; k < size; k++)
		{
			c = fgetc(file);
			
			if(p == '\n' && c == '\n'){}
			
			else
			{
				p = c;
				if((c != ' ' && ((c > 64 && c < 91) || (c > 96 && c < 123))) || c == '\n')
				{
					if(c > 64 && c < 91)
					{
						c += 32;
					}
					
					content[i] = c;
					i++;
				}
			}
		}
		
		content[i] = '\0';
		
		fclose(file);
    }

    /** IF FILE CAN NOT BE OPENED **/
    else
    {
        CLEAR
		printf("\nERROR : cannot open \"%s\" !\n",name);
        printf("\nPress enter to continue...");
        getchar();
		return 0;
    }
	
	file = fopen(name,"w+");
	
	if(file != NULL)
	{
		fprintf(file,"%s",content);
		fclose(file);
		return 1;
	}
	
	/** IF FILE CAN NOT BE OPENED **/
    else
    {
        CLEAR
		printf("\nERROR : cannot open \"%s\" !\n",name);
        printf("\nPress enter to continue...");
        getchar();
		return 0;
    }
}

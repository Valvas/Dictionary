#include "functions.h"

/**

INFO -	Ask the user if he wants to replace the content of the document given in parameter with the content given in parameter

1 - Execute the loop that shows the menu while the user does not choose one of the proposition
2 - Get the user's choice
3 - Execute if user has chosen to write 'content' in the document

	3.1 - Open the document and erase all its content
	3.2 - Write 'content' in the empty document
	3.3 - Print a confirmation for user
	
4 - Execute if user has choses to not replace the content of the document

	4.1 - Print a confirmation of the user's choice

**/

void replaceContent(char* path, char* content)
{
	int size = 3;
	long choice = 0;
	
	/** Step 1 **/
	while(choice < 1 || choice > 2)
	{
		/** Step 2 **/
		CLEAR
		printf("Do you want to rewrite the content of the document with the corrections ?\n");
		printf("\n1. Yes");
		printf("\n2. No");
		printf("\n\nYour choice : ");
		
		choice = integer(size);
		
		/** Step 3 **/
		if(choice == 1)
		{
			FILE* file = NULL;
			
			/** Step 3.1 **/
			file = fopen(path,"w+");
			
			if(file != NULL)
			{
				/** Step 3.2 **/
				fprintf(file,"%s",content);
				fclose(file);
				
				/** Step 3.3 **/
				CLEAR
				printf("\nSUCCESS : modifications applied in \"%s\" !\n",path);
				printf("\nPress enter to continue...");
				getchar();
			}
			
			else
			{
				CLEAR
				printf("\nERROR : cannot open \"%s\" !\n",path);
				printf("\nPress enter to continue...");
				getchar();
			}
		}
		
		/** Step 4 **/
		else if(choice == 2)
		{
			/** Step 4.1 **/
			CLEAR
			printf("Content not modified !\n");
			printf("\nPress enter to continue...");
			getchar();
		}
	}
}
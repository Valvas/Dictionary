#include "functions.h"

/**

INFO -	Create a source file in the folder 'sources' from the program root folder and create a structure 'source' for it

1 - Get the name of the new source file to create
2 - Check if the value entered is not null
3 - Get the value of the path to the sources folder in 'path'
4 - Make sure there will not be unexpected characters at the end of 'path'
5 - Concatenate 'path' with 'name'

	EXAMPLE : 'path' = 'sources/', 'name' = 'test.txt', concat = 'sources/test.txt'
	
6 - Check if file does not already exists
7 - Create the new source file by using the path of the concat just above
8 - Create a new structure 'source' in the program for this new source
9 - Add this new source in LIST_FILE (constant defined in "functions.h")
10 - Loop that print a menu to ask user if he wants to add words in the new source file
11 - If user wants to add words in the source file the function calls "addWord.c", else he will be send back to the sources management menu

**/

void createSource(head* listHead, primary* firstWord)
{
	char name[NAME_SIZE];
	char path[NAME_SIZE];
	
	CLEAR
	
	printf("======================================================================\n");
	printf("Enter the name of the source to create (without path) : ");
	
	/** Step 1 **/
	entry(name,NAME_SIZE);
	
	/** Step 2 **/
	if(strlen(name) > 0)
	{
		/** Step 3 **/
		strcpy(path,SOURCE_FOLDER_PATH);
	
		/** Step 4 **/
		path[strlen(path)] = '\0';
	
		/** step 5 **/
		strcat(path,name);
		
		FILE* file = NULL;
		
		/** Step 6 **/
		file = fopen(path,"r");
		
		if(file != NULL)
		{
			CLEAR
			printf("\nERROR : this file already exists !\n");
			printf("\nPress enter to continue...");
			getchar();
			fclose(file);
			return;
		}
		
		/** Step 7 **/
		file = fopen(path,"w+");
		
		if(file != NULL)
		{
			/** Step 8 **/
			if(newSource(listHead,path))
			{
				/** Step 9 **/
				if(addSourceInList(path))
				{
					printf("\nSUCCESS : file \"%s\" created !\n",path);
					printf("\nPress enter to continue...");
					getchar();
			
					int size = 3;
					long choice = 0;
			
					/** Step 10 **/
					while(choice < 1 || choice > 2)
					{
						CLEAR
			
						printf("======================================================================\n");
						printf("Do you want to add words in the new source file ?\n");
						printf("\n1. Yes");
						printf("\n2. No");
						printf("\n\nYour choice : ");
				
						choice = integer(size);
				
						/** Step 11 **/
						if(choice == 1)
						{
							addWord(firstWord,path);
						}
					}
				}
				
				else
				{
					printf("\nERROR : cannot add source in \"%s\", source will not be loaded at next program's start !\n",LIST_FILE);
					printf("\nPress enter to continue...");
					getchar();
				}
			}
			
			else
			{
				printf("\nERROR : cannot create new element source !\n");
				printf("\nPress enter to exit...");
				exit(0);
			}
			
			fclose(file);
		}
		
		else
		{
			printf("\nERROR : cannot create \"%s\" !\n",path);
			printf("\nPress enter to continue...");
			getchar();
		}
	}
	
	else
	{
		printf("\nERROR : null value entered !\n");
		printf("\nPress enter to continue...");
		getchar();
	}
}
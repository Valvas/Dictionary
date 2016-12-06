#include "functions.h"

/**



**/

void addWord(primary* firstWord, char* sourcePath)
{
	int run = 1, size = 3;
	long choice = 0;
	
	while(run)
	{
		while(choice < 1 || choice > 2)
		{
			CLEAR
			
			printf("======================================================================\n");
			printf("\n1. Enter new word");
			printf("\n2. Back");
			
			printf("\n\nYour choice : ");
			
			choice = integer(size);
			
			if(choice == 1)
			{
				FILE* file = NULL;
				
				file = fopen(sourcePath,"a");
				
				if(file != NULL)
				{
					char title[TITLE];
					char definition[DEFINITION];
					char origin[ORIGIN];
					
					title[0] = '\0';
					definition[0] = '\0';
					origin[0] = '\0';
					
					if(getTitle(title))
					{
						if(getDefinition(definition))
						{
							if(getOrigin(origin))
							{
								char word[DEFINITION];
								
								strcat(word,title);
								strcat(word,";");
								strcat(word,definition);
								strcat(word,";");
								strcat(word,origin);
								
								createWord(firstWord,title,definition,origin);
								insertWordInSource(sourcePath,word);
							}
						}
					}
					
					fclose(file);
				}
				
				else
				{
					printf("\nERROR : cannot open \"%s\" !\n",sourcePath);
					printf("\nPress enter to continue...");
					getchar();
					
					run = 0;
				}
				
				choice = 0;
			}
			
			else if(choice == 2)
			{
				run = 0;
			}
		}
	}
}

//************************************************************************************************************************************************************************//

int getTitle(char* title)
{
	while(strlen(title) < 2)
	{
		CLEAR
		printf("======================================================================\n");
		printf("\nEnter the word to add : ");
		
		entry(title,TITLE);
		
		if(strlen(title) < 2)
		{
			CLEAR
			printf("\nERROR : \"%s\" cannot be a word !\n",title);
			printf("\nPress enter to continue...");
			getchar();
		}
	}
	
	return 1;
}

//************************************************************************************************************************************************************************//

int getDefinition(char* definition)
{
	while(strlen(definition) < 10)
	{
		CLEAR
		printf("======================================================================\n");
		printf("\nEnter the definition for this word :\n\n");
		
		entry(definition,DEFINITION);
		
		if(strlen(definition) < 10)
		{
			CLEAR
			printf("\nERROR : \"%s\" cannot be a definition !\n",definition);
			printf("\nPress enter to continue...");
			getchar();
		}
	}
	
	return 1;
}

//************************************************************************************************************************************************************************//

int getOrigin(char* origin)
{
	while(strlen(origin) < 2)
	{
		CLEAR
		printf("======================================================================\n");
		printf("\nEnter the source for this word :\n\n");
		
		entry(origin,ORIGIN);
		
		if(strlen(origin) < 2)
		{
			CLEAR
			printf("\nERROR : \"%s\" cannot be a source !\n",origin);
			printf("\nPress enter to continue...");
			getchar();
		}
	}
	
	return 1;
}
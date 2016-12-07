#include "functions.h"

/**



**/

void readDocument(primary* firstWord)
{
	char document[NAME_SIZE];
	char path[NAME_SIZE];
	char c;
	
	strcpy(path,DOCUMENT_FOLDER_PATH);
	
	CLEAR
	
	printf("WARNING - All documents must be placed in folder \"%s\" from root directory !\n",path);
	printf("\nEnter the name of your document (with extension and without path) : ");
	
	entry(document,NAME_SIZE);
	
	CLEAR
	
	strcat(path,document);
	
	FILE* file = NULL;
	
	file = fopen(path,"r");
	
	if(file != NULL)
	{
		printf("\nDocument before correction :");
		printf("\n================================================================================\n\n");
		
		while((c = fgetc(file)) != EOF)
		{
			printf("%c",c);
		}

		printf("\n\n================================================================================\n\n");
		
		fclose(file);
	}
	
	file = fopen(path,"r");
	
	if(file != NULL)
	{
		char word[NAME_SIZE];
		char correctedWord[NAME_SIZE];
		int i = 0, line = 0, position = 1;
		
		while((c = fgetc(file) != EOF)
		{
			if(c == '\n' || c == 32)
			{
				if(c == '\n')
				{
					line++;
					position = 1;
				}
				
				if(c == 32)
				{
					position++;
				}
				
				word[i] = '\0';
				i = 0;
				
				if(checkWord(firstWord,word,correctedWord))
				{
					printf("\nWARNING - Line %d Position %d - %s -> %s",line,position,word,correctedWord);
				}
			}
			
			else
			{
				word[i] = c;
				i++;
			}
		}
		fclose(file);
	}
	
	else
	{
		printf("\nERROR : cannot open \"%s\" !\n",path);
		printf("\nPress enter to continue...");
		getchar();
		return;
	}
}
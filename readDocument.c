#include "functions.h"

/**

INFO -	Read the document, get each word and call "checkWord.c" to verify if the word exists in the dictionary and if it can be corrected

1 - Open document in read-only mode in order to print the content of the file before correcting it

	1.1 - Print each character of the file while we do not reach the end of the file
	1.2 - Put the cursor at the beginning of the file for next steps

**/

void readDocument(primary* firstWord, char* path)
{	
	char c;
	
	FILE* file = NULL;
	
	/** Step 1 **/
	file = fopen(path,"r");
	
	if(file != NULL)
	{
		printf("\nDocument before correction :");
		printf("\n================================================================================\n\n");
		
		/** Step 1.1 **/
		while((c = fgetc(file)) != EOF)
		{
			printf("%c",c);
		}

		printf("\n\n================================================================================\n\n");
		
		/** Step 1.2 **/
		rewind(file);
		
		char content[getFileSize(file) + 100];
		
		content[0] = '\0';
		
		char word[NAME_SIZE];
		char correctedWord[NAME_SIZE];
		int i = 0, j = 0, k = 0, line = 1, position = 0;
		
		while((c = fgetc(file)) != EOF)
		{
			if(c == '\n' || c == 32)
			{
				if(c == '\n')
				{
					line++;
					position = 0;
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
					
					for(j = 0; j < strlen(correctedWord); j++)
					{
						content[k] = correctedWord[j];
						k++;
					}
				}
				
				else
				{
					for(j = 0; j < strlen(word); j++)
					{
						content[k] = word[j];
						k++;
					}
				}
				
				if(c == '\n')
				{
					content[k] = '\n';
					k++;
				}
				
				if(c == 32)
				{
					content[k] = 32;
					k++;
				}
			}
			
			else
			{
				word[i] = c;
				i++;
			}
		}
		
		word[i] = '\0';
		
		if(checkWord(firstWord,word,correctedWord))
		{
			printf("\nWARNING - Line %d Position %d - %s -> %s",line,position,word,correctedWord);
			
			for(j = 0; j < strlen(correctedWord); j++)
			{
				content[k] = correctedWord[j];
				k++;
			}
		}
		
		else
		{
			for(j = 0; j < strlen(word); j++)
			{
				content[k] = word[j];
				k++;
			}
		}
		
		content[k] = '\0';
		
		fclose(file);
		
		printf("\n\n================================================================================\n\n");
		printf("Document after correction :");
		printf("\n\n================================================================================\n\n");
		printf("%s",content);
		printf("\n\n================================================================================\n\n");
		printf("Press enter to continue...");
		getchar();
	}
	
	else
	{
		printf("\nERROR : cannot open \"%s\" !\n",path);
		printf("\nPress enter to continue...");
		getchar();
		return;
	}
}
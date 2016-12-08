#include "functions.h"

/**

INFO -	Read the document, get each word and call "checkWord.c" to verify if the word exists in the dictionary and if it can be corrected

1 - Open document in read-only mode in order to print the content of the file before correcting it

	1.1 - Print each character of the file while we do not reach the end of the file
	1.2 - Put the cursor at the beginning of the file for next steps
	
2 -
3 -
4 -
5 -
6 -

	6.1 -
	6.2 -
	6.3 -
	6.4 -
	
		6.4.1 -
		6.4.2 -
		6.4.3 -
		
	6.5 -
	
		6.5.1 -
		6.5.2 -
		6.5.3 -
		
	6.6 -
	6.7 -
	
7 -
8 -
9 - The loop execute while it does not reach the end of the file, but by this way it get the last word of the file but do not add it in the corrected content
	So the function executes the loop actions once more to get this last word

	9.1 - Print a warning for user with the position in the text of a word that could be wrong and a proposition of resembling word found in the dictionary
	9.2 - Execute this loop for each character of the corrected word got from the dictionary
	9.3 - Put each of these characters in 'content' at the end and increment 'k' to always place the cursor at the end of 'content'
	
10 - The loop execute while it does not reach the end of the file, but by this way it get the last word of the file but do not add it in the corrected content
	 So the function executes the loop actions once more to get this last word

	10.1 - Print a warning for user with the position in the text of a word that is not found in the dictionary
	10.2 - Execute this loop for each character of the word got from the file
	10.3 - Put each of these characters in 'content' at the end and increment 'k' to always place the cursor at the end of 'content'
	
11 - End the corrected content array to avoid unexpected characters at end
12 - Print the content of the file once corrected and before writing it in file instead of original text

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
		
		/** Step 2 **/
		while((c = fgetc(file)) != EOF)
		{
			printf("%c",c);
		}

		printf("\n\n================================================================================\n\n");
		
		/** Step 3 **/
		rewind(file);
		
		/** Step 4 **/
		char content[getFileSize(file) + 100];
		
		content[0] = '\0';
		
		char word[NAME_SIZE];
		char correctedWord[NAME_SIZE];
		int i = 0, j = 0, k = 0, line = 1, position = 0;
		
		/** Step 5 **/
		while((c = fgetc(file)) != EOF)
		{
			/** Step 6 **/
			if(c == '\n' || c == 32)
			{
				/** Step 6.1 **/
				if(c == '\n')
				{
					line++;
					position = 0;
				}
				
				/** Step 6.2 **/
				if(c == 32)
				{
					position++;
				}
				
				/** Step 6.3 **/
				word[i] = '\0';
				i = 0;
				
				/** Step 6.4 **/
				if(checkWord(firstWord,word,correctedWord))
				{
					/** Step 6.4.1 **/
					printf("\nWARNING - Line %d Position %d - %s -> %s",line,position,word,correctedWord);
					
					/** Step 6.4.2 **/
					for(j = 0; j < strlen(correctedWord); j++)
					{
						/** Step 6.4.3 **/
						content[k] = correctedWord[j];
						k++;
					}
				}
				
				/** Step 6.5 **/
				else
				{
					/** Step 6.5.1 **/
					printf("\nINFO - Line %d Position %d - \"%s\" does not exist in the dictionary !",line,position,word);
					
					/** Step 6.5.2 **/
					for(j = 0; j < strlen(word); j++)
					{
						/** Step 6.5.3 **/
						content[k] = word[j];
						k++;
					}
				}
				
				/** Step 6.6 **/
				if(c == '\n')
				{
					content[k] = '\n';
					k++;
				}
				
				/** Step 6.7 **/
				if(c == 32)
				{
					content[k] = 32;
					k++;
				}
			}
			
			/** Step 7 **/
			else
			{
				word[i] = c;
				i++;
			}
		}
		
		/** Step 8 **/
		word[i] = '\0';
		
		/** Step 9 **/
		if(checkWord(firstWord,word,correctedWord))
		{
			/** Step 9.1 **/
			printf("\nWARNING - Line %d Position %d - %s -> %s",line,position,word,correctedWord);
			
			/** Step 9.2 **/
			for(j = 0; j < strlen(correctedWord); j++)
			{
				/** Step 9.3 **/
				content[k] = correctedWord[j];
				k++;
			}
		}
		
		/** Step 10 **/
		else
		{
			/** Step 10.1 **/
			printf("\nINFO - Line %d Position %d - \"%s\" does not exist in the dictionary !",line,position,word);
			
			/** Step 10.2 **/
			for(j = 0; j < strlen(word); j++)
			{
				content[k] = word[j];
				k++;
			}
		}
		
		/** Step 11 **/
		content[k] = '\0';
		
		fclose(file);
		
		/** Step 12 **/
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
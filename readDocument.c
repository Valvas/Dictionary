#include "functions.h"

/**

INFO -	Read the document, get each word and call "checkWord.c" to verify if the word exists in the dictionary and if it can be corrected

1 - Open document in read-only mode in order to print the content of the file before correcting it

	1.1 - Print each character of the file while we do not reach the end of the file
	1.2 - Put the cursor at the beginning of the file for next steps
	
2 - Print each character of the document by browsing it while function does not reach its end
3 - Put the cursor at the beginning of the document for next steps
4 - Create an array that will received the content of the document while it will be corrected (add 100 cells to be sure that it will not be too short because characters can be added compared to original content)

	EXAMPLE : 'progra' corrected to 'program' will add one character to the corrected content
	
5 - Browse the document by getting the read character in variable 'c' while the function does not reach the end
6 - If the next character is not a letter and if the previous one is the same character it will not be written in the corrected content (except if it is a number)
7 - Execute if the current character (except letters and numbers) is not the same that the previous one
8 - Execute only if the character read is a line break or a space

	8.1 - If it is a line break increment 'line' to indicate that the cursor is now on the next line of the document
	8.2 - It it is a space increment 'position' to indicate that the cursor is now on the next word in the current line
	8.3 - End the array 'word' that must contain all characters of the word between the last space and this one
		  Then the function set 'i' to zero because the next word that will be read by the function will be written in 'word' by replacing the current word written in it
	
		EXAMPLE : content -> 'Hello word', when the cursor reaches the space between 'Hello' and 'word' the array 'word' will contain 'Hello'
		
	8.4 - Call "checkWord.c" to check if the word got in the document exists in the dictionary. If it is, "checkWord.c" will write the correction of the word in 'correctedWord' and return 1
	
		8.4.1 - If 1 has been returned by "checkWord.c" it means that there is a correction for the sent word and this line of code prints a warning for user with the position of the word to 
		        correct (line and position in the line) and the corrected word
		8.4.2 - Browse each character of the corrected word in order to put it in the corrected content
		8.4.3 - Put the character got in the corrected content and increment 'k' to indicate where is the current end of the corrected content
		
	8.5 - If there are no spelling mistakes in the word and it it has been found in the dictionary, "checkWord.c" will return 0
	
		8.5.1 - Inform the user that the word has been found in the dictionary but there are no spelling mistakes
		8.5.2 - Browse each character of the word in order to put it in the corrected content
		8.5.3 - Put the character got in the corrected content and increment 'k' to indicate where is the current end of the corrected content
		
	8.6 - Execute if the word has not been found in the dictionary
	
		8.6.1 - Inform the user that the word has not been found in the dictionary
		8.6.2 - Browse each character of the word in order to put it in the corrected content
		8.6.3 - Put the character got in the corrected content and increment 'k' to indicate where is the current end of the corrected content
		
	8.7 - After all these executions the character is inserted in the corrected content
	
9 - If the character got from the document is not a line break of a space and if it is a letter (do not take special characters like commas), so it is a character of a word and is added at the end of 'word'
10 - End 'word' to avoid unexpected characters at end of the word
11 - The loop execute while it does not reach the end of the file, but by this way it get the last word of the file but do not add it in the corrected content
	So the function executes the loop actions once more to get this last word

	11.1 - Print a warning for user with the position in the text of a word that could be wrong and a proposition of resembling word found in the dictionary
	11.2 - Execute this loop for each character of the corrected word got from the dictionary
	11.3 - Put each of these characters in 'content' at the end and increment 'k' to always place the cursor at the end of 'content'
	
12 - The loop execute while it does not reach the end of the file, but by this way it get the last word of the file but do not add it in the corrected content
	 So the function executes the loop actions once more to get this last word

	12.1 - Print a warning for user with the position in the text of a word that is not found in the dictionary
	12.2 - Execute this loop for each character of the word got from the file
	12.3 - Put each of these characters in 'content' at the end and increment 'k' to always place the cursor at the end of 'content'
	
13 - End the corrected content array to avoid unexpected characters at end
14 - Print the content of the file once corrected and before writing it in file instead of original text
15 - Call "replaceContent.c" that will ask user if he wants to replace the content of the document with the corrected content and execute his will

**/

void readDocument(primary* firstWord, char* path)
{	
	char c;
	char p = '\n';
	
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
		int i = 0, j = 0, k = 0, line = 1, position = 0, result;
		
		/** Step 5 **/
		while((c = fgetc(file)) != EOF)
		{
			/** Step 6 **/
			if((c == '?' || c == '!' || c == '%' || c == '.' || c == '(' || c == ')' || c == '-' || c == '_' || c == '"' || c == '/' || c == '\\' || c == ',' || c == ';' || c == '&') && (c == p))
			{
				
			}
			
			/** Step 7 **/
			else
			{
				p = c;
				
				/** Step 8 **/
				if(c == '\n' || c == 32 || ((c < 65 || c > 91) && (c < 97 || c > 123)))
				{
					/** Step 8.1 **/
					if(c == '\n')
					{
						line++;
						position = 0;
					}
				
					/** Step 8.2 **/
					if(c == 32)
					{
						position++;
					}
			
					/** Step 8.3 **/
					word[i] = '\0';
					i = 0;
					result = -1;
				
					result = checkWord(firstWord,word,correctedWord);
				
					/** Step 8.4 **/
					if(result == 1)
					{
						/** Step 8.4.1 **/
						printf("\nWARNING - Line %d Position %d - %s -> %s",line,position,word,correctedWord);
					
						/** Step 8.4.2 **/
						for(j = 0; j < strlen(correctedWord); j++)
						{
							/** Step 8.4.3 **/
							content[k] = correctedWord[j];
							k++;
						}
					}
				
					/** Step 8.5 **/
					else if(result == 2)
					{
						/** Step 8.5.1 **/
						printf("\nINFO - Line %d Position %d - \"%s\" has been found in the dictionary !",line,position,word);
					
						/** Step 8.5.2 **/
						for(j = 0; j < strlen(word); j++)
						{
							/** Step 8.5.3 **/
							content[k] = word[j];
							k++;
						}
					}
					
					else if(result == 3)
					{
						
					}
				
					/** Step 8.6 **/
					else
					{
						/** Step 8.6.1 **/
						printf("\nINFO - Line %d Position %d - \"%s\" does not exist in the dictionary !",line,position,word);
					
						/** Step 8.6.2 **/
						for(j = 0; j < strlen(word); j++)
						{
							/** Step 8.6.3 **/
							content[k] = word[j];
							k++;
						}
					}
				
					/** Step 8.7 **/
					content[k] = c;
					k++;
				}
			
				/** Step 9 **/
				else if((c > 64 && c < 91) || (c > 96 && c < 123))
				{
					word[i] = c;
					i++;
				}
			}
		}
		
		/** Step 10 **/
		word[i] = '\0';
		
		result = checkWord(firstWord,word,correctedWord);
				
		/** Step 8.4 **/
		if(result == 1)
		{
			/** Step 8.4.1 **/
			printf("\nWARNING - Line %d Position %d - %s -> %s",line,position,word,correctedWord);
					
			/** Step 8.4.2 **/
			for(j = 0; j < strlen(correctedWord); j++)
			{
				/** Step 8.4.3 **/
				content[k] = correctedWord[j];
				k++;
			}
		}
				
		/** Step 8.5 **/
		else if(result == 2)
		{
			/** Step 8.5.1 **/
			printf("\nINFO - Line %d Position %d - \"%s\" has been found in the dictionary !",line,position,word);
					
			/** Step 8.5.2 **/
			for(j = 0; j < strlen(word); j++)
			{
				/** Step 8.5.3 **/
				content[k] = word[j];
				k++;
			}
		}
					
		else if(result == 3)
		{
						
		}
				
		/** Step 8.6 **/
		else
		{
			/** Step 8.6.1 **/
			printf("\nINFO - Line %d Position %d - \"%s\" does not exist in the dictionary !",line,position,word);
					
			/** Step 8.6.2 **/
			for(j = 0; j < strlen(word); j++)
			{
				/** Step 8.6.3 **/
				content[k] = word[j];
				k++;
			}
		}
		
		/** Step 13 **/
		content[k] = '\0';
		
		fclose(file);
		
		/** Step 14 **/
		printf("\n\n================================================================================\n\n");
		printf("Document after correction :");
		printf("\n\n================================================================================\n\n");
		printf("%s",content);
		printf("\n\n================================================================================\n\n");
		printf("Press enter to continue...");
		getchar();
		
		/** Step 15 **/
		replaceContent(path,content);
	}
	
	else
	{
		printf("\nERROR : cannot open \"%s\" !\n",path);
		printf("\nPress enter to continue...");
		getchar();
		return;
	}
}
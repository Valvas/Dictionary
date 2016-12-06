#include "functions.h"

/**

INFO -	This function create a structure 'word' with the three parameters it receives

1 - Allocate memory for the new structure 'word'
2 - Allocate memory for three elements of the structure 'word' (title, definition and origin)
3 - Copy the three parameters received with the function in the new structure 'word'
4 - All words will be added as a linked list each new one will be added at the end of this list
5 - 'firstWord' is a structure 'primary' that points on the first word in the linked list, by default it worth NULL
	Check if it is still NULL and if it is affect the new word as its target
6 - If 'firstWord' is not NULL create a temporary word that will permit to browse all the linked lits in order to reach the last element of this list
7 - Loop that will check if there is an element after the selected one and select it before reloading loop
	Loop stops when the selected element does not have another element after it
8 - By this way the next word of the selected element is NULL, so the function affets the new word to next word of the temporary element
	(that is the last element of the linked list)

**/

void createWord(primary* firstWord, char* title, char* definition, char* origin)
{
	/** Step 1 **/
	word* newWord = malloc(sizeof(word));
	
	if(newWord)
	{
		/** Step 2 **/
		newWord->title = calloc(TITLE,sizeof(char));
		newWord->definition = calloc(DEFINITION,sizeof(char));
		newWord->origin = calloc(ORIGIN,sizeof(char));
		
		/** Step 3 **/
		strcpy(newWord->title,title);
		strcpy(newWord->definition,definition);
		strcpy(newWord->origin,origin);
		
		/** Step 4 **/
		newWord->nextWord = NULL;
		
		/** Step 5 **/
		if(firstWord->wordTarget == NULL)
		{
			firstWord->wordTarget = newWord;
		}
		
		/** Step 6 **/
		else
		{
			word* tmpWord = firstWord->wordTarget;
			
			if(tmpWord != NULL)
			{
				/** Step 7 **/
				while(tmpWord->nextWord)
				{
					tmpWord = tmpWord->nextWord;
				}
				
				/** Step 8 **/
				tmpWord->nextWord = newWord;
			}
			
			else
			{
				printf("\nERROR : cannot allocate memory for new structure word !\n");
				printf("\nPress enter to exit...");
				exit(0);
			}
		}
	}
	
	else
	{
		printf("\nERROR : cannot allocate memory for new structure word !\n");
		printf("\nPress enter to exit...");
		exit(0);
	}
}
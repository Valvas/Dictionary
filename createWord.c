#include "functions.h"

/**

INFO -	This function create a structure 'word' with the three parameters it receives

1 - Allocate memory for the new structure 'word'
2 - Allocate memory for three elements of the structure 'word' (title, definition and origin)
3 - Copy the three parameters received with the function in the new structure 'word'
4 - 
5 - All words will be added as a linked list each new one will be added at the end of this list

**/

void createWord(primary* firstWord, char* title)
{	
	/** Step 1 **/
	word* newWord = malloc(sizeof(word));
	word* tmpWord = firstWord->wordTarget;
	
	if(newWord)
	{
		/** Step 2 **/
		newWord->title = calloc(TITLE,sizeof(char));
		
		/** Step 3 **/
		strcpy(newWord->title,title);
		
		/** Step 4 **/
		firstWord->wordTarget = newWord;
		
		/** Step 5 **/
		newWord->nextWord = tmpWord;
	}
	
	else
	{
		printf("\nERROR : cannot allocate memory for new structure word !\n");
		printf("\nPress enter to exit...");
		exit(0);
	}
}
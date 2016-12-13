#include "functions.h"

/**

INFO -  Variable 'size' corresponds to the number of characters the function 'integer' will read
        Example : if 'size' worth 3, 'choice' will not have more than three characters

        For a better understanding read the explanations of functions 'integer' and 'entry'

**/

void menu(head* listHead, primary* firstWord)
{
    short run = 1, size = 3;
    long choice = 0;
	char sourcePath[NAME_SIZE];

    while(run)
    {
        while(choice < 1 || choice > 5)
        {
            CLEAR

            printf("\n");
            printf("+=============================+\n");
            printf("|          Main Menu          |\n");
            printf("+=============================+\n");

            printf("\n1. Search word");
            printf("\n2. Add new word");
            printf("\n3. Manage sources");
			printf("\n4. Correct document");
            printf("\n5. Exit");

            printf("\n\nEnter a value (1 to 5) : ");

            choice = integer(size);

            switch(choice)
            {			
                case SEARCH_WORD : searchWord(firstWord->wordTarget); choice = 0; break;
				
                case ADD_WORD : 
				
					/** Get the name of the source in which the user wants to add words **/
					selectSource(listHead,sourcePath);
					
					/** Call "addWord.c" with the result of "selectSource.c" just above **/
					addWord(firstWord,sourcePath);
					
					choice = 0;
					break;
				
                case MANAGE_SOURCES : manageSources(listHead,firstWord); choice = 0; break;
				case CORRECT_DOCUMENT : correctDocument(firstWord); choice = 0; break;
                case EXIT : run = 0; break;
            }
        }
    }
}

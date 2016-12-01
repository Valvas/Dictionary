#include "functions.h"

/**

INFO -  Variable 'size' corresponds to the number of characters the function 'integer' will read
        Example : if 'size' worth 3, 'choice' will not have more than three characters

        For a better understanding read the explanations of functions 'integer' and 'entry'

**/

void menu(source* firstSource)
{
    short run = 1, size = 3;
    long choice = 0;

    while(run)
    {
        while(choice < 1 || choice > 5)
        {
            CLEAR

            printf("\n");
            printf("+=============================+\n");
            printf("|          Main Menu          |\n");
            printf("+=============================+\n");

            printf("\n1. List of words");
            printf("\n2. Search word");
            printf("\n3. Add new word");
            printf("\n4. Manage sources");
            printf("\n5. Exit");

            printf("\n\nEnter a value (1 to 5) : ");

            choice = integer(size);

            switch(choice)
            {
                case WORD_LIST : printf("\nList of words"); choice = 0; break;
                case SEARCH_WORD : printf("\nSearch word"); choice = 0; break;
                case ADD_WORD : printf("\nAdd new word"); choice = 0; break;
                case MANAGE_SOURCES : manageSources(firstSource); choice = 0; break;
                case EXIT : run = 0; break;
            }
        }
    }
}

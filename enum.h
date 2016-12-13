#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef enum_list
#define enum_list

/**

INFO -	The first enum is used in the main menu ("menu.c")
		The second enum is used in sources management menu ("manageSources.c")

**/

enum
{
   SEARCH_WORD = 1, ADD_WORD, MANAGE_SOURCES, CORRECT_DOCUMENT, EXIT
};

enum
{
    ADD_SOURCE = 1, CREATE_SOURCE, REMOVE_SOURCE, SHOW_SOURCES, BACK_MENU
};

#endif

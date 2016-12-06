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
    WORD_LIST = 1, SEARCH_WORD, ADD_WORD, MANAGE_SOURCES, EXIT
};

enum
{
    ADD_SOURCE = 1, CREATE_SOURCE, REMOVE_SOURCE, SHOW_SOURCES, BACK_MENU
};

#endif

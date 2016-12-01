#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef enum_list
#define enum_list

enum
{
    WORD_LIST = 1, SEARCH_WORD, ADD_WORD, MANAGE_SOURCES, EXIT
};

enum
{
    ADD_SOURCE = 1, REMOVE_SOURCE, SHOW_SOURCES, BACK_MENU
};

#endif

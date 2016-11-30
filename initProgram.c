#include "functions.h"

/**

INFO -  This function checks if sources list file exists, if not it will be created at LIST_FILE path
        LIST_FILE is a constant found in "functions.h"
        This function returns 1 if file can be created and open and 0 if not

**/

int initProgram()
{
    FILE* file = NULL;

    file = fopen(LIST_FILE,"a");

    if(file != NULL)
    {
        fclose(file);
        return 1;
    }

    else
    {
        return 0;
    }
}

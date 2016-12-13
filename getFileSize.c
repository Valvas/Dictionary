#include "functions.h"

/**

INFO -  This function return the number of characters in a file (counts break lines and blanks too)

**/

long long getFileSize(FILE* file)
{
    int c = 0;
	long long size = 0;

    while((c = fgetc(file)) != EOF)
    {
        size++;
    }

    rewind(file);

    return size;
}

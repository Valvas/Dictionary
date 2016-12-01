#include "functions.h"

/**

INFO -  This function is called by 'entry' to clean buffer after an user's entry
        Example :

            - If user's entry is "Hello world!" and maximum size of the entry is 8 (this number counts \0)
            - Entry retrieved by function 'entry' will be "Hello w" (7 characters plus \0)
            - But it will remain "orld!" in buffer
            - So at next user's entry the function 'entry' will automatically retrieve this value and do not ask for user's entry
            - In order to avoid this to happen, buffer will be cleaned

        While end of remaining characters is not reached the function gets the next character

**/

void cleanBuffer()
{
    int c = 0;

    while(c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

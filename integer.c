#include "functions.h"

/**

INFO -  This function replaces 'scanf' and must be called only to get integers, in order to get strings call directly function 'entry' (go see explanations of this function after)
        This function calls 'entry' itself and permits to convert user's entry in integer
        This function receives one parameter :

            - int size : this is the number of characters that will be retrieved for user's entry (\0 counts in this number)
              Example : 'size' worths 4 and user's entry is "123456789", after calling of function 'entry' it will be "123" (do not forget \0 that counts for one character in 'size')

1 - Create a string with size given by the parameter 'size'
2 - Get user's entry by using 'entry'
3 - Convert the entry in an integer by using 'strtol'
4 - Return the result to the calling function (example : if user's entry is "123456789" and 'size' worths 3 it will be "12" then 12)

**/

long integer(int size)
{
    /** Step 1 **/
    char str[size];

    /** Step 2 **/
    if(entry(str,size))
    {
        /** Step 3 and 4 **/
        return strtol(str,NULL,10);
    }

    else
    {
        return 0;
    }
}

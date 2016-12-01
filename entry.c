#include "functions.h"

/**

INFO -  This function is used instead of 'scanf' because this one is not secure
        This function only permits to get strings, in order to get integers this function must be called by function 'integer' (go see explanations of this function after)
        This function receives two parameters :

            - char* str : this is the string that will contain user's entry
            - int size  : this is the size of the string just above

        This function returns 1 if entry worked

1 - Get user's entry in string sent in first parameter
2 - Consider end of entry when user uses line break and then apply end of string at this point :

    - By this way we avoid an entry with a line break in the middle or an empty entry but not considered as empty if user only entered a line break

3 - Call function 'clean_buffer' if there is not line break in the string delimited by the size from second parameter of the function :

    - If 'size' worths 3 for example, so fgets will only get the three first characters entered by user : "Hello\n\0" --> "Hel\0"
    - In example above fgets has "Hel\0" but remains "lo\n\0" in buffer, user's next entry will automatically get this value.
    - In order to avoid this we need to clean the buffer by calling function 'clean_buffer' (go see the explanations of this function after)

4 - In order to avoid bugs call of function 'clean_buffer' if fgets did not work

**/

int entry(char* str, int size)
{
    char* endOfLine = NULL;

    /** Step 1 **/
    if(fgets(str,size,stdin) != NULL)
    {
        /** Step 2 **/
        endOfLine = strchr(str,'\n');

        if(endOfLine != NULL)
        {
            *endOfLine = '\0';
        }

        /** Step 3 **/
        else
        {
            cleanBuffer();
        }

        return 1;
    }

    /** Step 4 **/
    else
    {
        cleanBuffer();

        return 0;
    }
}
